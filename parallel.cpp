#include<omp.h>
#include<iostream>
#include<cstdlib>
#include<time.h>
clock_t s,e;
using namespace std;
int main(){
    int n=1e+5;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
        // printf("%d ",arr[i]);
    }
    int sum=0;
    s=clock();
    #pragma omp parallel for reduction(+:sum)
        for(int i=0;i<n;i++){
        sum=sum+arr[i];//reduction occurs
    }
    // SPMD code
    // #pragma omp parallel
    // {
    //     int i,tempSum;
    //     int nThrd =omp_get_num_threads();
    //     int id=omp_get_thread_num();
    //     for(i=id,tempSum=0;i<n;i+=nThrd){
    //         tempSum+=arr[i];
    //     }
    //     #pragma omp critical
    //     sum+=tempSum;
    // }
    
    e=clock();
    cout<<"\n"<<sum<<endl;
    cout<<e-s<<endl;
    return 0;
}
