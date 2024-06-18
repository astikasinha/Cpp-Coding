#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of packets";
    cin>>n;
    int arr[n];
    cout<<"Enter the chocolates in each packets"<<" ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of students"<<" ";
    cin>>m;
    sort(arr,arr+n);
    int mini=INT_MAX;
    for(int i=0;i<n-m;i++){
        for(int j=i+m-1;j<n;j++){
            int s=arr[j]-arr[i];
            mini=min(mini,s);
        }
    }
    cout<<"Minimum difference is "<<mini;

}