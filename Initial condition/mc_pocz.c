#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "functions.h"

int main(int argc, char ** argv){
	if (argc != 2){
		printf("Usage: make alg12/alg3/rk4\n");
		exit(0);
	}
	else{
		if(strcmp(argv[1], "alg12") == 0){
			FILE * out;
			FILE * odch;
			out = fopen("out12.txt", "w");
			odch = fopen("odch12.txt", "w");
			srand(time(NULL));
			
			double t, x, xmin, xmax, c, lambda, tmax, mu, x0, dx;
			double fAn, bAn;
			double sigma10, sigma20, sigma40;
			double sumaB10_3, sumaF10_3, sumaB20_3, sumaF20_3, sumaF40_3, sumaB40_3;
			double sumaB10_4, sumaF10_4, sumaB20_4, sumaF20_4, sumaF40_4, sumaB40_4;
			double sumaB10_5, sumaF10_5, sumaB20_5, sumaF20_5, sumaF40_5, sumaB40_5;
			double odchB10_3, odchF10_3, odchB20_3, odchF20_3, odchF40_3, odchB40_3;
			double odchB10_4, odchF10_4, odchB20_4, odchF20_4, odchF40_4, odchB40_4;
			double odchB10_5, odchF10_5, odchB20_5, odchF20_5, odchF40_5, odchB40_5;
			int N1, N2, N3;
		// 1
			xmin = -5; xmax = 5; c = 2.0E+8; lambda = 22.5E+6; tmax = 20E-9;
			mu = 0.0; x0 = 0.0;
			dx = 2*xmax / SIZE;
			sigma10 = 10*dx, sigma20 = 20*dx, sigma40 = 40*dx;
			odchB10_3 = odchB10_4 = odchB10_5 = odchB20_3 = odchB20_4 = odchB20_5 = odchB40_3 = odchB40_4 = odchB40_5 = 0;
			odchF10_3 = odchF10_4 = odchF10_5 = odchF20_3 = odchF20_4 = odchF20_5 = odchF40_3 = odchF40_4 = odchF40_5 = 0;
			
			N1 = 1E+3; N2 = 1E+4; N3 = 1E+5; 
			t = tmax;

		// 3	
			for(x = xmin; x <= xmax; x += dx){
				printf("%g\n", x);
				
				sumaF10_3 = mc1(N1, tmax, x, c, lambda, mu, sigma10, x0);
				sumaF10_4 = mc1(N2, tmax, x, c, lambda, mu, sigma10, x0);
				sumaF10_5 = mc1(N3, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB10_3 = mc2(N1, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB10_4 = mc2(N2, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB10_5 = mc2(N3, tmax, x, c, lambda, mu, sigma10, x0);
				sumaF20_3 = mc1(N1, tmax, x, c, lambda, mu, sigma20, x0);
				sumaF20_4 = mc1(N2, tmax, x, c, lambda, mu, sigma20, x0);
				sumaF20_5 = mc1(N3, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB20_3 = mc2(N1, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB20_4 = mc2(N2, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB20_5 = mc2(N3, tmax, x, c, lambda, mu, sigma20, x0);
				sumaF40_3 = mc1(N1, tmax, x, c, lambda, mu, sigma40, x0);
				sumaF40_4 = mc1(N2, tmax, x, c, lambda, mu, sigma40, x0);
				sumaF40_5 = mc1(N3, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB40_3 = mc2(N1, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB40_4 = mc2(N2, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB40_5 = mc2(N3, tmax, x, c, lambda, mu, sigma40, x0);
				fAn = fAnalytical(x, t, lambda, c);
				bAn = bAnalytical(x, t, lambda, c);
				
				// odchylenia
				if (fabs(sumaB10_3 - bAn) > odchB10_3 && (x > -3.6)) odchB10_3 = fabs(sumaB10_3 - bAn);
				if (fabs(sumaB10_4 - bAn) > odchB10_4 && (x > -3.6)) odchB10_4 = fabs(sumaB10_4 - bAn);
				if (fabs(sumaB10_5 - bAn) > odchB10_5 && (x > -3.6)) odchB10_5 = fabs(sumaB10_5 - bAn);
				if (fabs(sumaB20_3 - bAn) > odchB20_3 && (x > -3.2)) odchB20_3 = fabs(sumaB20_3 - bAn);
				if (fabs(sumaB20_4 - bAn) > odchB20_4 && (x > -3.2)) odchB20_4 = fabs(sumaB20_4 - bAn);
				if (fabs(sumaB20_5 - bAn) > odchB20_5 && (x > -3.2)) odchB20_5 = fabs(sumaB20_5 - bAn);
				if (fabs(sumaB40_3 - bAn) > odchB40_3 && (x > -2.45)) odchB40_3 = fabs(sumaB40_3 - bAn);
				if (fabs(sumaB40_4 - bAn) > odchB40_4 && (x > -2.45)) odchB40_4 = fabs(sumaB40_4 - bAn);
				if (fabs(sumaB40_5 - bAn) > odchB40_5 && (x > -2.45)) odchB40_5 = fabs(sumaB40_5 - bAn);
				if (fabs(sumaF10_3 - fAn) > odchF10_3 && (x < 3.6)) odchF10_3 = fabs(sumaF10_3 - fAn);
				if (fabs(sumaF10_4 - fAn) > odchF10_4 && (x < 3.6)) odchF10_4 = fabs(sumaF10_4 - fAn);
				if (fabs(sumaF10_5 - fAn) > odchF10_5 && (x < 3.6)) odchF10_5 = fabs(sumaF10_5 - fAn);
				if (fabs(sumaF20_3 - fAn) > odchF20_3 && (x < 3.2)) odchF20_3 = fabs(sumaF20_3 - fAn);
				if (fabs(sumaF20_4 - fAn) > odchF20_4 && (x < 3.2)) odchF20_4 = fabs(sumaF20_4 - fAn);
				if (fabs(sumaF20_5 - fAn) > odchF20_5 && (x < 3.2)) odchF20_5 = fabs(sumaF20_5 - fAn);
				if (fabs(sumaF40_3 - fAn) > odchF40_3 && (x < 2.45)) odchF40_3 = fabs(sumaF40_3 - fAn);
				if (fabs(sumaF40_4 - fAn) > odchF40_4 && (x < 2.45)) odchF40_4 = fabs(sumaF40_4 - fAn);
				if (fabs(sumaF40_5 - fAn) > odchF40_5 && (x < 2.45)) odchF40_5 = fabs(sumaF40_5 - fAn);
				
				fprintf(out, "%.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g \n", tmax, x, fAn, sumaF10_3, sumaF10_4, sumaF10_5, sumaF20_3, sumaF20_4, sumaF20_5, sumaF40_3, sumaF40_4, sumaF40_5, bAn, sumaB10_3, sumaB10_4, sumaB10_5, sumaB20_3, sumaB20_4, sumaB20_5, sumaB40_3, sumaB40_4, sumaB40_5);
			}
			
			fprintf(odch, "sigma N odchF odchB: \n");
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N1, odchF10_3, odchB10_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N2, odchF10_4, odchB10_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N3, odchF10_5, odchB10_5);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N1, odchF20_3, odchB20_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N2, odchF20_4, odchB20_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N3, odchF20_5, odchB20_5);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N1, odchF40_3, odchB40_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N2, odchF40_4, odchB40_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N3, odchF40_5, odchB40_5);
		
			
			fclose(out);
			fclose(odch);
		}
		
		else if(strcmp(argv[1], "alg3") == 0){
			FILE * out;
			FILE * odch;
			out = fopen("out3.txt", "w");
			odch = fopen("odch3.txt", "w");
			srand(time(NULL));
			
			double t, x, xmin, xmax, c, lambda, tmax, mu, x0, dx, fAn, bAn;
			double sigma10, sigma20, sigma40;
			double sumaB10_3, sumaF10_3, sumaB20_3, sumaF20_3, sumaF40_3, sumaB40_3;
			double sumaB10_4, sumaF10_4, sumaB20_4, sumaF20_4, sumaF40_4, sumaB40_4;
			double sumaB10_5, sumaF10_5, sumaB20_5, sumaF20_5, sumaF40_5, sumaB40_5;
			double odchB10_3, odchF10_3, odchB20_3, odchF20_3, odchF40_3, odchB40_3;
			double odchB10_4, odchF10_4, odchB20_4, odchF20_4, odchF40_4, odchB40_4;
			double odchB10_5, odchF10_5, odchB20_5, odchF20_5, odchF40_5, odchB40_5;
			int N1, N2, N3;
			
		// 1
			xmin = -5; xmax = 5; c = 2.0E+8; lambda = 22.5E+6; tmax = 20E-9;
			mu = 0.0; x0 = 0.0;
			dx = 2*xmax / SIZE;
			sigma10 = 10*dx, sigma20 = 20*dx, sigma40 = 40*dx;
			odchB10_3 = odchB10_4 = odchB10_5 = odchB20_3 = odchB20_4 = odchB20_5 = odchB40_3 = odchB40_4 = odchB40_5 = 0;
			odchF10_3 = odchF10_4 = odchF10_5 = odchF20_3 = odchF20_4 = odchF20_5 = odchF40_3 = odchF40_4 = odchF40_5 = 0;
			
			N1 = 1E+3; N2 = 1E+4; N3 = 1E+5; 
			t = tmax;

		// 3	
			for(x = xmin; x <= xmax; x += dx){
				printf("%g\n", x);
				
				mc3(x, t, N1, c, lambda, mu, sigma10, x0, &sumaB10_3, &sumaF10_3);
				mc3(x, t, N2, c, lambda, mu, sigma10, x0, &sumaB10_4, &sumaF10_4);
				mc3(x, t, N3, c, lambda, mu, sigma10, x0, &sumaB10_5, &sumaF10_5);
				mc3(x, t, N1, c, lambda, mu, sigma20, x0, &sumaB20_3, &sumaF20_3);
				mc3(x, t, N2, c, lambda, mu, sigma20, x0, &sumaB20_4, &sumaF20_4);
				mc3(x, t, N3, c, lambda, mu, sigma20, x0, &sumaB20_5, &sumaF20_5);
				mc3(x, t, N1, c, lambda, mu, sigma40, x0, &sumaB40_3, &sumaF40_3);
				mc3(x, t, N2, c, lambda, mu, sigma40, x0, &sumaB40_4, &sumaF40_4);
				mc3(x, t, N3, c, lambda, mu, sigma40, x0, &sumaB40_5, &sumaF40_5);
				fAn = fAnalytical(x, t, lambda, c);
				bAn = bAnalytical(x, t, lambda, c);
				
				// odchylenia
				if (fabs(sumaB10_3 - bAn) > odchB10_3 && (x > -3.6)) odchB10_3 = fabs(sumaB10_3 - bAn);
				if (fabs(sumaB10_4 - bAn) > odchB10_4 && (x > -3.6)) odchB10_4 = fabs(sumaB10_4 - bAn);
				if (fabs(sumaB10_5 - bAn) > odchB10_5 && (x > -3.6)) odchB10_5 = fabs(sumaB10_5 - bAn);
				if (fabs(sumaB20_3 - bAn) > odchB20_3 && (x > -3.2)) odchB20_3 = fabs(sumaB20_3 - bAn);
				if (fabs(sumaB20_4 - bAn) > odchB20_4 && (x > -3.2)) odchB20_4 = fabs(sumaB20_4 - bAn);
				if (fabs(sumaB20_5 - bAn) > odchB20_5 && (x > -3.2)) odchB20_5 = fabs(sumaB20_5 - bAn);
				if (fabs(sumaB40_3 - bAn) > odchB40_3 && (x > -2.45)) odchB40_3 = fabs(sumaB40_3 - bAn);
				if (fabs(sumaB40_4 - bAn) > odchB40_4 && (x > -2.45)) odchB40_4 = fabs(sumaB40_4 - bAn);
				if (fabs(sumaB40_5 - bAn) > odchB40_5 && (x > -2.45)) odchB40_5 = fabs(sumaB40_5 - bAn);
				if (fabs(sumaF10_3 - fAn) > odchF10_3 && (x < 3.6)) odchF10_3 = fabs(sumaF10_3 - fAn);
				if (fabs(sumaF10_4 - fAn) > odchF10_4 && (x < 3.6)) odchF10_4 = fabs(sumaF10_4 - fAn);
				if (fabs(sumaF10_5 - fAn) > odchF10_5 && (x < 3.6)) odchF10_5 = fabs(sumaF10_5 - fAn);
				if (fabs(sumaF20_3 - fAn) > odchF20_3 && (x < 3.2)) odchF20_3 = fabs(sumaF20_3 - fAn);
				if (fabs(sumaF20_4 - fAn) > odchF20_4 && (x < 3.2)) odchF20_4 = fabs(sumaF20_4 - fAn);
				if (fabs(sumaF20_5 - fAn) > odchF20_5 && (x < 3.2)) odchF20_5 = fabs(sumaF20_5 - fAn);
				if (fabs(sumaF40_3 - fAn) > odchF40_3 && (x < 2.45)) odchF40_3 = fabs(sumaF40_3 - fAn);
				if (fabs(sumaF40_4 - fAn) > odchF40_4 && (x < 2.45)) odchF40_4 = fabs(sumaF40_4 - fAn);
				if (fabs(sumaF40_5 - fAn) > odchF40_5 && (x < 2.45)) odchF40_5 = fabs(sumaF40_5 - fAn);
				
				fprintf(out, "%.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g \n", tmax, x, fAn, sumaF10_3, sumaF10_4, sumaF10_5, sumaF20_3, sumaF20_4, sumaF20_5, sumaF40_3, sumaF40_4, sumaF40_5, bAn, sumaB10_3, sumaB10_4, sumaB10_5, sumaB20_3, sumaB20_4, sumaB20_5, sumaB40_3, sumaB40_4, sumaB40_5);
			}
			
			fprintf(odch, "sigma N odchF odchB: \n");
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N1, odchF10_3, odchB10_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N2, odchF10_4, odchB10_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma10, N3, odchF10_5, odchB10_5);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N1, odchF20_3, odchB20_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N2, odchF20_4, odchB20_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma20, N3, odchF20_5, odchB20_5);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N1, odchF40_3, odchB40_3);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N2, odchF40_4, odchB40_4);
			fprintf(odch, "%.5g %d %.5g %.5g\n", sigma40, N3, odchF40_5, odchB40_5);
		
			fclose(out);
			fclose(odch);
		}
		
		else if(strcmp(argv[1], "rk4") == 0){
			FILE * out;
			FILE * odch;
			out = fopen("outrk4.txt", "w");
			
			double t, x, xmin, xmax, c, lambda, tmax, mu, x0, dx, dt;
			double sigma10, sigma20, sigma40;
			double f10[SIZE], b10[SIZE], f20[SIZE], b20[SIZE], f40[SIZE], b40[SIZE];
			double fAn[SIZE], bAn[SIZE];
			int i = 0;
			
		// 1
			xmin = -5; xmax = 5; c = 2.0E+8; lambda = 22.5E+6; tmax = 20E-9;
			mu = 0.0; x0 = 0.0;
			
			dt = tmax / 1.0E+5;
			dx = 2*xmax / SIZE;
			sigma10 = 10*dx; sigma20 = 20*dx; sigma40 = 40*dx;
			
		//  inicjalizacja funkcją gaussowską
			i = 0;
			for(i = 0; i < SIZE; i++){	
				x = dx*i - xmax;
				
				f10[i] = f0(x, sigma10, x0);
				f20[i] = f0(x, sigma20, x0);
				f40[i] = f0(x, sigma40, x0);
				b10[i] = b0(x, sigma10, x0);
				b20[i] = b0(x, sigma20, x0);
				b40[i] = b0(x, sigma40, x0);
				
				// analitycznie
				fAn[i] = fAnalytical(x, tmax, lambda, c);
				bAn[i] = bAnalytical(x, tmax, lambda, c);
			}
			
		// 2 - RK4
			for(t = 0; t < tmax; t += dt){
				rk4(f10, b10, t, dt, c, lambda, mu, dx);
				rk4(f20, b20, t, dt, c, lambda, mu, dx);
				rk4(f40, b40, t, dt, c, lambda, mu, dx);
				printf ("%.5g\n", (t/tmax));
			}
		
		// zapis wyników
			for(i = 0; i <= SIZE; i++){
				x = dx*i - xmax;				
				fprintf(out, "%.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g \n", tmax, x, fAn[i], f10[i], f20[i], f40[i], bAn[i], b10[i], b20[i], b40[i]);
			}
			
			fclose(out);
		}
		
		else if(strcmp(argv[1], "zad4") == 0){
			FILE * out;
			FILE * odch;
			out = fopen("outzad4.txt", "w");
			srand(time(NULL));
			
			double t, x, xmin, xmax, c, lambda, tmax, mu, x0, dx, dt, cfl;
			double sigma10, sigma20, sigma40;
			double sumaB10_4, sumaF10_4, sumaB20_4, sumaF20_4, sumaF40_4, sumaB40_4;
			double f10[SIZE], b10[SIZE], f20[SIZE], b20[SIZE], f40[SIZE], b40[SIZE];
			int i, N;			
		// 1
			xmin = -5; xmax = 5; c = 2.0E+8; lambda = 22.5E+6; tmax = 20E-9;
			mu = 2*10E+6; x0 = 0.0;
			
			dt = tmax / 1.0E+5;
			dx = 2*xmax / SIZE;
			sigma10 = 10*dx, sigma20 = 20*dx, sigma40 = 40*dx;
			
			N = 1E+4;
			
			//  inicjalizacja funkcją gaussowską
			i = 0;
			for(i = 0; i < SIZE; i++){	
				x = dx*i - xmax;
				
				f10[i] = f0(x, sigma10, x0);
				f20[i] = f0(x, sigma20, x0);
				f40[i] = f0(x, sigma40, x0);
				b10[i] = b0(x, sigma10, x0);
				b20[i] = b0(x, sigma20, x0);
				b40[i] = b0(x, sigma40, x0);
			}
	
		// 4 - RK4
			cfl = c * t / dx;
			printf ("CFL: %.5g\n", cfl);
			for(t = 0; t < tmax; t += dt){
				rk4(f10, b10, t, dt, c, lambda, mu, dx);
				rk4(f20, b20, t, dt, c, lambda, mu, dx);
				rk4(f40, b40, t, dt, c, lambda, mu, dx);
				printf ("RK4: Wykonano: %.5g%%\n", (t/tmax)*100);
			}

		// 4 - MC
			t = tmax, i = 0;
			for(i = 0; i < SIZE; i++){	
				x = dx*i - xmax;
				printf("MC: %g\n", x);				
				mc3(x, t, N, c, lambda, mu, sigma10, x0, &sumaB10_4, &sumaF10_4);
				mc3(x, t, N, c, lambda, mu, sigma20, x0, &sumaB20_4, &sumaF20_4);
				mc3(x, t, N, c, lambda, mu, sigma40, x0, &sumaB40_4, &sumaF40_4);
				fprintf(out, "%.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g %.5g \n", tmax, x, f10[i], sumaF10_4, f20[i], sumaF20_4, f40[i], sumaF40_4, b10[i], sumaB10_4, b20[i], sumaB20_4, b40[i], sumaB40_4);
				i++;
			}
		
			fclose(out);
		}
		
		else if(strcmp(argv[1], "compare") == 0){
			FILE * out;
			out = fopen("out_compare.txt", "w");
			srand(time(NULL));
			
			clock_t start, end;
			double t, x, xmin, xmax, c, lambda, tmax, mu, x0, dx, fAn, bAn;
			double dt, cpu_time_used;
			double sumaB_an, sumaF_an, sumaB_12, sumaF_12, sumaB_3, sumaF_3;
			double f_rk4[SIZE], b_rk4[SIZE];
			int i, N1, N2, N3;
			
			xmin = -5; xmax = 5; c = 2.0E+8; lambda = 22.5E+6; tmax = 20E-9;
			mu = 0.0; x0 = 0.0;
			dt = tmax / 1.0E+5;
			dx = 2*xmax / SIZE;
			double sigma10, sigma20, sigma40;
			
			N1 = 1E+3; N2 = 1E+4; N3 = 1E+5; 
			sigma10 = 10*dx, sigma20 = 20*dx, sigma40 = 40*dx;
			
			t = tmax;
			printf("Analitycznie...\n");
			fprintf(out, "Analitycznie: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_an = fAnalytical(x, t, lambda, c);
				sumaB_an = bAnalytical(x, t, lambda, c);

			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			
		// Monte Carlo - algorytmy 1 i 2
			t = tmax;
			printf("Monte Carlo (algorytmy 1 i 2)...\n");
			fprintf(out, "Monte Carlo (algorytmy 1 i 2): \n");
			printf("n = 10^3, sigma = 10*dx: ");
			fprintf(out, "n = 10^3, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N1, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB_12 = mc2(N1, tmax, x, c, lambda, mu, sigma10, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			t = tmax;
			printf("n = 10^4, sigma = 10*dx: ");
			fprintf(out, "n = 10^4, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N2, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB_12 = mc2(N2, tmax, x, c, lambda, mu, sigma10, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			t = tmax;
			printf("n = 10^5, sigma = 10*dx: ");
			fprintf(out, "n = 10^5, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N3, tmax, x, c, lambda, mu, sigma10, x0);
				sumaB_12 = mc2(N3, tmax, x, c, lambda, mu, sigma10, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^3, sigma = 20*dx: ");
			fprintf(out, "n = 10^3, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N1, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB_12 = mc2(N1, tmax, x, c, lambda, mu, sigma20, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			t = tmax;
			printf("n = 10^4, sigma = 20*dx: ");
			fprintf(out, "n = 10^4, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N2, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB_12 = mc2(N2, tmax, x, c, lambda, mu, sigma20, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
						t = tmax;;
			printf("n = 10^5, sigma = 20*dx: ");
			fprintf(out, "n = 10^5, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N3, tmax, x, c, lambda, mu, sigma20, x0);
				sumaB_12 = mc2(N3, tmax, x, c, lambda, mu, sigma20, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
				printf("n = 10^3, sigma = 40*dx: ");
			fprintf(out, "n = 10^3, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N1, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB_12 = mc2(N1, tmax, x, c, lambda, mu, sigma40, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			t = tmax;
			printf("n = 10^4, sigma = 40*dx: ");
			fprintf(out, "n = 10^4, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N2, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB_12 = mc2(N2, tmax, x, c, lambda, mu, sigma40, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			t = tmax;
			printf("n = 10^5, sigma = 40*dx: ");
			fprintf(out, "n = 10^5, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				sumaF_12 = mc1(N3, tmax, x, c, lambda, mu, sigma40, x0);
				sumaB_12 = mc2(N3, tmax, x, c, lambda, mu, sigma40, x0);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
		
		// Monte Carlo - algorytm 3
			t = tmax;
			printf("Monte Carlo (algorytm 3)...\n");
			fprintf(out, "Monte Carlo (algorytm 3): \n");
			printf("n = 10^3, sigma = 10*dx: ");
			fprintf(out, "n = 10^3, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N1, c, lambda, mu, sigma10, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^4, sigma = 10*dx: ");
			fprintf(out, "n = 10^4, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N2, c, lambda, mu, sigma10, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^5, sigma = 10*dx: ");
			fprintf(out, "n = 10^5, sigma = 10*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N3, c, lambda, mu, sigma10, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^3, sigma = 20*dx: ");
			fprintf(out, "n = 10^3, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N1, c, lambda, mu, sigma20, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^4, sigma = 20*dx: ");
			fprintf(out, "n = 10^4, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N2, c, lambda, mu, sigma20, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^5, sigma = 20*dx: ");
			fprintf(out, "n = 10^5, sigma = 20*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N3, c, lambda, mu, sigma20, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^3, sigma = 40*dx: ");
			fprintf(out, "n = 10^3, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N1, c, lambda, mu, sigma40, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^4, sigma = 40*dx: ");
			fprintf(out, "n = 10^4, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N2, c, lambda, mu, sigma40, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("n = 10^5, sigma = 40*dx: ");
			fprintf(out, "n = 10^5, sigma = 40*dx: ");
			start = clock();
			for(x = xmin; x <= xmax; x += dx){
				mc3(x, t, N3, c, lambda, mu, sigma40, x0, &sumaB_3, &sumaF_3);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			
		// RK4	
			printf("Rungego-Kutty 4. rzędu...\n");
			fprintf(out, "Rungego-Kutty 4. rzędu: \n");
			printf("sigma = 10*dx: ");
			fprintf(out, "sigma = 10*dx: ");
			start = clock();
			i = 0;
			for(i = 0; i < SIZE; i++){	
				f_rk4[i] = f0(x, sigma10, x0);
				b_rk4[i] = b0(x, sigma10, x0);
			}
			for(t = 0; t < tmax; t += dt){
				rk4(f_rk4, b_rk4, t, dt, c, lambda, mu, dx);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("sigma = 20*dx: ");
			fprintf(out, "sigma = 20*dx: ");
			start = clock();
			i = 0;
			for(i = 0; i < SIZE; i++){	
				f_rk4[i] = f0(x, sigma20, x0);
				b_rk4[i] = b0(x, sigma20, x0);
			}
			for(t = 0; t < tmax; t += dt){
				rk4(f_rk4, b_rk4, t, dt, c, lambda, mu, dx);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			printf("sigma = 40*dx: ");
			fprintf(out, "sigma = 40*dx: ");
			start = clock();
			i = 0;
			for(i = 0; i < SIZE; i++){	
				f_rk4[i] = f0(x, sigma40, x0);
				b_rk4[i] = b0(x, sigma40, x0);
			}
			for(t = 0; t < tmax; t += dt){
				rk4(f_rk4, b_rk4, t, dt, c, lambda, mu, dx);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(out, "%g s\n", cpu_time_used);
			printf("%g s\n", cpu_time_used);
			
			fclose(out);
		}
		
		else printf("Usage: make alg12/alg3/rk4/zad4/compare\n");
	}
}