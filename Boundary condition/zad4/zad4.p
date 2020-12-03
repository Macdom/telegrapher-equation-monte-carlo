set term png

set out "zad4_0.png"
	set title 'a) f0 = 0 Hz' font ", 20"
	set ylabel 'u_A - u_{num}' font ", 18"
	set xlabel 't' font ", 18"
	set key font ", 18"
	set xtics font ", 16"
	set ytics font ", 16"
    plot 'out_zad4_0.txt' u 2:3 w l lt 1 lw 2 t 'N = 10^3',\
	'' u 2:4 w l lt 2 lw 2 t 'N = 10^4',\
	'' u 2:5 w l lt 3 lw 2 t 'N = 10^5'
	
set out "zad4_1.png"
	set title 'b) f0 = 1 GHz'
	set ylabel 'u_A - u_{num}'
	set xlabel 't'
    plot 'out_zad4_1.txt' u 2:3 w l lt 1 lw 2 t 'N = 10^3',\
	'' u 2:4 w l lt 2 lw 2 t 'N = 10^4',\
	'' u 2:5 w l lt 3 lw 2 t 'N = 10^5'

set out "zad4_3.png"
	set title 'c) f0 = 3 GHz'
	set ylabel 'u_A - u_{num}'
	set xlabel 't'
    plot 'out_zad4_3.txt' u 2:3 w l lt 1 lw 2 t 'N = 10^3',\
	'' u 2:4 w l lt 2 lw 2 t 'N = 10^4',\
	'' u 2:5 w l lt 3 lw 2 t 'N = 10^5'

set out "zad4_9.png"
	set title 'd) f0 = 9 GHz'
	set ylabel 'u_A - u_{num}'
	set xlabel 't'
    plot 'out_zad4_9.txt' u 2:3 w l lt 1 lw 2 t 'N = 10^3',\
	'' u 2:4 w l lt 2 lw 2 t 'N = 10^4',\
	'' u 2:5 w l lt 3 lw 2 t 'N = 10^5'

set out "zad4_27.png"
	set title 'e) f0 = 27 GHz'
	set ylabel 'u_A - u_{num}'
	set xlabel 't'
    plot 'out_zad4_27.txt' u 2:3 w l lt 1 lw 2 t 'N = 10^3',\
	'' u 2:4 w l lt 2 lw 2 t 'N = 10^4',\
	'' u 2:5 w l lt 3 lw 2 t 'N = 10^5'		