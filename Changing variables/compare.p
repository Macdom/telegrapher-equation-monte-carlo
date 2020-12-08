set term png

set out "plots/compare.png"
	set title 'Czas działania funkcji MC'
	set ylabel 't [s]'
	set xlabel 'tmax [ns]'
	set format x "%.0s"
	Z = 36500000
	W = 0.067
	f(x) = W * exp(x * Z)
    #plot 'out_compare.txt' u 1:2 w p lt 2
	plot 'out_compare.txt' u 1:2 ps 1.3 pt 2 t 'Czas działania',\
    f(x) w l lt 2 lw 2 t 'Dopasowana funkcja'