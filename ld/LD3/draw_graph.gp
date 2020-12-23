set terminal svg size 800,600
set out "output.svg"
set grid
plot "derivative.dat" using 1:2 title "f" with lines, \
     "derivative.dat" using 1:3 title "f' numeral" with lines, \
     "derivative.dat" using 1:4 title "f'' numeral" with lines, \
     "derivative.dat" using 1:5 title "f' analytical" with lines, \
     "derivative.dat" using 1:6 title "f''analytical" with lines
