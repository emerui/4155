#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#define n  1000000
#define nTwo 10000000
#define nThree 100000000

template <typename T>
T maxArrayA(const std::vector<T>& a){
    T m = a[0];
    for(int i = 1; i<a.size();i++){
        if (a[i]>m){
            m=a[i];
        }
    }
    return m;
}
template <typename T>
T maxArrayB(const std::vector<T>& a){
    T m = a[0];
    for(int i = 1; i<a.size();i++){
        m = (a[i]>m) ? a[i]:m; 
    }
    return m;
}

template <typename T>
void randomSort(std::vector<T>& a){
    for(int i = 0; i < a.size(); i++){
        a[i] = rand();
    }

}

template<typename T>
std::vector<double> timer(std::vector<T>& a, T (*func)(const std::vector<T> &)){
    T result;
    std::vector<double> timeList; 
    struct timespec start, stop;

    result = func(a);

    for (int i = 0; i <10; i++){
        clock_gettime(CLOCK_MONOTONIC, &start);
        result = func(a);
        clock_gettime(CLOCK_MONOTONIC, &stop);
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

void updateCSV(std::string input, std::string type, std::string version, int numb, double rate){
    std::ofstream fin;
    fin.open("../data/arrayMax.csv", std::ios_base::app);
    fin << input<< "," << type << "," << version << "," << numb << "," << rate << std::endl;
}
template<typename T>
void report(std::vector<double>& timeList, std::string inputSort, std::string type, std::string version, int size){
    double avg = average(timeList);

    std::sort(timeList.begin(), timeList.end());

    double med = median(timeList);
    double max = maxArrayA(timeList);
    double min = *std::min_element(timeList.begin(), timeList.end());

    double rate = (size * sizeof(T)) / avg;

    std::cout << "Report of " << inputSort << " sort "<< type <<" loop "<< version << ", n = "<<size << std::endl;
    std::cout << "Rate: " << rate << " bytes/s" << std::endl;
    std::cout << "Average: " << avg << " s"
              << " Median: " << med << " s"
              << " Min: " << min << " s"
              << " Max: " << max << " s"
              << std::endl;

    updateCSV(inputSort, type, version, size, rate);
}



int main(){
    //restart CSV file each time code is ran
    std::ofstream fout("../data/arrayMax.csv");
    fout << "inputSort,type,loopVersion,nSize,rate\n";
    fout.close();

    //int and double arrays to be passed to maxArrayA() or B()
    std::vector<int> a(n); 
    std::vector<int> b(nTwo);
    std::vector<int> c(nThree);
    std::vector<double> aDouble(n);
    std::vector<double> bDouble(nTwo);
    std::vector<double> cDouble(nThree);

    //elapsed time, rate, average, max, min, median of random filled integers with inner loop a
    randomSort(a);
    std::vector<double> timeLista = timer(a, maxArrayA);
    report<int>(timeLista, "random", "int", "A", n);
    randomSort(b);
    std::vector<double> timeListb = timer(b, maxArrayA);
    report<int>(timeListb,"random", "int", "A", nTwo);
    randomSort(c);
    std::vector<double> timeListc = timer(c, maxArrayA);
    report<int>(timeListc,"random", "int", "A", nThree);

    //elapsed time, rate, average, max, min, median of random filled doubles with inner loop a
    randomSort(aDouble);
    std::vector<double> timeListaDouble = timer(aDouble, maxArrayA);
    report<int>(timeListaDouble, "random", "double", "A", n);
    randomSort(bDouble);
    std::vector<double> timeListbDouble = timer(bDouble, maxArrayA);
    report<int>(timeListbDouble, "random", "double", "A", nTwo);
    randomSort(cDouble);
    std::vector<double> timeListcDouble = timer(cDouble, maxArrayA);
    report<int>(timeListcDouble, "random", "double", "A", nThree);


    //report of random filled ints with inner loop B
    timeLista = timer(a, maxArrayB);
    report<int>(timeLista, "random", "int", "B", n);
    timeListb = timer(b, maxArrayB);
    report<int>(timeListb,"random", "int", "B", nTwo);
    timeListc = timer(c, maxArrayB);
    report<int>(timeListc, "random", "int", "B", nThree);

    //report of random filled doubles with inner loop B
    timeListaDouble = timer(aDouble, maxArrayB);
    report<double>(timeListaDouble, "random", "double", "B", n);
    timeListbDouble = timer(bDouble, maxArrayB);
    report<double>(timeListbDouble, "random", "double", "B", nTwo);
    timeListcDouble = timer(cDouble, maxArrayB);
    report<double>(timeListcDouble, "random", "double", "B", nThree);
    
    // report of increasing sort int with inner loop A
    std::sort(a.begin(), a.end());
    timeLista = timer(a, maxArrayA);
    report<int>(timeLista, "increasing", "int", "A", n);
    std::sort(b.begin(), b.end());
    timeListb = timer(b, maxArrayA);
    report<int>(timeListb, "increasing", "int", "A", nTwo);
    std::sort(c.begin(), c.end());
    timeListc = timer(c, maxArrayA);
    report<int>(timeListc, "increasing", "int", "A", nThree);

    // report reverse sort int with inner loop A
    std::sort(a.begin(), a.end(), std::greater<int>());    
    timeLista = timer(a, maxArrayA);
    report<int>(timeLista,"reverse", "int", "A", n);
    std::sort(b.begin(), b.end(), std::greater<int>());
    timeListb = timer(b, maxArrayA);
    report<int>(timeListb,"reverse", "int", "A", nTwo);
    std::sort(c.begin(), c.end(), std::greater<int>());
    timeListc = timer(c, maxArrayA);
    report<int>(timeListc, "reverse", "int", "A", nThree);

    //report reverse sort double with inner loop A
    std::sort(aDouble.begin(), aDouble.end(), std::greater<double>());
    timeListaDouble = timer(aDouble, maxArrayA);
    report<double>(timeListaDouble, "reverse", "double", "A", n);
    std::sort(bDouble.begin(), bDouble.end(), std::greater<double>());
    timeListbDouble = timer(bDouble, maxArrayA);
    report<double>(timeListbDouble, "reverse", "double", "A", nTwo);
    std::sort(cDouble.begin(), cDouble.end(), std::greater<double>());
    timeListcDouble = timer(cDouble, maxArrayA);
    report<double>(timeListcDouble, "reverse", "double", "A", nThree);

    //report increase sort double with inner loop A
    std::sort(aDouble.begin(), aDouble.end());
    timeListaDouble = timer(aDouble, maxArrayA);
    report<double>(timeListaDouble, "increasing", "double", "A", n);
    std::sort(bDouble.begin(), bDouble.end());
    timeListbDouble = timer(bDouble, maxArrayA);
    report<double>(timeListbDouble, "increasing", "double", "A", nTwo);
    std::sort(cDouble.begin(), cDouble.end());
    timeListcDouble = timer(cDouble, maxArrayA);
    report<double>(timeListcDouble, "increasing", "double", "A", nThree);

    
    // report of increasing sort int with inner loop B
    std::sort(a.begin(), a.end());
    timeLista = timer(a, maxArrayB);
    report<int>(timeLista, "increasing", "int", "B", n);
    std::sort(b.begin(), b.end());
    timeListb = timer(b, maxArrayB);
    report<int>(timeListb, "increasing", "int", "B", nTwo);
    std::sort(c.begin(), c.end());
    timeListc = timer(c, maxArrayB);
    report<int>(timeListc, "increasing", "int", "B", nThree);

    // report reverse sort int with inner loop B
    std::sort(a.begin(), a.end(), std::greater<int>());    
    timeLista = timer(a, maxArrayB);
    report<int>(timeLista, "reverse", "int", "B", n);
    std::sort(b.begin(), b.end(), std::greater<int>());
    timeListb = timer(b, maxArrayB);
    report<int>(timeListb, "reverse", "int", "B", nTwo);
    std::sort(c.begin(), c.end(), std::greater<int>());
    timeListc = timer(c, maxArrayB);
    report<int>(timeListc, "reverse", "int", "B", nThree);

    //report increase sort double with inner loop B
    std::sort(aDouble.begin(), aDouble.end());
    timeListaDouble = timer(aDouble, maxArrayB);
    report<double>(timeListaDouble, "increasing", "double", "B", n);
    std::sort(bDouble.begin(), bDouble.end());
    timeListbDouble = timer(bDouble, maxArrayB);
    report<double>(timeListbDouble, "increasing", "double", "B", nTwo);
    std::sort(cDouble.begin(), cDouble.end());
    timeListcDouble = timer(cDouble, maxArrayB);
    report<double>(timeListcDouble, "increasing", "double", "B", nThree);


    //report reverse sort double with inner loop B
    std::sort(aDouble.begin(), aDouble.end(), std::greater<double>());
    timeListaDouble = timer(aDouble, maxArrayB);
    report<double>(timeListaDouble, "reverse", "double", "B", n);
    std::sort(bDouble.begin(), bDouble.end(), std::greater<double>());
    timeListbDouble = timer(bDouble, maxArrayB);
    report<double>(timeListbDouble, "reverse", "double", "B", nTwo);
    std::sort(cDouble.begin(), cDouble.end(), std::greater<double>());
    timeListcDouble = timer(cDouble, maxArrayB);
    report<double>(timeListcDouble, "reverse", "double", "B", nThree);


    //4.1
    int kb = 256;
    std::vector<double> bandwidth;
    double avgBandwidth;
    while (kb <= 33554432){
        std::vector<double>doubleB(kb);
        std::vector<double>timeList = timer(doubleB, maxArrayB);
        avgBandwidth = (kb*sizeof(double))/average(timeList);
        bandwidth.push_back(avgBandwidth);
        updateCSV("bandwidth","double","B",kb,avgBandwidth);

        kb*=2;
    }

    


    return 0;
}