#include<bits/stdc++.h>
using namespace std;
void egyptianfraction(int n,int d){
    if(n==0||d==0){
        return;
    }
    if(n%d==0){
        cout<<"1/"<<n/d;
    }
    if(d%n==0){
        cout<<"1/"<<d/n;
    }
    if(n>d){
        cout<<n/d;
        egyptianfraction(n%d,d);
    }
    int x=d/n +1;
    cout<<"1/"<<x;
    egyptianfraction(x*n-d,d*x);

}
int main(){
    int n,d;
    cout<<"Enter the numerator"<<" ";
    cin>>n;
    cout<<"Enter the denominator"<<" ";
    cin>>d;
    egyptianfraction(n,d);

}