#include <math.h>
#include <complex.h>
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
	return cos(omega0 * t) * exp((-1) * (((t-t0)*(t-t0)) / (2*sigma0*sigma0))); 
}

double f_wb(double x, double t, double c, double lambda, double mu, double gamma_in, double gamma_out, double ksi, double xmax, double t0, double sigma0, double f0) {
	double S;
	if (t < 0) return 0;
	if (t > 0) {
		S = gen2(lambda, mu);
		if((x - c*S) > 0){
			return (lambda / (lambda+mu)) * b_wb(x - c*S, t-S, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0);
		}
		else{
			S = x / c;
			return gamma_in * b_wb(x - c*S, t-S, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0) + ksi * Vg(t - S, t0, sigma0, f0);
		}
	}
}

double b_wb(double x, double t, double c, double lambda, double mu, double gamma_in, double gamma_out, double ksi, double xmax, double t0, double sigma0, double f0) {
	double S;
	if (t < 0) return 0;
	if (t > 0) {
		S = gen2(lambda, mu);
		if((x + c*S) < xmax){
			return (lambda / (lambda+mu)) * f_wb(x + c*S, t-S, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0);
		}
		else{
			S = (xmax - x) / c;
			return gamma_out * f_wb(x + c*S, t-S, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0);
		}
	}
}

void mc(double x, double t, int N, double c, double lambda, double mu, double sigma, double x0, double gamma_in, double gamma_out, double ksi, double xmax, double t0, double sigma0, double f0, double *sumaB, double *sumaF){
	double xx, tt, suma_f = 0, suma_b = 0;
	int i;
	for (i = 1; i <= N; i++){
		xx = x;
		tt = t;
		suma_f = suma_f + f_wb(xx, tt, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0);
		xx = x;
		tt = t;
		suma_b = suma_b + b_wb(xx, tt, c, lambda, mu, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0);
	}
	*sumaB = suma_b/N;
	*sumaF = suma_f/N;
}

