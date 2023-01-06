#set for comma
set datafile separator ","

#title
set title "Polynomial Regression on Iris Dataset"

#labels
set xlabel "Petal Length (cm)"
set ylabel "Petal Width (cm)"

#ranges
set xrange [0:7]
set yrange [0:2.7]

#3rd degree polynomial function
g(x) = a*x**3+b*x**2+c*x+d

#make graph
fit g(x) "iris.data" using 3:4 via a,b,c,d
plot g(x) linecolor 7 notitle, "iris.data" using 3:4 with point pointtype 6 linecolor 14 notitle