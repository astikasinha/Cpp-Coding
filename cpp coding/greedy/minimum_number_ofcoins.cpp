/*Given a value of V Rs and an infinite supply of
 each of the denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000} 
valued coins/notes, The task is to find the minimum number of 
coins and/or notes needed to make the change?

Examples:  

Input: V = 70
Output: 2
Explanation: We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
Explanation: We need a 100 Rs note, a 20 Rs note, and a 1 Rs coin.

*/



#include <bits/stdc++.h>
using namespace std;
void findmincoins(int denominations[],int n,int v){
    sort(denominations,denominations+n);
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        while(v>=denominations[i]){
            v=v-denominations[i];
            ans.push_back(denominations[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}
int main(){
    int n,v;
    cout<<"Enter the number of denominations"<<" ";
    cin>>n;
    int denominations[n];
    cout<<"Enter the denominations"<<" ";
    for(int i=0;i<n;i++){
        cin>>denominations[i];
    }
    cout<<"Enter the amount"<<" ";
    cin>>v;
    findmincoins(denominations,n,v);

}