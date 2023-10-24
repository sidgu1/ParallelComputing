#include<iostream>
#include<stdlib.h>
#include<time.h>
clock_t s,e;
using namespace std;
int main(){
    long long int n=1e+5;
    // cin>>n;
    long long int arr[n];
    long long  int sum=0;
   
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
        // printf("%d ",arr[i]);
    }
    s=clock();
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    e=clock();
    cout<<endl<<sum<<endl;

    cout<<e-s<<endl;
return 0;
}
