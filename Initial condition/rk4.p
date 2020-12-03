set term png

set out "plots/rk4/mc_f.png"
	set title 'Algorytm RK4'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[-5:5]
    plot 'outrk4.txt' u 2:3 w l lt 2 lw 2 t 'analytical',\
    '' u 2:4 w l lt 1 lw 2 t 'RK4, sigma = 10',\
    '' u 2:5 w l lt 4 lw 2 t 'RK4, sigma = 20',\
    '' u 2:6 w l lt 3 lw 2 t 'RK4, sigma = 40'

set out "plots/rk4/mc_b.png"
	set title 'Algorytm RK4'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange[-5:5]
    plot 'outrk4.txt' u 2:7 w l lt 2 lw 2 t 'analytical',\
    '' u 2:8 w l lt 1 lw 2 t 'RK4, sigma = 10',\
    '' u 2:9 w l lt 4 lw 2 t 'RK4, sigma = 20',\
    '' u 2:10 w l lt 3 lw 2 t 'RK4, sigma = 40'
