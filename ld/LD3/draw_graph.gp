set terminal svg size 800,600
set out "output.svg"
set grid
plot "derivative.dat" using 1:2 title "f"
replot "derivative.dat" using 1:3 title "f' numeral"
replot "derivative.dat" using 1:4 title "f'' numeral"
replot "derivative.dat" using 1:5 title "f' analytical"
replot "derivative.dat" using 1:6 title "f''analytical"
