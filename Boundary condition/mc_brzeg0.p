set term png

set out "plots/0/mc0_3_075.png"
	set title 'a) f0 = 0 Hz, N = 10^3, tmax = 7.5 * 10^{-9} s' font ", 20"
	set ylabel 'u(x)' font ", 18"
	set xlabel 'x' font ", 18"
	set key font ", 18"
	set xtics font ", 16"
	set ytics font ", 16"
    plot 'out0.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:3 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_075_dif.png"
	set title 'b) f0 = 0 Hz, N = 10^3, tmax = 7.5 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:4 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_075.png"
	set title 'f0 = 0, N = 10^4, tmax = 7.5 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:5 w p lt 2 t 'u_{num}'

set out "plots/0/mc0_4_075_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 7.5 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:6 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_5_075.png"
	set title 'f0 = 0, N = 10^5, tmax = 7.5 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:7 w p lt 2 t 'u_{num}'

set out "plots/0/mc0_5_075_dif.png"
	set title 'c) f0 = 0 Hz, N = 10^5, tmax = 7.5 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:8 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_3_10.png"
	set title 'd) f0 = 0 Hz, N = 10^3, tmax = 10 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:9 w l lt 1 lw 2 t 'u_A',\
    '' u 1:10 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_10_dif.png"
	set title 'e) f0 = 0 Hz, N = 10^3, tmax = 10 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:11 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_10.png"
	set title 'f0 = 0, N = 10^4, tmax = 10 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:9 w l lt 1 lw 2 t 'u_A',\
    '' u 1:12 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_10_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 10 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:13 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/0/mc0_5_10.png"
	set title 'f0 = 0, N = 10^5, tmax = 10 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:10 w l lt 1 lw 2 t 'u_A',\
    '' u 1:14 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_10_dif.png"
	set title 'f) f0 = 0 Hz, N = 10^5, tmax = 10 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:15 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/0/mc0_3_15.png"
	set title 'g) f0 = 0 Hz, N = 10^3, tmax = 15 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:17 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_15_dif.png"
	set title 'h) f0 = 0 Hz, N = 10^3, tmax = 15 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:18 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_15.png"
	set title 'f0 = 0, N = 10^4, tmax = 15 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:19 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_15_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 15 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:20 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/0/mc0_5_15.png"
	set title 'f0 = 0, N = 10^5, tmax = 15 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:21 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_15_dif.png"
	set title 'i) f0 = 0 Hz, N = 10^5, tmax = 15 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:22 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/0/mc0_3_20.png"
	set title 'f0 = 0, N = 10^3, tmax = 20 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:24 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_20_dif.png"
	set title 'f0 = 0, N = 10^3, tmax = 20 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:25 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_20.png"
	set title 'f0 = 0, N = 10^4, tmax = 20 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:26 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_20_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 20 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:27 w l lt 1 lw 2 t 'u_A - u_{num}'
	
	set out "plots/0/mc0_5_20.png"
	set title 'f0 = 0, N = 10^5, tmax = 20 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:28 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_20_dif.png"
	set title 'f0 = 0, N = 10^5, tmax = 20 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:29 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/0/mc0_3_25.png"
	set title 'j) f0 = 0 Hz, N = 10^3, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:31 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_25_dif.png"
	set title 'k) f0 = 0 Hz, N = 10^3, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:32 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/0/mc0_4_25.png"
	set title 'f0 = 0, N = 10^4, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:33 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_25_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:34 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/0/mc0_5_25.png"
	set title 'f0 = 0, N = 10^5, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:35 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_25_dif.png"
	set title 'l) f0 = 0 Hz, N = 10^5, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:36 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/0/mc0_3_30.png"
	set title 'f0 = 0, N = 10^3, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:38 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_30_dif.png"
	set title 'f0 = 0, N = 10^3, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:39 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_30.png"
	set title 'f0 = 0, N = 10^4, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:40 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_30_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:41 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/0/mc0_5_30.png"
	set title 'f0 = 0, N = 10^5, tmax = 25 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:42 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_30_dif.png"
	set title 'f0 = 0, N = 10^5, tmax = 25 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:43 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/0/mc0_3_35.png"
	set title 'm) f0 = 0 Hz, N = 10^3, tmax = 35 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:45 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_3_35_dif.png"
	set title 'n) f0 = 0 Hz, N = 10^3, tmax = 35 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:46 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/0/mc0_4_35.png"
	set title 'f0 = 0, N = 10^4, tmax = 35 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:47 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_4_35_dif.png"
	set title 'f0 = 0, N = 10^4, tmax = 35 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:48 w l lt 1 lw 2 t 'u_A - u_{num}'			
	
set out "plots/0/mc0_5_35.png"
	set title 'f0 = 0, N = 10^5, tmax = 35 * 10^{-9} s'
	set ylabel 'u(x)'
	set xlabel 'x'
    plot 'out0.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:49 w p lt 2 t 'u_{num}'
	
set out "plots/0/mc0_5_35_dif.png"
	set title 'o) f0 = 0 Hz, N = 10^5, tmax = 35 * 10^{-9} s'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
    plot 'out0.txt' u 1:50 w l lt 1 lw 2 t 'u_A - u_{num}'			