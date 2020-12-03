set term png

set out "plots/27/mc27_3_075.png"
	set title 'a) f0 = 27 GHz, N = 10^3, tmax = 7.5 ns' font ", 22"
	set ylabel 'u(x)' font ", 20"
	set xlabel 'x' font ", 20"
	set key font ", 20"
	set xtics font ", 18"
	set ytics font ", 18"
	set xrange[0:2]
    plot 'out27.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:3 w p lt 2 t 'u_{num}'
	
set out "plots/27/closeup/mc27_3_075.png"
	set title 'b) f0 = 27 GHz, N = 10^3, tmax = 7.5 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:0.5]
    plot 'out27.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:3 w p lt 2 t 'u_{num}'	
	
set out "plots/27/mc27_3_075_dif.png"
	set title 'c) f0 = 27 GHz, N = 10^3, tmax = 7.5 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:4 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_075.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 7.5 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:5 w p lt 2 t 'u_{num}'
	

set out "plots/27/mc27_4_075_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 7.5 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:6 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_5_075.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 7.5 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:2 w l lt 1 lw 2 t 'u_A',\
    '' u 1:7 w p lt 2 t 'u_{num}'

set out "plots/27/mc27_5_075_dif.png"
	set title 'd) f0 = 27 GHz, N = 10^5, tmax = 7.5 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:8 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_3_10.png"
	set title 'e) f0 = 27 GHz, N = 10^3, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:9 w l lt 1 lw 2 t 'u_A',\
    '' u 1:10 w p lt 2 t 'u_{num}'
	
set out "plots/27/closeup/mc27_3_10.png"
	set title 'f) f0 = 27 GHz, N = 10^3, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0.1:0.9]
    plot 'out27.txt' u 1:9 w l lt 1 lw 2 t 'u_A',\
    '' u 1:10 w p lt 2 t 'u_{num}'	
	
set out "plots/27/mc27_3_10_dif.png"
	set title 'g) f0 = 27 GHz, N = 10^3, tmax = 10 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:11 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_10.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:9 w l lt 1 lw 2 t 'u_A',\
    '' u 1:12 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_10_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 10 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:13 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/27/mc27_5_10.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 10 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:10 w l lt 1 lw 2 t 'u_A',\
    '' u 1:14 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_10_dif.png"
	set title 'h) f0 = 27 GHz, N = 10^5, tmax = 10 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:15 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/27/mc27_3_15.png"
	set title 'i) f0 = 27 GHz, N = 10^3, tmax = 15 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:17 w p lt 2 t 'u_{num}'
	
set out "plots/27/closeup/mc27_3_15.png"
	set title 'j) f0 = 27 GHz, N = 10^3, tmax = 15 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[1.1:1.9]
    plot 'out27.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:17 w p lt 2 t 'u_{num}'	
	
set out "plots/27/mc27_3_15_dif.png"
	set title 'k) f0 = 27 GHz, N = 10^3, tmax = 15 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:18 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_15.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 15 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:19 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_15_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 15 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:20 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/27/mc27_5_15.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 15 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:16 w l lt 1 lw 2 t 'u_A',\
    '' u 1:21 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_15_dif.png"
	set title 'l) f0 = 27 GHz, N = 10^5, tmax = 15 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:22 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/27/mc27_3_20.png"
	set title 'f0 = 27 GHz, N = 10^3, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:24 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_3_20_dif.png"
	set title 'f0 = 27 GHz, N = 10^3, tmax = 20 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:25 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_20.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:26 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_20_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 20 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:27 w l lt 1 lw 2 t 'u_A - u_{num}'
	
	set out "plots/27/mc27_5_20.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 20 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:23 w l lt 1 lw 2 t 'u_A',\
    '' u 1:28 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_20_dif.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 20 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:29 w l lt 1 lw 2 t 'u_A - u_{num}'
	
set out "plots/27/mc27_3_25.png"
	set title 'm) f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:31 w p lt 2 t 'u_{num}'
	
set out "plots/27/closeup/mc27_3_25.png"
	set title 'n) f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0.1:0.9]
    plot 'out27.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:31 w p lt 2 t 'u_{num}'	
	
set out "plots/27/mc27_3_25_dif.png"
	set title 'o) f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:32 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/27/mc27_4_25.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:33 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_25_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:34 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/27/mc27_5_25.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:30 w l lt 1 lw 2 t 'u_A',\
    '' u 1:35 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_25_dif.png"
	set title 'p) f0 = 27 GHz, N = 10^5, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:36 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/27/mc27_3_30.png"
	set title 'f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:38 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_3_30_dif.png"
	set title 'f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:39 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_30.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:40 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_30_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:41 w l lt 1 lw 2 t 'u_A - u_{num}'	

set out "plots/27/mc27_5_30.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:37 w l lt 1 lw 2 t 'u_A',\
    '' u 1:42 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_30_dif.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 25 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:43 w l lt 1 lw 2 t 'u_A - u_{num}'	
	
set out "plots/27/mc27_3_35.png"
	set title 'q) f0 = 27 GHz, N = 10^3, tmax = 35 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:45 w p lt 2 t 'u_{num}'
	
set out "plots/27/closeup/mc27_3_35.png"
	set title 'r) f0 = 27 GHz, N = 10^3, tmax = 25 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[1.1:1.9]
    plot 'out27.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:45 w p lt 2 t 'u_{num}'		
	
set out "plots/27/mc27_3_35_dif.png"
	set title 's) f0 = 27 GHz, N = 10^3, tmax = 35 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:46 w l lt 1 lw 2 t 'u_A - u_{num}'

set out "plots/27/mc27_4_35.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 35 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:47 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_4_35_dif.png"
	set title 'f0 = 27 GHz, N = 10^4, tmax = 35 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:48 w l lt 1 lw 2 t 'u_A - u_{num}'			
	
set out "plots/27/mc27_5_35.png"
	set title 'f0 = 27 GHz, N = 10^5, tmax = 35 ns'
	set ylabel 'u(x)'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:44 w l lt 1 lw 2 t 'u_A',\
    '' u 1:49 w p lt 2 t 'u_{num}'
	
set out "plots/27/mc27_5_35_dif.png"
	set title 't) f0 = 27 GHz, N = 10^5, tmax = 35 ns'
	set ylabel 'u_A - u_{num}'
	set xlabel 'x'
	set xrange[0:2]
    plot 'out27.txt' u 1:50 w l lt 1 lw 2 t 'u_A - u_{num}'			