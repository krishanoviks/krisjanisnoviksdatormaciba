set terminal svg size 400,300 enhanced fname 'arial' butt solid
set output "output.svg"


set title 'exp(x)'
plot  "myfile.txt" with lines
