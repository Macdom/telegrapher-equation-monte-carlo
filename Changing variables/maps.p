set term png

set view map
set size square
unset contour


set out "plots/maps/map_L2.png"
	set palette defined (-0.407603 'blue', 0 'white', 0.993119 'red')
	set cbrange [-0.407603:0.993119];
	set title 'a) L_2 = 2L_1' font ", 20"
	set ylabel 't [ns]' font ", 18"
	set xlabel 'x [m]' font ", 18"
	set key font ", 18"
	set format y "%.0s"
	set xtics font ", 16"
	set ytics font ", 16"
	set pm3d interpolate 2,2
	splot 'out_maps.txt' u 2:1:3 w pm3d


set out "plots/maps/map_L16.png"
	set palette defined (-0.447596 'blue', 0 'white', 0.855377 'red')
	set cbrange [-0.447596:0.855377];
	set title 'b) L_2 = 16L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps.txt' u 2:1:4 w pm3d

