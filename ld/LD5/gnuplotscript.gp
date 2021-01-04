set terminal svg  size 2000,800 enhanced
set output "histogram.svg"
set title "Krisjanis ir baigi fors"
set style data histogram
plot 'histogram.txt' using 2:xtic(1)
