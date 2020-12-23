set terminal svg size 800,600 enhanced fname 'arial' butt solid
set output "output.svg"


set title 'exp(-x)'
plot  "myfile.txt" with lines title "e^(-x)"
