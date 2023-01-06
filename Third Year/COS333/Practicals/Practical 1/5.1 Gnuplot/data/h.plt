# Imports
set terminal png  
set output 'irisgraph.png'

# Set labels
set xlabel 'Petal Length (cm)'
set ylabel 'Petal Width (cm)'

# Set Title
set title 'Polynomial Regression on Iris Dataset'

# Set Ranges
set xrange [0:7]
set yrange [0:2.7]

# Creart graph
f(x) = a*x**3 + b*x**2 + c*x + d
set datafile separator comma
fit f(x) "iris.data" using 3:4 via a,b,c,d

# Read data
set datafile separator comma
plot f(x) linecolor 7 notitle, "iris.data" using 3:4 with points pointtype 6 linecolor 14 notitle



