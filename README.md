Setup for all kernels:
all .cpp files compiled (unless otherwise stated) as 
g++ -std=c++17 -O2 -Wall -Wextra [fileName].cpp -o hello

All .cpp files timed ran a number of 10 repititions


## Part 1 arrayMax.cpp
1. After submitting a job, the follwoing command provides detailed results of arrayMax of every type of test requested:

        grep -A 3 "Report of" slurm-*.out 
- maxArrayA = algorithm search where m=a[i]; occurrs
- maxArrayB = algorithm search where m = (a[i]>m) ? a[i]:m; occurrs
2. I went through an array of either type int or double to find the largest element inside of said array. I originally test on smaller arrays of size 10 and had those print out the results. After I had verified that the results were accurrate, I finalized my methods maxArrayA and maxArrayB. 

The following are reports/comparisons based of assignment instructions:
I will be comparing sizes 10^6, 10^7, and 10^8 for an array with randomly filled integers based on search type maxArrayA and then on serach type maxArrayB. 
maxArrayA:
For n = 10^6, the elapsed time averaged 0.000150618 seconds with a rate of 2.65572 * 10^10 bytes per second.
For n = 10^7, the elapsed time averaged 0.00358162 seconds  with a rate of 1.11681 * 10^10 bytes per second.
For n = 10^8, the elapsed time averaged 0.0406277 seconds with a rate of 9.8455 * 10^9 bytes per second.

maxArrayB:
For n = 10^6, the elapsed time averaged 0.000175718 seconds with a rate of 2.27637 * 10^10 bytes per second.
For n = 10^7, the elapsed time averaged 0.00385774 seconds  with a rate of 1.03688 * 10^10 bytes per second.
For n = 10^8, the elapsed time averaged 0.0410314 seconds with a rate of 9.74863 * 10^9 bytes per second.
The results suggest that as size input increased, the algorithm took longer to complete. As for the algorithm serach versions, it appears that maxArrayB had a slight higher time completion, making it slower than maxArrayA.  

For comparing the running times of the three inputs: sorted, reverse-sorted, and random, I will compare them at n = 10^6 and as the type integer with maxArrayA then maxArrayB. 
maxArrayA:
As stated before, For a random filled list at n = 10^6, the elapsed time averaged 0.000150618 seconds with a rate of 2.65572 * 10^10 bytes per second.
For a sorted list, the elapsed time averaged 0.000150136 seconds with a rate of 2.66425 * 10^10 bytes per second.
For the reverse-sorted list, the elapsed time averaged 0.000150004 seconds with a rate of 2.6666 * 10^10 bytes per second.

maxArrayB:
For a random filled list at n = 10^6, the elapsed time averaged 0.000175718 seconds with a rate of 2.27637 * 10^10 bytes per second.
For a sorted list, the elapsed time averaged 0.000152545 seconds with a rate of 2.62218 * 10^10 bytes per second.
For the reverse-sorted list, the elapsed time averaged 0.000152704 seconds with a rate of 2.61944 * 10^10 bytes per second.
Since the number to search for is randomly generated, the elapsed times for how the list is sorted would have little effect since they all loop through the array in linear time. Once again, maxArrayA runtimes slightly outperformed maxArrayB. 

To compare the times for an int and double array, I will be using size n = 10^6 with a randomly filled array with maxArrayA then maxArrayB.
maxArrayA:
For an integer randomly filled list, the elapsed time averaged 0.000150618 seconds with a rate of 2.65572 * 10^10 bytes per second.
For the double randomly filled list, the elapsed time averaged 0.00109621 seconds with a rate of 3.64894 * 10^9 bytes per second.

maxArrayB:
For an integer randomly filled list, the elapsed time averaged 0.000175718 seconds with a rate of 2.27637 * 10^10 bytes per second.
For the double randomly filled list, the elapsed time averaged 0.00247113 seconds with a rate of 3.23739 * 10^9 bytes per second.

For both search algorithms, it appears that the double filled array timed rates perform at a slower rate with a difference of a power of 10 existing between the two types of arrays. Between the two search algorithms, maxArrayA once again outperformed slightly but both behaved similarly in their comparisons between integer and double. 

To plot the rate, I had the report method write into a CSV file which plot_arrayMax.py uses to visualize four different plots(Random sort, increasing sort, reverse-sort, bandwidth).
L1d cache:                               1.1 MiB (36 instances)
L1i cache:                               1.1 MiB (36 instances)
L2 cache:                                36 MiB (36 instances)
L3 cache:                                49.5 MiB (2 instances)






The plot.py found in /scripts can be ran with the following command: 
    python [fileName].py
