#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <complex.h>
#include "functions.h"

void calculateForGivenF0(double f0, char * fileName, FILE * table, double nomega){
	printf("Calculating for f0 = %g\n", f0);
	printf("----------------------------------------\n", f0);
	FILE * out;
	out = fopen(fileName, "w");
	srand(time(NULL));
	
	double t, x, xmax, c, lambda, mu, x0, dx, sigma;
	double t0, sigma0, L, C, R, G, Rout, Rin, R0, gamma_in, gamma_out, ksi;
	double u_an_Re, u3, u4, u5, sumaB3, sumaF3, sumaB4, sumaF4, sumaB5, sumaF5;
	double maxdif3, maxdif4, maxdif5;
	double dif3, dif4, dif5;
	int N3, N4, N5, i;
	double complex u_an;
	
	x0 = 0.0; xmax = 2; 
	dx = 2*xmax / SIZE;
	sigma = 20*dx;

	t0 = 7.5 * 1.0E-9; sigma0 = 0.75 * 1.0E-9;
	L = 0.25 * 1.0E-6;
	C = 100 * 1.0E-12; 
	G = 0.5 * 1.0E-3;
	R = 12.5;
	Rout = 12.5; 
	Rin = 75;
	
	c = 1 / sqrt(L*C);
	lambda = (R/L - G/C)/2;
	mu = G / C;
	
	N3 = 10E+3; N4 = 10E+4; N5 = 10E+5;
	
	double tmax[7] = {7.5, 10, 15, 20, 25, 30, 35};
	for (i = 0; i < 7; i++) tmax[i] *= 1.0E-9;

	maxdif3 = maxdif4 = maxdif5 = 0;

	R0 = sqrt(L/C);
	gamma_in = (Rin - R0) / (Rin + R0);
	gamma_out = (Rout - R0) / (Rout + R0);
	ksi = R0 / (R0 + Rin);
	
	for(x = 0; x <= xmax; x += dx){
		printf("%g\n", x);
		fprintf(out, "%.5g ", x);
		for (i = 0; i < 7; i++){
			u_an = analytical(f0, sigma0, R, L, G, C, Rin, Rout, t0, tmax[i], xmax, x, nomega);
			u_an_Re = creal(u_an);
			
			mc(x, tmax[i], N3, c, lambda, mu, sigma, x0, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0, &sumaB3, &sumaF3);
			mc(x, tmax[i], N4, c, lambda, mu, sigma, x0, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0, &sumaB4, &sumaF4);
			mc(x, tmax[i], N5, c, lambda, mu, sigma, x0, gamma_in, gamma_out, ksi, xmax, t0, sigma0, f0, &sumaB5, &sumaF5);
			
			u3 = sumaB3 + sumaF3;
			u4 = sumaB4 + sumaF4;
			u5 = sumaB5 + sumaF5;
			
			dif3 = u_an_Re - u3;
			dif4 = u_an_Re - u4;
			dif5 = u_an_Re - u5;
			
			if(fabs(dif3) > maxdif3) maxdif3 = fabs(dif3);
			if(fabs(dif4) > maxdif4) maxdif4 = fabs(dif4);
			if(fabs(dif5) > maxdif5) maxdif5 = fabs(dif5);
			
			fprintf(out, "%.5g %.5g %.5g %.5g %.5g %.5g %.5g ", u_an_Re, u3, dif3, u4, dif4, u5, dif5);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	for (i = 0; i < 7; i++){
		fprintf(table, "%.5g %.5g %.5g %.5g\n", f0, tmax[i], N3, maxdif3);
		fprintf(table, "%.5g %.5g %.5g %.5g\n", f0, tmax[i], N4, maxdif4);
		fprintf(table, "%.5g %.5g %.5g %.5g\n", f0, tmax[i], N5, maxdif5);
	}
	printf("----------------------------------------\n\n");
}

int main(){
	FILE * table;
	table = fopen("out_table2.txt", "w");
	fprintf(table, "f0 tmax N ||UA - Unum||inf\n");
	
	double f0_0, f0_1, f0_3, f0_9, f0_27;
	double nomega, nomega27;
	
	f0_0 = 0.0; f0_1 = 1.0E+9;
	f0_3 = 3.0E+9; f0_9 = 9.0E+9;
	f0_27 = 27.0E+9;
	nomega = 1000; nomega27 = 2500;
	
	calculateForGivenF0(f0_0, "out0.txt", table, nomega);
	calculateForGivenF0(f0_1, "out1.txt", table, nomega);
	calculateForGivenF0(f0_3, "out3.txt", table, nomega);
	calculateForGivenF0(f0_9, "out9.txt", table, nomega);
	calculateForGivenF0(f0_27, "out27.txt", table, nomega27);
	
	fclose(table);
}