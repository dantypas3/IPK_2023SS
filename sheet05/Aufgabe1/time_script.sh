#!/bin/bash
# uses gnuplot to visualize the runntime of the different programms

# get compile and run times for different k's
for i in {0..10000000..1000000}
do
    echo "for INDEX = $i"
    echo -n "$i " >> build_run.txt
    \time -f "%e" -a -o build_run.txt ./build/normal.out $i
    echo " "
done

for i in {0..10000000..1000000}
do
    echo "for INDEX = $i"
    echo -n "$i " >> release_run.txt
    \time -f "%e" -a -o release_run.txt ./build-release/normal.out $i
    echo " "
done


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

        set xlabel "vector length"
        set ylabel "time in seconds"
        set title "run time"   
        set term png
        set output "times.png"
        plot "build_run.txt" title "normal" with linespoints linestyle 1, \
             "release_run.txt" title "release" with linespoints linestyle 2
EOF

# cleanup files
rm ./build_run.txt
rm ./release_run.txt
