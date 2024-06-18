#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct job{
    char jobid;
    int deadline;
    int profit;
};
bool comaprison(job a,job b){
    return a.profit>b.profit;
}
void jobscheduling(job arr,int n){
    int result[n];
    bool slot[n];
    sort(arr,arr+n,comparison);
    for(int i=0;i<n;i++){
        slot[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                result[i]=arr[i].profit;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i]==true){
            cout<<arr[result[i]].id<<" ";
        }
    }

}
int main(){
    job arr[]={{'a',2,78},
    {'a',3,89},
    {'c',1,90}};
    int n;
    cin>>n;

    jobscheduling(arr,n);

}