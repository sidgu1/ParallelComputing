#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
clock_t s,e;
#define n 1000
using namespace std;
bool forwardElimination(vector<vector<double>> &l,vector<vector<double>> &arr){
    s=clock();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                double a=arr[j][i]/arr[i][i];
                for(int k=0;k<n;k++){
                    arr[j][k]-=a*arr[i][k];
                    l[j][k]-=a*l[i][k];
                }
            }

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        }
        arr[i][i]=1;
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
            // a=(i+1)*(i+1);
            // cin>>arr[i][j];
            a=rand()%1000;
            arr[i].push_back(a);
        }
    }
    forwardElimination(l,arr);
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
    cout<<"The time taken for sequential pragram is "<<e-s<<endl;
    return 0;
}