#include<bits/stdc++.h>
using namespace std;
#define N 3
int minimum(int amount[]){
    int m=0;
    for(int i=1;i<N;i++){
        if(amount[i]<amount[m]){
            m=i;
        }

    }
    return m;
}
int maximum(int amount[]){
    int m=0;
    for(int i=1;i<N;i++){
        if(amount[i]>amount[m]){
            m=i;
        }
    }
    return m;
}
int minimumof2(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}
void mincashflow(int amount[]){
    int mxdebit=minimum(amount);
    int mxcredit=maximum(amount);
    if(amount[mxcredit]==0 && amount[mxdebit]==0){
        return;
    }
    int minof2=minimumof2(-amount[mxdebit],amount[mxcredit]);
    amount[mxcredit]=amount[mxcredit]-minof2;
    amount[mxdebit]=amount[mxdebit]+minof2;
    cout<<"Person "<<mxdebit<<" pays "<<minof2<<" to person "<<mxcredit<<endl;
    mincashflow(amount);
}
void mincash(int graph[][N]){
    int amount[N]={0};
    for(int p=0;p<N;p++){
        for(int i=0;i<N;i++){
            amount[p]=amount[p]+(graph[i][p]-graph[p][i]);
        }
    }
    mincashflow(amount);
}
int main(){
    int graph[N][N] = {
        { 0, 1000, 2000 },
        { 0, 0, 5000 },
        { 0, 0, 0 },
    };
    mincash(graph);
}