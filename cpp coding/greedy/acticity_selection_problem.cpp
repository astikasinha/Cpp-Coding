/*You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time. 

Examples:  

Input: start[]  =  {10, 12, 20}, finish[] =  {20, 25, 30}
Output: 0
Explanation: A person can perform at most one activities.

Input: start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
Output: 0 1 3 4
Explanation: A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and finish[]*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct activity{
    int start,finish;
};
bool activitycompare(activity s1,activity s2){
    return (s1.finish<s2.finish);
}
int maxactivities(int s[],int f[],int n){
    int i=0;
    sort(f,f+n,activitycompare);
    cout<<s[i]<<" ";
    for(int j=1;j<n;j++){
        if(s[j]>=f[i]){
            cout<<s[j]<<" ";
            i=j;
        }
    }

}
int main(){
    int n;
    cout<<"Enter the number of activities"<<" ";
    cin>>n;
    int s[n],f[n];
    cout<<"Enter the start time of activities"<<" ";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"Enter the finish time of activities"<<" ";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    maxactivities(s,f,n);

}