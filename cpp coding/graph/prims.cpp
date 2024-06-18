#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
int main(){
    int n,e,i,a,b,cost;
    cout<<"Enter the number of vetices";
    cin>>n;
    vector<pair<int,int>>adj[n];
    cout<<"Enter the number of edges";
    cin>>e;
    for(i=1;i<=e;i++){
        cout<<"enter the endpoints followed by cost"<<i<<": ";
        cin>>a>>b>>cost;
        adj[a].push_back({b, cost}); 
        adj[b].push_back({a, cost});
        

    }
    for(i=0;i<n;i++){
        int j=0;
        cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<"("<<adj[i][j].first<<",";
            cout<<adj[i][j].second<<"), ";
        }
        cout<<endl;

    }
    vector<int>inmst(n,0);
    vector<int>key(n,INT_MAX);
    vector<int>predecessor(n,-1);
    key[0]=0;

    priority_queue< ipair,vector<ipair>,greater<ipair> > pq;
    pq.push({0,0});
    for(i=1;i<=n-1;i++){
        pair<int,int>x=pq.top();
        pq.pop();

        int v=x.second;
        inmst[v]=1;
        for(int j=0;j<adj[v].size();j++){
            int vertex=adj[v][j].first;
            int weight =adj[v][j].second;
            if(inmst[vertex]==0 && key[vertex]>weight){
                key[vertex]=weight;
                predecessor[vertex]=v;
                pq.push({key[vertex],vertex});
            }
        }

    }
    cout<<"MST IS"<<endl;
    cout<<"vertex key "<<" Predecessor "<<endl;
    for(i=0;i<n;i++){
        cout<<i<<"\t";
        cout<<key[i]<<"\t";
        cout<<predecessor[i];
        cout<<endl;
    }
}