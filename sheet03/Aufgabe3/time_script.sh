#!/bin/bash
# uses gnuplot to visualize the runntime of the different programms

# get compile and run times for different k's
g++ iter_fibonacci.cc -o main.o
for i in {5..45..5}
do
    echo "for INDEX = $i"
    echo -n "$i " >> iter_run.txt
    \time -f "%e" -a -o iter_run.txt ./main.o $i
    echo " "
done

g++ rec_fibonacci.cc -o main.o
for i in {5..45..5}
do
    echo "for INDEX = $i"
    echo -n "$i " >> rec_run.txt
    \time -f "%e" -a -o rec_run.txt ./main.o $i
    echo " "
done

# output times to the console
echo "running times"
cat iter_run.txt
echo " "
cat rec_run.txt

# plot the times with gnuplot
gnuplot <<- EOF
        set style line 1 \
            linecolor rgb '#0060ad' \
            linetype 1 linewidth 2 \
            pointtype 7 pointsize 1
        set style line 2 \
            linecolor rgb '#dd181f' \
            linetype 1 linewidth 2 \
            pointtype 5 pointsize 1

        set xlabel "Fibonacci Number"
        set ylabel "Time in seconds"
        set title "Timing"   
        set term png
        set output "times.png"
        plot "iter_run.txt" title "iterative" with linespoints linestyle 1, \
             "rec_run.txt" title "recursive" with linespoints linestyle 2
EOF

# cleanup files
rm main.o
rm ./iter_run.txt
rm ./rec_run.txt
