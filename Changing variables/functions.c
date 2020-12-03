#include <math.h>
#include <stdlib.h>

#include "functions.h"

double randomdouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

double gen2(double lambda, double mu){
	double x = randomdouble(0., 1.);
	return -(1 / (lambda + mu)) * log(1 - x);
}

double Vg(double t, double t0, double sigma0, double f0){
	double omega0 = 2 * M_PI * f0;
	return cos(omega0 * t) * exp(-(t-t0)*(t-t0)/(2*sigma0*sigma0));  
}

double f_wb2(double x, double * xj, double t, double * cj, double * lambdaj, double * muj, double * R0, int j, double gamma_in, double gamma_out, double ksi, double t0, double sigma0, double f0) {
	double S, alpha, beta;
	
	if (t < 0) return 0;
	if (t > 0) {
		S = gen2(lambdaj[j], muj[j]);
		if((x - cj[j]*S) > xj[j-1]){
			return (lambdaj[j] / (lambdaj[j]+muj[j])) * b_wb2(x - cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		}
		else if(j > 1){
			S = (x - xj[j-1]) / cj[j];
			alpha = (2/R0[j-1]) * (1 / ((1/(R0[j-1])) + (1/(R0[j]))));
			beta = -((1/(R0[j-1])) - (1/(R0[j]))) * (1 / ((1/(R0[j-1])) + (1/(R0[j]))));
			return beta * b_wb2(x-cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0) + alpha * f_wb2(x-cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j-1, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		}
		else if (j == 1) {
			S = (x - xj[j-1]) / cj[j];
			return gamma_in * b_wb2(x-cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0) + ksi * Vg(t-S, t0, sigma0, f0);
		}
	}
}

double b_wb2(double x, double * xj, double t, double * cj, double * lambdaj, double * muj, double * R0, int j, double gamma_in, double gamma_out, double ksi, double t0, double sigma0, double f0) {
	double S, alpha, beta;
	int jmax;
	jmax = 3;
	
	if (t < 0) return 0;
	if (t > 0) {
		S = gen2(lambdaj[j], muj[j]);
		if((x + cj[j]*S) < xj[j]){
			return (lambdaj[j] / (lambdaj[j]+muj[j])) * f_wb2(x+cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		}
		else if(j < jmax){
			S = (xj[j] - x) / cj[j];
			alpha = (2/R0[j+1]) * (1 / ((1/(R0[j])) + (1/(R0[j+1]))));
			beta = ((1/(R0[j])) - (1/(R0[j+1]))) * (1 / ((1/(R0[j])) + (1/(R0[j+1]))));
			return beta * f_wb2(x+cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0) + alpha * b_wb2(x+cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j+1, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		}
		else if (j == jmax) {
			S = (xj[j] - x) / cj[j];
			return gamma_out * f_wb2(x+cj[j]*S, xj, t-S, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		}
	}
}

double mc(int N, double x, double * xj, double t, double * cj, double * lambdaj, double * muj, double * R0, int j, double gamma_in, double gamma_out, double ksi, double t0, double sigma0, double f0){
	double xx, tt, suma_f = 0, suma_b = 0;
	int i;
	for (i = 1; i <= N; i++){
		xx = x;
		tt = t;
		suma_f = suma_f + f_wb2(xx, xj, tt, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0);
		xx = x;
		tt = t;
		suma_b = suma_b + b_wb2(xx, xj, tt, cj, lambdaj, muj, R0, j, gamma_in, gamma_out, ksi, t0, sigma0, f0) + ksi * Vg(t, t0, sigma0, f0);
	}
	suma_b = suma_b/N;
	suma_f = suma_f/N;
	
	return suma_b + suma_f;
}

