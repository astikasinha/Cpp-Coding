#include<bits/stdc++.h>
using namespace std;
void nextgreaterelement(int arr[],int n){
    stack<int>s;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        while(s.empty()==false && s.top()<arr[i]){
            cout<<"greater element for"<<s.top()<<"is "<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(s.empty()==false){
        cout<<"greater element for"<<s.top()<<"is "<<"-1"<<endl;
        s.pop();
    }


}
int main(){
    int n;
    cout<<"Enter the number of elements in array"<<" ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextgreaterelement(arr,n);
}