#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "functions.h"

int main(int argc, char ** argv){
	if (argc != 2){
		printf("Usage: make plots/maps/compare\n");
		exit(0);
	}
	else{
		double x, t0, sigma, L, C, R, G, Rin, Rout, f0;
		double c2[4], c16[4], mu[4], lambda2[4], lambda16[4], R02[4], R016[4];
		double c025[4], lambda025[4], R0025[4];
		double ksi2, ksi16, gammain2, gammain16, gammaout2, gammaout16;
		double ksi025, gammain025, gammaout025;
		int i, j, nx, N3, N4, N5;
		double dx;
			
		t0 = 7.5E-9; sigma = 0.75E-9;
		L = 0.25E-6; C = 100E-12; R = 12.5;
		G = 0.5E-3; Rin = 5; Rout = 10; f0 = 0.0;
			
		double xtab[4] = {0.0, 4.0, 6.0, 10.0};
		double Ctab[4] = {0, C, C, C};
		double Ltab2[4] = {0, L, L*2, L};
		double Ltab16[4] = {0, L, L*16, L};
		double Ltab025[4] = {0, L, L*0.25, L};
		double Gtab[4] = {0, G, G, G};
		double Rtab[4] = {0, R, R, R};
			
		double tmax[6] = {10., 20., 30., 40., 50., 60.};
		for (i = 0; i < 6; i++) tmax[i] *= 1.0E-9;
			
		N3 = 1.0E+3; N4 = 1.0E+4; N5 = 1.0E+5; 
		
		nx = 203;
		dx = xtab[3] / nx;
			
		for (j = 1; j < 4; j++){
			c2[j] = 1 / (sqrt(Ltab2[j] * Ctab[j]));
			c16[j] = 1 / (sqrt(Ltab16[j] * Ctab[j]));
			c025[j] = 1 / (sqrt(Ltab025[j] * Ctab[j]));
			lambda2[j] = ((Rtab[j] / Ltab2[j]) - (Gtab[j] / Ctab[j])) / 2;
			lambda16[j] = ((Rtab[j] / Ltab16[j]) - (Gtab[j] / Ctab[j])) / 2;
			lambda025[j] = ((Rtab[j] / Ltab025[j]) - (Gtab[j] / Ctab[j])) / 2;
			mu[j] = Gtab[j] / Ctab[j];
			R02[j] = sqrt(Ltab2[j] / Ctab[j]);
			R016[j] = sqrt(Ltab16[j] / Ctab[j]);
			R0025[j] = sqrt(Ltab025[j] / Ctab[j]);
		}
			
		ksi2 = R02[1] / (R02[1] + Rin);
		ksi16 = R016[1] / (R016[1] + Rin);
		ksi025 = R0025[1] / (R0025[1] + Rin);
		gammain2 = (Rin - R02[1]) / (Rin + R02[1]);
		gammain16 = (Rin - R016[1]) / (Rin + R016[1]);
		gammain025 = (Rin - R0025[1]) / (Rin + R0025[1]);
			
		gammaout2 = (Rout - R02[3]) / (Rout + R02[3]);
		gammaout16 = (Rout - R016[3]) / (Rout + R016[3]);
		gammaout025 = (Rout - R0025[3]) / (Rout + R0025[3]);
		
		if(strcmp(argv[1], "plots") == 0){
			double u3_2, u4_2, u5_2, u3_16, u4_16, u5_16;
			
			FILE * out0;
			FILE * out13;
			out0 = fopen("out0.txt", "w");
			out13 = fopen("out13.txt", "w");
			srand(time(NULL));
			
			for (j = 1; j < 4; j++){
				for(x = xtab[j-1]; x <= xtab[j]; x += dx){
					printf("%g\n", x);
					fprintf(out0, "%.5g ", x);
					for (i = 0; i < 6; i++){
						u3_2 = mc(N3, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u3_16 = mc(N3, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						u4_2 = mc(N4, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u4_16 = mc(N4, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						u5_2 = mc(N5, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u5_16 = mc(N5, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						
						fprintf(out0, "%.5g %.5g %.5g %.5g %.5g %.5g ", u3_2, u3_16, u4_2, u4_16, u5_2, u5_16);
					}
					fprintf(out0, "\n");
				}
			}
			fclose(out0);

			f0 = 1.3E+9;
			for (j = 1; j < 4; j++){
				for(x = xtab[j-1]; x <= xtab[j]; x += dx){
					printf("%g\n", x);
					fprintf(out13, "%.5g ", x);
					for (i = 0; i < 6; i++){
						u3_2 = mc(N3, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u3_16 = mc(N3, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						u4_2 = mc(N4, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u4_16 = mc(N4, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						u5_2 = mc(N5, x, xtab, tmax[i], c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);
						u5_16 = mc(N5, x, xtab, tmax[i], c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0);
						
						fprintf(out13, "%.5g %.5g %.5g %.5g %.5g %.5g ", u3_2, u3_16, u4_2, u4_16, u5_2, u5_16);
					}
					fprintf(out13, "\n");
				}
			}
			fclose(out13);	
		}
		
		if(strcmp(argv[1], "maps") == 0){
			double t, f0_0, f0_3, f0_9;
			double u2_0, u16_0, u025_0, u2_3, u16_3, u025_3, u2_9, u16_9, u025_9; 
			nx = 400;
			dx = xtab[3] / nx;			
			f0_0 = 0;
			f0_3 = 3.0E+9;
			f0_9 = 9.0E+9;
			
			FILE * out_maps;
			out_maps = fopen("out_maps_new.txt", "w");
			
			for(t = 10E-9; t <= 100E-9; t += 0.5E-9){
				printf("%g\n", t);	
				for (j = 1; j < 4; j++){
					for(x = xtab[j-1]; x <= xtab[j]; x += dx){
						//printf("%g %g\n", t, x);
						u2_0 = mc(N5, x, xtab, t, c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0_0);						
						u16_0 = mc(N5, x, xtab, t, c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0_0);						
						u025_0 = mc(N5, x, xtab, t, c025, lambda025, mu, R0025, j, gammain025, gammaout025, ksi025, t0, sigma, f0_0);
						
						u2_3 = mc(N5, x, xtab, t, c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0_3);						
						u16_3 = mc(N5, x, xtab, t, c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0_3);						
						u025_3 = mc(N5, x, xtab, t, c025, lambda025, mu, R0025, j, gammain025, gammaout025, ksi025, t0, sigma, f0_3);	
						
						u2_9 = mc(N5, x, xtab, t, c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0_9);						
						u16_9 = mc(N5, x, xtab, t, c16, lambda16, mu, R016, j, gammain16, gammaout16, ksi16, t0, sigma, f0_9);						
						u025_9 = mc(N5, x, xtab, t, c025, lambda025, mu, R0025, j, gammain025, gammaout025, ksi025, t0, sigma, f0_9);
						
						fprintf(out_maps, "%g %g %g %g %g %g %g %g %g %g %g\n", t, x, u2_0, u16_0, u025_0, u2_3, u16_3, u025_3, u2_9, u16_9, u025_9);
					}
				}
				fprintf(out_maps, "\n");
			}
			fclose(out_maps);
		}
		

		if(strcmp(argv[1], "compare") == 0){
			double t, f0, u, cpu_time_used;
			nx = 400;
			dx = xtab[3] / nx;			
			f0 = 0;
			
			clock_t start, end;			
			
			FILE * out_compare;
			out_compare = fopen("out_compare.txt", "w");
			
			x = 5;
			j = 2;
			
			for(t = 10E-9; t <= 100E-9; t += 0.5E-9){
				printf("%g\n", t);
				start = clock();
				u = mc(N5, x, xtab, t, c2, lambda2, mu, R02, j, gammain2, gammaout2, ksi2, t0, sigma, f0);												
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;				
				fprintf(out_compare, "%g %g\n", t, cpu_time_used);
			}
			fclose(out_compare);
		}

	}
}