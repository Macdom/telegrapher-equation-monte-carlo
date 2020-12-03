#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "functions.h"

double D(double lambda, double mu, double t){
	double alpha = lambda + mu;
	return alpha / (1 - exp(-alpha * t));
}

double g(double lambda, double mu, double t){
	double alpha = lambda + mu;
	double d = D(lambda, mu, t);
	return d * exp(-alpha * t);
}

double randomdouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

double gen1(double lambda, double mu, double T){
	double x = randomdouble(0, 1);
	double alpha = lambda + mu;
	double M = (exp(alpha * T) - 1) * (exp(-alpha * T) - 1);
	return (-1 / alpha) * (log((M * x - 1 + exp(alpha * T)) / (exp(alpha * T) - 1)));
}

double gen2(double lambda, double mu){
	double x = randomdouble(0, 1);
	return -(1 / (lambda + mu)) * log(1 - x);
}


double s(double x, double t, double c) {
	return sqrt(c*c * t*t - x*x);
}

double fAnalytical(double x, double t, double lambda, double c){
	double ss = 0.0, arg = 0.0, result;
	ss = s(x, t, c);
	arg = lambda * ss / c;
	result = lambda * exp(-lambda*t) / (2 * c * ss) * (bessi0(arg) * ss + bessi1(arg) * (x + c*t));
	
	if ((c * t) <= fabs(x)) result = 0;
	return result;
}

double bAnalytical(double x, double t, double lambda, double c){
	double ss = 0.0, arg = 0.0, result;
	ss = s(x, t, c);
	arg = lambda * ss / c;
	result = lambda * exp(-lambda*t) / (2 * c * ss) * (bessi0(arg) * ss + bessi1(arg) * (c*t - x));
	
	if ((c * t) <= fabs(x)) result = 0;
	return result;
}

double F(double tn, int i, double * f, double * b, double c, double lambda, double mu, double dx){
	return -c * ((f[i+1] - f[i-1])/(2*dx)) + lambda * b[i] - (lambda+mu) * f[i];
}
double B(double tn, int i, double * f, double * b, double c, double lambda, double mu, double dx){
	return c * ((b[i+1] - b[i-1])/(2*dx)) + lambda * f[i] - (lambda+mu) * b[i];
}

void rk4(double * f, double * b, double tn, double dt, double c, double lambda, double mu, double dx){
	int i;
	double k1f[SIZE], k1b[SIZE], k2f[SIZE], k2b[SIZE], k3f[SIZE], k3b[SIZE], k4f[SIZE], k4b[SIZE];  
	double tempf2[SIZE], tempb2[SIZE], tempf3[SIZE], tempb3[SIZE], tempf4[SIZE], tempb4[SIZE];
	
	for (i = 1; i < SIZE-1; i++){
		k1f[i] = F(tn, i, f, b, c, lambda, mu, dx);
		k1b[i] = B(tn, i, f, b, c, lambda, mu, dx);
		tempf2[i] = f[i] + (dt/2) * k1f[i];
		tempb2[i] = b[i] + (dt/2) * k1b[i];
	}
	
	for (i = 1; i < SIZE-1; i++){	
		k2f[i] = F(tn + dt/2, i, tempf2, tempb2, c, lambda, mu, dx);
		k2b[i] = B(tn + dt/2, i, tempf2, tempb2, c, lambda, mu, dx);
		tempf3[i] = f[i] + (dt/2) * k2f[i];
		tempb3[i] = b[i] + (dt/2) * k2b[i];
	}
		
	for (i = 1; i < SIZE-1; i++){	
		k3f[i] = F(tn + dt/2, i, tempf3, tempb3, c, lambda, mu, dx);
		k3b[i] = B(tn + dt/2, i, tempf3, tempb3, c, lambda, mu, dx);
		tempf4[i] = f[i] + dt * k3f[i];
		tempb4[i] = b[i] + dt * k3b[i];
	}
	
	for (i = 1; i < SIZE-1; i++){	
		k4f[i] = F(tn + dt, i, tempf4, tempb4, c, lambda, mu, dx);
		k4b[i] = B(tn + dt, i, tempf4, tempb4, c, lambda, mu, dx);
	}
	
	for (i = 1; i < SIZE-1; i++){
		f[i] += (dt/6) * (k1f[i] + 2*k2f[i] + 2*k3f[i] + k4f[i]);
		b[i] += (dt/6) * (k1b[i] + 2*k2b[i] + 2*k3b[i] + k4b[i]);
	}
}

