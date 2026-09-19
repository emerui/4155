#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#define n  1000000
#define nTwo 10000000
#define nThree 100000000

void mergeA(std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c){
    int p = b.size();
    int q = c.size();
    int i = 0;
    int j = 0;
    int k = 0;

    while(i<p && j<q){
        if(b[i]<= c[j]){
            a[k] = b[i];
            i++;
        }
        else{
            a[k] = c[j];
            j++;
        }
        k++;
    }

    if(i==p){
       while(j<q){
        a[k]=c[j];
        k++;
        j++;
       } 
    }
    else{
        while(i<p){
            a[k]=b[i];
            k++;
            i++;
        }
    }
}
void mergeSortA(std::vector<int>& a){
    int size = a.size();
    if (size > 1){
        int mid = size/2;
        std::vector<int> b(a.begin(), a.begin()+mid);
        std::vector<int> c(a.begin()+mid, a.end());
        mergeSortA(b);
        mergeSortA(c);
        mergeA(a, b, c);
    }
}

void mergeB (std::vector<int>& a, std::vector<int>& temporary, int left, int mid, int right){
    for (int i = left; i <= right; i++){
        temporary[i] = a[i];
    }
    int i = left;
    int j = mid+1;
    int k = left;
    while(i<=mid && j<=right){
        if(temporary[i]<=temporary[j]){
            a[k] = temporary[i];
            k++;
            i++;
        }
        else{
            a[k]=temporary[j];
            k++;
            j++;
        }
    }
    while(i<= mid){
        a[k] = temporary[i];
        k++;
        i++;
    }
}
void buffer (std::vector<int>& a, std::vector<int>& temp, int left, int right){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;
    buffer(a, temp, left, mid);
    buffer(a,temp, mid+1, right);
    mergeB(a, temp, left, mid, right);
}
void mergeSortB(std::vector<int>& a){
    std::vector<int> temporary(a.size());
    buffer(a, temporary, 0, a.size()-1);
    
}

void stdSort(std::vector<int>& a){
    std::sort(a.begin(), a.end());
}

void randomFill(std::vector<int>& a){
    for(int i = 0; i < a.size(); i++){
        a[i] = rand();
    }

}
std::vector<double> timer(std::vector<int>& a, void (*func)(std::vector<int>&)){
    std::vector<int> result = a;
    std::vector<double> timeList; 
    struct timespec start, stop;
    long sum = 0;

    func(result);
    bool verify = std::is_sorted(result.begin(), result.end());
    int ogSum = 0; 
    int sortSum = 0;
    for (int i = 0; i < a.size(); i++) {
        ogSum += a[i];
        sortSum += result[i];
    }
    if (!verify || ogSum != sortSum) {
        std::cout << "You're cooked :/" << std::endl;
    }



    for (int i = 0; i <10; i++){
        std::vector<int> reset = a;
        clock_gettime(CLOCK_MONOTONIC, &start);
        func(reset);
        clock_gettime(CLOCK_MONOTONIC, &stop);
        sum = reset[0] + sum;
        timeList.push_back((stop.tv_sec - start.tv_sec) 
        + (double)(stop.tv_nsec - start.tv_nsec) / 1000000000.0);
    }
    result = a;
    std::cout << "Result: " << sum << std::endl;
    return timeList;

}
double average(std::vector<double>& a){
    double avg = 0.0; 
    for(int i = 0; i<a.size(); i++){
        avg = a[i]+avg;
    }
    avg = avg/a.size();
    return avg;
}
double median(std::vector<double> a){
    return (a[4] + a[5]) / 2.0;
}
void report(std::vector<double>& timeList, std::string merge,std::string input, int size){
    double avg = average(timeList);

    std::sort(timeList.begin(), timeList.end());

    double med = median(timeList);
    double max = *std::max_element(timeList.begin(), timeList.end());
    double min = *std::min_element(timeList.begin(), timeList.end());

    double rate = size / avg;

    std::cout << "Report of "  <<input << " merge sort " <<merge <<", matrix size = "<< size << std::endl;
    std::cout << "Rate: " << rate << " elements/s" << std::endl;
    std::cout << "Average: " << avg << " s"
              << " Median: " << med << " s"
              << " Min: " << min << " s"
              << " Max: " << max << " s"
              << std::endl;

}

