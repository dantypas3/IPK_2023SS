#!/bin/bash
# uses gnuplot to visualize the runntime of the different programms

# get compile and run times for different k's
g++ iter_fibonacci.cc -o main.o
for i in {1..60..1}
do
    echo -n "$i " >> iter_run.txt
    ./main.o $i >> iter_run.txt
done

g++ iter_fibonacci_64.cc -o main.o
for i in {1..60..1}
do
    echo -n "$i " >> iter64_run.txt
    ./main.o $i >> iter64_run.txt
done

# plot the times with gnuplot
gnuplot <<- EOF
        set style line 1 \
            linecolor rgb '#0060ad' \
            linetype 1 linewidth 2
        set style line 2 \
            linecolor rgb '#dd181f' \
            linetype 1 linewidth 2

        set xlabel "Fibonacci Index"
        set ylabel "Fibonacci Number"
        set title "Values"   
        set term png
        set output "values_32.png"
        plot "iter_run.txt" title "int32" with linespoints linestyle 1
EOF

gnuplot <<- EOF
        set style line 1 \
            linecolor rgb '#0060ad' \
            linetype 1 linewidth 2
        set style line 2 \
            linecolor rgb '#dd181f' \
            linetype 1 linewidth 2

        set xlabel "Fibonacci Index"
        set ylabel "Fibonacci Number"
        set title "Values"   
        set term png
        set output "values_64.png"
        plot "iter64_run.txt" title "int64" with linespoints linestyle 2
EOF

# cleanup files
rm main.o
rm ./iter_run.txt
rm ./iter64_run.txt
