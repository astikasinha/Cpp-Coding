/* arr[] = {15, 4, 15}
Output : 0
Array is already a palindrome. So we
do not need any merge operation.
Input : arr[] = {1, 4, 5, 1}
Output : 1
We can make given array palindrome with
minimum one merging (merging 4 and 5 to
make 9)
Input : arr[] = {11, 14, 15, 99}
Output : 3
We need to merge all elements to make
a palindrome.*/

#include<bits/stdc++.h>
using namespace std;
int mergeoperations(int arr[],int n){
    int c=0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else if(arr[i]<arr[j]){
            arr[i]=arr[i]+arr[i+1];
            c++;
            i++;

        }
        else{
            arr[j]=arr[j]+arr[j-1];
            c++;
            j--;
        }
    }
    return c;
}
int main(){
    int n;
    cout<<"Enter the number of elements in array";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergeoperations(arr,n);
}
