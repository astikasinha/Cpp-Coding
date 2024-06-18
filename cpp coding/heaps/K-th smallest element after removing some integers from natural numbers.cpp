#include<bits/stdc++.h>
/*Input : arr[] = { 1 } and k = 1.
Output: 2
Natural numbers are {1, 2, 3, 4, .... }
After removing {1}, we get {2, 3, 4, ...}.
Now, K-th smallest element = 2.
Input : arr[] = {1, 3}, k = 4.
Output : 6
First 5 Natural number {1, 2, 3, 4, 5, 6,  .. }
After removing {1, 3}, we get {2, 4, 5, 6, ... }.*/
#define MAX 1000000
using namespace std;
int ksmallest( vector<int>& arr,int n,int k){
    vector<int> b(MAX, 0);

    for(int i=0;i<n;i++){
        b[arr[i]]=1;
    }
    for(int i=1;i<MAX;i++){
        if(b[i]!=1){
            k--;
        }
        if(k==0){
            return i;
        }
    }

}
int main(){
    int n,k;
    cout<<"Enter the number of elements in array";
    cin>>n;
    cout<<"Enter the elements in array";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of K";
    cin>>k;
    cout<<ksmallest(arr,n,k);
}