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
    e=clock();
    cout<<"\n"<<sum<<endl;
    cout<<e-s<<endl;
    return 0;
}
