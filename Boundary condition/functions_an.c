#include <math.h>
#include <complex.h>
#include <stdlib.h>

#include "functions.h"

double complex analytical(double f0, double sigma0, double R, double L, double G, double C, double Rin, double Rout, double t0, double t, double xmax, double xx, double nomega){
	double nx, dx;
	double omega0, domega, omegamax;
	double x, omega, i;
	double Zout, c;
	double complex Z0, ksi, gammain, gammaout, k, u0, ui, suma_u, wynik, VG;
	
	nx = 100.0;
	dx = xmax / (nx+1);
	
	if (f0 > 0) {
		omega0 = 2*M_PI * f0;
		domega = 2*omega0 / nomega;
	}
	if (fabs(f0) < 1.0e-5) {
		omega0 = 0;
		omegamax = 2 / sigma0;
		domega = 2*omegamax / nomega;
	}
	
	x=xx;
	wynik = 0+I*0;
	for(omega = -(domega*nomega); omega <= (domega*nomega); omega += domega){
		Z0 = csqrt((R + I*omega*L) / (G + I*omega*C));
		ksi = Z0 / (Z0 + Rin);
		Zout = Rout;
		gammain = (Rin - Z0) / (Rin + Z0);
		gammaout = (Zout - Z0) / (Zout + Z0);
		c = 1 / (sqrt(L*C));
		k = (-I/c) * (csqrt((I*omega + R/L) * (I*omega + G/C)));
		
		VG = sqrt(M_PI/2)*sigma0*(
				cexp(-0.5*(omega0+omega)*((omega0+omega)*sigma0*sigma0+2*I*t0))
				+cexp(0.5*(omega0-omega)*((-omega0+omega)*sigma0*sigma0+2*I*t0)));
		
		u0 = ksi * VG * (cexp(-I*k*x) + gammaout * cexp(-I*k * (2*xmax - x)));
		
		suma_u = 0+I*0;
		for (i = 0; i <= 100; i++){
			ui = u0 * cpowf(gammain, i) * cpowf(gammaout, i) * cexp(-2*I * k * i * xmax);
			suma_u = suma_u + ui;
		}
		wynik = wynik + (1 / (2*M_PI)) * suma_u * cexp(I * omega * t) * domega;
	}
	return wynik;
}