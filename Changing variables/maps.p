set term png

set view map
unset contour

set out "plots/maps/map_0_L2.png"
	set palette defined (-0.148718 'blue', 0 'white', 0.855223 'red')
	set cbrange [-0.148718:0.855223];
	set title 'a) f0 = 0 Hz, L_2 = 2L_1' font ", 20"
	set ylabel 't [ns]' font ", 18"
	set xlabel 'x [m]' font ", 18"
	set key font ", 18"
	set format y "%.0s"
	set xtics font ", 14"
	set ytics font ", 14"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:3 w pm3d notitle


set out "plots/maps/map_0_L16.png"
	set palette defined (-0.419831 'blue', 0 'white', 0.853551 'red')
	set cbrange [-0.419831:0.853551];
	set title 'b) f0 = 0 Hz, L_2 = 16L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:4 w pm3d notitle

set out "plots/maps/map_0_L025.png"
	set palette defined (-0.146878 'blue', 0 'white', 0.854708 'red')
	set cbrange [-0.146878:0.854708];
	set title 'c) f0 = 0 Hz, L_2 = 0.25L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:5 w pm3d notitle
	
set out "plots/maps/map_3_L2.png"
	set palette defined (-0.445577 'blue', 0 'white', 0.392112 'red')
	set cbrange [-0.445577:0.392112];
	set title 'd) f0 = 3 GHz, L_2 = 2L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:6 w pm3d notitle


set out 'plots/maps/map_3_L16.png'
	set palette defined (-0.444549 'blue', 0 'white', 0.392632 'red')
	set cbrange [-0.444549:0.392632];
	set title 'e) f0 = 3 GHz, L_2 = 16L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:7 w pm3d notitle

set out "plots/maps/map_3_L025.png"
	set palette defined (-0.44577 'blue', 0 'white', 0.392463 'red')
	set cbrange [-0.44577:0.392463];
	set title 'f) f0 = 3 GHz, L_2 = 0.25L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:8 w pm3d	notitle
	
set out "plots/maps/map_9_L2.png"
	set palette defined (-0.444461 'blue', 0 'white', 0.393461 'red')
	set cbrange [-0.444461:0.393461];
	set title 'g) f0 = 9 GHz, L_2 = 2L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:9 w pm3d notitle


set out "plots/maps/map_9_L16.png"
	set palette defined (-0.446108 'blue', 0 'white', 0.394397 'red')
	set cbrange [-0.446108:0.394397];
	set title 'h) f0 = 9 GHz, L_2 = 16L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:10 w pm3d notitle

set out "plots/maps/map_9_L025.png"
	set palette defined (-0.445624 'blue', 0 'white', 0.39243 'red')
	set cbrange [-0.445624:0.39243];
	set title 'i) f0 = 9 GHz, L_2 = 0.25L_1' font ", 20"
	set pm3d interpolate 2,2
	splot 'out_maps_new.txt' u 2:1:11 w pm3d notitle		