double f0(double x, double sigma, double x0){
	return  (1 / (sigma * sqrt(2 * M_PI))) * (exp(-(pow(x - x0, 2) / (2 * sigma * sigma))));
}

double b0(double x, double sigma, double x0){
	return  (1 / (sigma * sqrt(2 * M_PI))) * (exp(-(pow(x - x0, 2) / (2 * sigma * sigma))));
}

double mc1(int N, double tmax, double xi, double c, double lambda, double mu, double sigma, double x0){
	double suma_f, t, S, x;
	int i, MAX, k, p;
	
	double alpha, D2;
	alpha = mu + lambda;
	D2 = alpha / (1 - exp(-alpha * tmax));
	
	suma_f = 0.0;
	for (i = 1; i <= N; i++){
		t = tmax, k = 0;
		x = xi;
		while (t > 0){
			p = k % 2;
			if (p == 0) suma_f += (pow((lambda / D2), k) * f0(x - c*t, sigma, x0) * exp(-alpha * t));
			else suma_f += (pow((lambda / D2), k) * b0(x + c*t, sigma, x0) * exp(-alpha * t));
			S = gen1(lambda, mu, tmax);
			t = t - S;
			x = x + pow(-1, p+1) * c * S;
			k++;
		}
	}
	return suma_f / N;
}

double mc2(int N, double tmax, double xi, double c, double lambda, double mu, double sigma, double x0){
	double suma_b, t, S, x;
	int i, MAX, k, p;
	
	double alpha, D2;
	alpha = mu + lambda;
	D2 = alpha / (1 - exp(-alpha * tmax));
	
	suma_b = 0.0;
	for (i = 1; i <= N; i++){
		t = tmax, k = 0;
		x = xi;
		while (t > 0){
			p = k%2;
			if (p == 0) suma_b += (pow((lambda / D2), k) * b0(x + c*t, sigma, x0) * exp(-alpha * t));
			else suma_b += (pow((lambda / D2), k) * f0(x - c*t, sigma, x0) * exp(-alpha * t));
			S = gen1(lambda, mu, tmax);
			t = t - S;
			x = x + pow(-1, p) * c * S;
			k++;
		}
	}
	return suma_b / N;
}

double fRecursive(double x, double t, double c, double lambda, double mu, double sigma, double x0){
	double S;
	if (t < 0) return 0;
	if (t > 0){
		S = gen2(lambda, mu);
		double D2 = lambda + mu;
		
		if (S > t) return f0(x - c*t, sigma, x0);
		if (S < t) return (lambda / D2) * bRecursive(x - c*S, t-S, c, lambda, mu, sigma, x0);
	}
}

double bRecursive(double x, double t, double c, double lambda, double mu, double sigma, double x0){
	double S;
	if (t < 0) return 0;
	if (t > 0){
		S = gen2(lambda, mu);
		double D2 = lambda + mu;
		
		if (S > t) return b0(x + c*t, sigma, x0);
		if (S < t) return (lambda / D2) * fRecursive(x + c*S, t-S, c, lambda, mu, sigma, x0);
	}
}
void mc3(double x, double t, int N, double c, double lambda, double mu, double sigma, double x0, double *sumaB, double *sumaF){
	double xx, tt, suma_f = 0, suma_b = 0;
	int i;
	for (i = 1; i <= N; i++){
		xx = x;
		tt = t;
		suma_f = suma_f + fRecursive(xx, tt, c, lambda, mu, sigma, x0);
		xx = x;
		tt = t;
		suma_b = suma_b + bRecursive(xx, tt, c, lambda, mu, sigma, x0);
	}
	*sumaB = suma_b/N;
	*sumaF = suma_f/N;
}