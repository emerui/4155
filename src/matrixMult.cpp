#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

void fillMatrix(std::vector<int>& a, int M, int N){
    for (int i = 0; i<M*N; i++){
        a[i] = rand() % 101 + 1;
    }

}
void printMatrix(std::vector<int>& a, int M, int N, std::string loop){
    std::cout<< loop<<" loop:"<<std::endl;
    for (int i = 0; i<M*N; i++){
        std::cout<<a[i]<<std::endl;
    }

}

std::vector<int>& loopIJK(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for (int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            int sum = 0;
            for (int k = 0; k<K; k++){
                sum = a[i * K + k] * b[k * N + j] + sum;
            }
            c[i * N + j]= sum; 
            sum = 0;
        }
    }
    return c;

}
std::vector<int>& loopIKJ(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for (int i = 0; i<M; i++){
        for(int k=0; k<K; k++){
            for (int j = 0; j<N; j++){
                c[i * N + j] = a[i * K + k] * b[k * N + j] + c[i * N +j];            
            }
        }
    }
    return c;

}
std::vector<int>& loopJIK(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for(int j = 0; j<N; j++){
        for (int i = 0; i<M; i++){
            int sum = 0;
            for(int k=0; k<K; k++){
                sum = a[i * K + k] * b[k * N + j] + sum;            
            }
            c[i * N + j]= sum; 
            sum = 0;
        }
    }
    return c;

}
std::vector<int>& loopJKI(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for(int j = 0; j<N; j++){
        for (int k=0; k<K; k++){
            for(int i = 0; i<M; i++){
                c[i * N + j] = a[i * K + k] * b[k * N + j] + c[i * N +j];            
            }
        }
    }
    return c;

}
std::vector<int>& loopKIJ(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for (int k=0; k<K; k++){
        for(int i = 0; i<M; i++){
            for (int j = 0; j<N; j++){
                c[i * N + j] = a[i * K + k] * b[k * N + j] + c[i * N +j];            
            }
        }
    }
    return c;

}
std::vector<int>& loopKJI(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, int M, int K, int N){
    for (int k=0; k<K; k++){
        for(int j = 0 ; j<N; j++){
            for (int i = 0; i<M; i++){
                c[i * N + j] = a[i * K + k] * b[k * N + j] + c[i * N + j];            
            }
        }
    }
    return c; 

}


std::vector<double> timer(std::vector<int>& a, std::vector<int>& b, std::vector<int> &c, int M, int K, int N, std::vector<int>& (*func)(const std::vector<int>& , const std::vector<int>& , std::vector<int>&, int , int , int)){
    std::vector<double> timeList; 
    struct timespec start, stop;

    std::fill(c.begin(), c.end(), 0);
    std::vector<int>& result = func(a, b, c, M, K, N);

    for (int i = 0; i <10; i++){
        std::fill(c.begin(), c.end(), 0);
        clock_gettime(CLOCK_MONOTONIC, &start);
        result = func(a, b, c, M, K, N);
        clock_gettime(CLOCK_MONOTONIC, &stop);
        timeList.push_back((stop.tv_sec - start.tv_sec) 
        + (double)(stop.tv_nsec - start.tv_nsec) / 1000000000.0);
    }
    std::cout << "Result: " << result[0] << std::endl;
    return timeList;

}

