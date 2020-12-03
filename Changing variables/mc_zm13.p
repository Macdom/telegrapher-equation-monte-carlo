set term png

set out "plots/13/mc0_3_10.png"
	set title 'a) f0 = 1.3 GHz, N = 10^3, tmax = 10 ns' font ", 20"
	set ylabel 'u(x)' font ", 18"
	set xlabel 'x' font ", 18"
	set key font ", 18"
	set xtics font ", 16"
	set ytics font ", 16"
    plot 'out13.txt' u 1:2 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:3 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_10.png"
	set title 'b) f0 = 1.3 GHz, N = 10^4, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:4 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:5 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_10.png"
	set title 'c) f0 = 1.3 GHz, N = 10^5, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x' 
    plot 'out13.txt' u 1:6 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:7 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_3_20.png"
	set title 'd) f0 = 1.3 GHz, N = 10^3, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:8 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:9 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_20.png"
	set title 'e) f0 = 1.3 GHz, N = 10^4, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:10 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:11 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_20.png"
	set title 'f) f0 = 1.3 GHz, N = 10^5, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:12 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:13 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_3_30.png"
	set title 'g) f0 = 1.3 GHz, N = 10^3, tmax = 30 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:14 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:15 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_30.png"
	set title 'h) f0 = 1.3 GHz, N = 10^4, tmax = 30 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:16 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:17 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_30.png"
	set title 'i) f0 = 1.3 GHz, N = 10^5, tmax = 30 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:18 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:19 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_3_40.png"
	set title 'j) f0 = 1.3 GHz, N = 10^3, tmax = 40 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:20 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:21 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_40.png"
	set title 'k) f0 = 1.3 GHz, N = 10^4, tmax = 40 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:22 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:23 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_40.png"
	set title 'l) f0 = 1.3 GHz, N = 10^5, tmax = 40 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:24 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:25 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_3_50.png"
	set title 'm) f0 = 1.3 GHz, N = 10^3, tmax = 50 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:26 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:27 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_50.png"
	set title 'n) f0 = 1.3 GHz, N = 10^4, tmax = 50 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:28 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:29 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_50.png"
	set title 'o) f0 = 1.3 GHz, N = 10^5, tmax = 50 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:30 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:31 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_3_60.png"
	set title 'p) f0 = 1.3 GHz, N = 10^3, tmax = 60 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:32 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:33 w l lt 2 lw 2 t 'L_2 = 16L_1'
	
set out "plots/13/mc0_4_60.png"
	set title 'q) f0 = 1.3 GHz, N = 10^4, tmax = 60 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:34 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:35 w l lt 2 lw 2 t 'L_2 = 16L_1'

set out "plots/13/mc0_5_60.png"
	set title 'r) f0 = 1.3 GHz, N = 10^5, tmax = 60 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out13.txt' u 1:36 w l lt 1 lw 2 t 'L_2 = 2L_1',\
    '' u 1:37 w l lt 2 lw 2 t 'L_2 = 16L_1'		