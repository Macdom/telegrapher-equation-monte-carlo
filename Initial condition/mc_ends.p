set term png

set out "plots/alg3/ends/mc3_f_10.png"
	set title 'Algorytm 3 (sigma = 10 - prawy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[3.6:5]
    plot 'out3.txt' u 2:4 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:5 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:6 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'

set out "plots/alg3/ends/mc3_f_20.png"
	set title 'Algorytm 3 (sigma = 20 - prawy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[3.2:5]
    plot 'out3.txt' u 2:7 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:8 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:9 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'
	
set out "plots/alg3/ends/mc3_f_40.png"
	set title 'Algorytm 3 (sigma = 40 - prawy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[2.45:5]
    plot 'out3.txt' u 2:10 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:11 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:12 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'

set out "plots/alg3/ends/mc3_b_10.png"
	set title 'Algorytm 3 (sigma = 10 - lewy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-3.6]
    plot 'out3.txt' u 2:14 w l lt 1 lw 2 t 'N = 10**3',\
	'' u 2:15 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:16 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'

set out "plots/alg3/ends/mc3_b_20.png"
	set title 'Algorytm 3 (sigma = 20 - lewy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-3.2]
    plot 'out3.txt' u 2:17 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:18 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:19 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'
	
set out "plots/alg3/ends/mc3_b_40.png"
	set title 'Algorytm 3 (sigma = 40 - lewy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-2.45]
    plot 'out3.txt' u 2:20 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:21 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:22 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'
	
	set out "plots/alg12/ends/mc12_f_10.png"
	set title 'Algorytmy 1 i 2 (sigma = 10 - lewy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[3.6:5]
    plot 'out12.txt' u 2:4 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:5 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:6 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'

set out "plots/alg12/ends/mc12_f_20.png"
	set title 'Algorytmy 1 i 2 (sigma = 20 - lewy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[3.2:5]
    plot 'out12.txt' u 2:7 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:8 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:9 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'
	
set out "plots/alg12/ends/mc12_f_40.png"
	set title 'Algorytmy 1 i 2 (sigma = 40 - lewy brzeg)'
	set ylabel 'f(x)'
	set xlabel 'x'
	set xrange[2.45:5]
    plot 'out12.txt' u 2:10 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:11 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:12 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:3 w l lt 2 lw 2 t 'analytical'

set out "plots/alg12/ends/mc12_b_10.png"
	set title 'Algorytmy 1 i 2 (sigma = 10 - prawy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-3.6]
    plot 'out12.txt' u 2:14 w l lt 1 lw 2 t 'N = 10**3',\
	'' u 2:15 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:16 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'

set out "plots/alg12/ends/mc12_b_20.png"
	set title 'Algorytmy 1 i 2 (sigma = 20 - prawy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-3.2]
    plot 'out12.txt' u 2:17 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:18 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:19 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'
	
set out "plots/alg12/ends/mc12_b_40.png"
	set title 'Algorytmy 1 i 2 (sigma = 40 - prawy brzeg)'
	set ylabel 'b(x)'
	set xlabel 'x'
	set xrange [-5:-2.45]
    plot 'out12.txt' u 2:20 w l lt 1 lw 2 t 'N = 10**3',\
    '' u 2:21 w l lt 3 lw 2 t 'N = 10**4',\
    '' u 2:22 w l lt 4 lw 2 t 'N = 10**5',\
	'' u 2:13 w l lt 2 lw 2 t 'analytical'
	