void updateCSV(std::string version, std::string MKN, double rate){
    std::ofstream fin;
    fin.open("../data/matrixMult.csv", std::ios_base::app);
    fin << version<< "," <<MKN << "," << rate << std::endl;
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
void report(std::vector<double>& timeList, std::string loop, int M, int N, int K){
    double avg = average(timeList);

    std::sort(timeList.begin(), timeList.end());

    double med = median(timeList);
    double max = *std::max_element(timeList.begin(), timeList.end());
    double min = *std::min_element(timeList.begin(), timeList.end());

    double rate = (2.0*M*K*N) / avg;

    std::cout << "Report of "  << loop <<" loop "<< ", matrix size = "<<M << " * " <<N << std::endl;
    std::cout << "Rate: " << rate << " operations/s" << std::endl;
    std::cout << "Average: " << avg << " s"
              << " Median: " << med << " s"
              << " Min: " << min << " s"
              << " Max: " << max << " s"
              << std::endl;

    std::string MKN = std::to_string(M)+"x"+std::to_string(K)+"x"+std::to_string(N);
    updateCSV(loop, MKN, rate);
}

int main(){
    //restart CSV file each time code is ran
    std::ofstream fout("../data/matrixMult.csv");
    fout << "loopVersion,MKN,rate\n";
    fout.close();

    int M = 3;
    int N = 2;
    int K= 4;
    std::vector<int> aMatrix (M*K);
    std::vector<int> bMatrix(K*N);
    std::vector<int> cMatrix(M*N);
    fillMatrix(aMatrix, M, K);
    fillMatrix(bMatrix, K, N);

    //verifying matrix loops all create matrix C
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<int> check = loopIJK(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N, "IJK");
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    check =loopIKJ(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N,"IKJ");
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    check =loopJIK(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N,"JIK");
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    check =loopJKI(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N,"JKI");
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    check =loopKIJ(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N,"KIJ");
    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    check =loopKJI(aMatrix, bMatrix, cMatrix, M, K, N);
    printMatrix(check, M, N,"KJI");

    //MKN = 256
    M = K = N = 256;
    aMatrix.resize(M*K);
    bMatrix.resize(K*N);
    cMatrix.resize(M*N);
    fillMatrix(aMatrix, M, K);
    fillMatrix(bMatrix, K, N);

    std::vector<double> timeListIJK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIJK);
    report(timeListIJK,"IJK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<double> timeListIKJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIKJ);
    report(timeListIKJ,"IKJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<double> timeListJIK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJIK);
    report(timeListJIK,"JIK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<double> timeListJKI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJKI);
    report(timeListJKI,"JKI", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<double> timeListKIJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKIJ);
    report(timeListKIJ,"KIJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    std::vector<double> timeListKJI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKJI);
    report(timeListKJI,"KJI", M, N, K);


    //MKN = 512
    M = K = N = 512;
    aMatrix.resize(M*K);
    bMatrix.resize(K*N);
    cMatrix.resize(M*N);
    fillMatrix(aMatrix, M, K);
    fillMatrix(bMatrix, K, N);

    timeListIJK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIJK);
    report(timeListIJK,"IJK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListIKJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIKJ);
    report(timeListIKJ,"IKJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJIK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJIK);
    report(timeListJIK,"JIK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJKI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJKI);
    report(timeListJKI,"JKI", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKIJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKIJ);
    report(timeListKIJ,"KIJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKJI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKJI);
    report(timeListKJI,"KJI", M, N, K);

    //MKN = 1024
    M = K = N = 1024;
    aMatrix.resize(M*K);
    bMatrix.resize(K*N);
    cMatrix.resize(M*N);
    fillMatrix(aMatrix, M, K);
    fillMatrix(bMatrix, K, N);

    timeListIJK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIJK);
    report(timeListIJK,"IJK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListIKJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIKJ);
    report(timeListIKJ,"IKJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJIK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJIK);
    report(timeListJIK,"JIK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJKI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJKI);
    report(timeListJKI,"JKI", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKIJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKIJ);
    report(timeListKIJ,"KIJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKJI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKJI);
    report(timeListKJI,"KJI", M, N, K);

    //MKN = different values
    M = 256;
    K = 512;
    aMatrix.resize(M*K);
    bMatrix.resize(K*N);
    cMatrix.resize(M*N);
    fillMatrix(aMatrix, M, K);
    fillMatrix(bMatrix, K, N);

    timeListIJK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIJK);
    report(timeListIJK,"IJK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListIKJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopIKJ);
    report(timeListIKJ,"IKJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJIK = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJIK);
    report(timeListJIK,"JIK", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListJKI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopJKI);
    report(timeListJKI,"JKI", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKIJ = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKIJ);
    report(timeListKIJ,"KIJ", M, N, K);

    std::fill(cMatrix.begin(), cMatrix.end(), 0);
    timeListKJI = timer(aMatrix, bMatrix, cMatrix, M, K, N, loopKJI);
    report(timeListKJI,"KJI", M, N, K);

    

}
