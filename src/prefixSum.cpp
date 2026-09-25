#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#define n  1000000
#define nTwo 10000000
#define nThree 100000000

template <typename T>
T prefixSum(std::vector<T>& a) {
    T sum = 0;

    for (size_t i = 0; i < a.size(); i++) {
        T current = a[i];
        a[i] = sum;
        sum += current;
    }
    return sum;
}
template <typename T>
void randomFill(std::vector<T>& a){
    for(size_t i = 0; i < a.size(); i++){
        a[i] = rand();
    }

}
template<typename T>
std::vector<double> timer(std::vector<T>& a){
    T result;
    std::vector<double> timeList; 
    struct timespec start, stop;

    std::vector<T> copy = a;
    result = prefixSum(a);
    a = copy;

    for (int i = 0; i <10; i++){
        clock_gettime(CLOCK_MONOTONIC, &start);
        result = prefixSum(a);
        clock_gettime(CLOCK_MONOTONIC, &stop);
        a=copy;
        timeList.push_back((stop.tv_sec - start.tv_sec) 
        + (double)(stop.tv_nsec - start.tv_nsec) / 1000000000.0);
    }
    std::cout << "Result: " << result << std::endl;
    return timeList;

}
template<typename T>
double average(std::vector<T>& a){
    //need timelist
    double avg = 0.0; 
    for(int i = 0; i<a.size(); i++){
        avg = a[i]+avg;
    }
    avg = avg/a.size();
    return avg;
}
template<typename T>
double median(std::vector<T> a){
    return (a[4] + a[5]) / 2.0;
}
template<typename T>
void report(std::vector<double>& timeList, std::string type, int size){
    double avg = average(timeList);

    std::sort(timeList.begin(), timeList.end());
    double rate = size / avg;
    double med = median(timeList);
    double max = *std::max_element(timeList.begin(), timeList.end());
    double min = *std::min_element(timeList.begin(), timeList.end());

    std::cout << "Report of " << type << ", n = "<<size << std::endl;
    std::cout << "Rate: " << rate << " elements/s" << std::endl;
    std::cout << "Average: " << avg << " s"
              << " Median: " << med << " s"
              << " Min: " << min << " s"
              << " Max: " << max << " s"
              << std::endl;

}


int main(){
    //int and double arrays to be passed to prefixSum()
    std::vector<int> a(n); 
    std::vector<int> b(nTwo);
    std::vector<int> c(nThree);
    std::vector<double> aDouble(n);
    std::vector<double> bDouble(nTwo);
    std::vector<double> cDouble(nThree);

    //elapsed time, rate, average, max, min, median of random filled integers
    randomFill(a);
    std::vector<double> timeLista = timer(a);
    report<int>(timeLista, "int", n);
    randomFill(b);
    std::vector<double> timeListb = timer(b);
    report<int>(timeListb, "int", nTwo);
    randomFill(c);
    std::vector<double> timeListc = timer(c);
    report<int>(timeListc, "int", nThree);

    //elapsed time, rate, average, max, min, median of random double integers
    randomFill(aDouble);
    std::vector<double> timeListaDouble = timer(aDouble);
    report<double>(timeListaDouble, "double", n);
    randomFill(bDouble);
    std::vector<double> timeListbDouble = timer(bDouble);
    report<double>(timeListbDouble, "double", nTwo);
    randomFill(cDouble);
    std::vector<double> timeListcDouble = timer(cDouble);
    report<double>(timeListcDouble, "double", nThree);
    
}