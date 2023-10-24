#include<iostream>
#include<bits/stdc++.h>
#include<omp.h>
#include<time.h>
#define n 1000
using namespace std;
int forwardElimination(vector<vector<double>> &l,vector<vector<double>> &arr,int x){
    clock_t s,e;
    // int n=arr.size();
    
    int i,j,k;
    double a;
    s=clock();
    #pragma omp parallel for private(j) shared(arr) shared(l) num_threads(x)
    for(i=0;i<n;i++){
        #pragma omp parallel for private(k) shared(arr) shared(l) num_threads(x)
        for(j=0;j<n;j++){
            if(i!=j){
                
                a=arr[j][i]/arr[i][i];
                for(k=0;k<n;k++){

                    arr[j][k]-=a*arr[i][k];
                    l[j][k]-=a*l[i][k];
                }
            }
        }
    }
    #pragma omp parallel for private(j) shared(arr) shared(l) num_threads(x)
    for( i=0;i<n;i++){
        for( j=0;j<n;j++){
            l[i][j]/=arr[i][i];
        }
        arr[i][i]=1;
    }
    e=clock();
    return e-s;
}
int main(int argc, char** argv)
{   
    vector<vector<double>> arr(n);
    vector<vector<double>> l(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) l[i].push_back(1.0);
            else l[i].push_back(0.0);
        }
    }
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // a=(i+1)*(i+1);
            // cin>>arr[i][j];
            a=rand()%10000000;
            arr[i].push_back(a);
        }
    }
    for(int i=2;i<=6;i++){
        cout<<"Time taken for number of threads  "<<i<<" is "<<forwardElimination(l,arr,i)<<endl;
    }
    // cout<<"//////////////\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%f ",arr[i][j]);
    //     }
    //     cout<<endl;
    // }
    // cout<<"//////////////\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%f ",l[i][j]);
    //     }
    //     cout<<endl;
    // }
    // cout<<"//////////////\n";
    return 0;
}