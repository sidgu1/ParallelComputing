#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
clock_t s,e;
#define n 400
using namespace std;
bool forwardElimination(vector<vector<double>> &l,vector<vector<double>> &arr){
    s=clock();
    int i,j,k;
    double a;
    for(i=0;i<n;i++){
        
        for(j=i+1;j<n;j++){
                a=arr[j][i]/arr[i][i];
                l[j][i]=a;
                for(k=i;k<n;k++){
                    arr[j][k]-=a*arr[i][k];
                }
            
        }
    }
    e=clock();
    return true;
}
int main()
{
    vector<vector<double>> arr(n);
    vector<vector<double>> l(n);
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) l[i].push_back(1.0);
            else l[i].push_back(0.0);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a=rand()%100;
            arr[i].push_back(a);
        }
    }
    forwardElimination(l,arr);
    cout<<"//////////////\n";
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
    cout<<e-s<<endl;
    return 0;
}