int main(){
    std::vector<int> a(n); 
    std::vector<int> b(nTwo);
    std::vector<int> c(nThree);

    //elapsed time, rate, average, max, min, median of random filled mergeSortA
    randomFill(a);
    std::vector<double> timeLista = timer(a, mergeSortA);
    std::vector<double> timeListaSorted = timer(a, stdSort);
    report(timeLista, "random", "A", n);
    report(timeListaSorted,"", "std::sort", n);

    randomFill(b);
    std::vector<double> timeListb = timer(b, mergeSortA);
    std::vector<double> timeListbSorted = timer(b, stdSort);
    report(timeListb, "random", "A", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    randomFill(c);
    std::vector<double> timeListc = timer(c, mergeSortA);
    std::vector<double> timeListcSorted = timer(c, stdSort);
    report(timeListc, "random","A", nThree);
    report(timeListcSorted,"", "std::sort", nThree);

    //elapsed time, rate, average, max, min, median of random filled mergeSortB
    timeLista = timer(a, mergeSortB);
    report(timeLista, "random","B", n);
    report(timeListaSorted,"", "std::sort", n);

    timeListb = timer(b, mergeSortB);
    report(timeListb, "random","B", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    timeListc = timer(c, mergeSortB);
    report(timeListc, "random","B", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of sorted mergeSortA
    randomFill(a);
    std::sort(a.begin(), a.end());
    timeLista = timer(a, mergeSortA);
    timeListaSorted = timer(a, stdSort);
    report(timeLista, "sorted","A", n);
    report(timeListaSorted, "","std::sort", n);

    randomFill(b);
    std::sort(b.begin(), b.end());
    timeListb = timer(b, mergeSortA);
    timeListbSorted = timer(b, stdSort);
    report(timeListb, "sorted","A", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    randomFill(c);
    std::sort(c.begin(), c.end());
    timeListc = timer(c, mergeSortA);
    timeListcSorted = timer(c, stdSort);
    report(timeListc, "sorted","A", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of sorted filled mergeSortB
    timeLista = timer(a, mergeSortB);
    report(timeLista, "sorted","B", n);
    report(timeListaSorted, "","std::sort", n);

    timeListb = timer(b, mergeSortB);
    report(timeListb, "sorted","B", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    timeListc = timer(c, mergeSortB);
    report(timeListc,"sorted", "B", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of reverse sort mergeSortA
    randomFill(a);
    std::sort(a.begin(), a.end(), std::greater<int>());    
    timeLista = timer(a, mergeSortA);
    timeListaSorted = timer(a, stdSort);
    report(timeLista, "reverse-sort","A", n);
    report(timeListaSorted, "","std::sort", n);

    randomFill(b);
    std::sort(b.begin(), b.end(), std::greater<int>());    
    timeListb = timer(b, mergeSortA);
    timeListbSorted = timer(b, stdSort);
    report(timeListb, "reverse-sort","A", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    randomFill(c);
    std::sort(c.begin(), c.end(), std::greater<int>());    
    timeListc = timer(c, mergeSortA);
    timeListcSorted = timer(c, stdSort);
    report(timeListc, "reverse-sort","A", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of reverse sort filled mergeSortB
    timeLista = timer(a, mergeSortB);
    report(timeLista, "reverse-sort","B", n);
    report(timeListaSorted, "","std::sort", n);

    timeListb = timer(b, mergeSortB);
    report(timeListb, "reverse-sort","B", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    timeListc = timer(c, mergeSortB);
    report(timeListc,"reverse-sort", "B", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of all elements equal sort mergeSortA
    std::fill(a.begin(), a.end(), 36);   
    timeLista = timer(a, mergeSortA);
    timeListaSorted = timer(a, stdSort);
    report(timeLista, "AEE","A", n);
    report(timeListaSorted, "","std::sort", n);

    std::fill(b.begin(), b.end(), 36);   
    timeListb = timer(b, mergeSortA);
    timeListbSorted = timer(b, stdSort);
    report(timeListb, "AEE","A", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    std::fill(c.begin(), c.end(), 36);       
    timeListc = timer(c, mergeSortA);
    timeListcSorted = timer(c, stdSort);
    report(timeListc, "AEE","A", nThree);
    report(timeListcSorted, "","std::sort", nThree);

    //elapsed time, rate, average, max, min, median of AEE filled mergeSortB
    timeLista = timer(a, mergeSortB);
    report(timeLista, "AEE","B", n);
    report(timeListaSorted, "","std::sort", n);

    timeListb = timer(b, mergeSortB);
    report(timeListb, "AEE","B", nTwo);
    report(timeListbSorted, "","std::sort", nTwo);

    timeListc = timer(c, mergeSortB);
    report(timeListc,"AEE", "B", nThree);
    report(timeListcSorted, "","std::sort", nThree);

}