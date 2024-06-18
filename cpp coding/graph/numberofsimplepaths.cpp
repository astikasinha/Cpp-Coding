#include<iostream>
#include<vector>
using namespace std;
void prepareadjlist(int n, int m, vector<vector<int>>& adjlist){
    adjlist.resize(n+1); 
    int u, v;
    for(int i=0; i<m; i++){
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v; 
        adjlist[u].push_back(v); 
        adjlist[v].push_back(u); 
    }
}
void printadjlist(int n,vector<vector<int>>& adjlist){
    for(int i = 1; i <= n; i++){
        cout << "Adjacency list of vertex " << i << ": ";
        for(int j = 0; j < adjlist[i].size(); j++){
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(int node,int &c,vector<vector<int>> &adjlist,vector<int>&vis){
    vis[node]=1;
    c++;
    for(auto &u:adjlist[node]){
        if(!vis[u]){
            dfs(u,c,adjlist,vis);
        }
    }
    vis[node]=0;

}
int numberofsimplepaths(int n,int m,vector<vector<int>> &adjlist){
    int c=0;
    vector<int>vis(n+1,0);
    dfs(1,c,adjlist,vis);
    return c;

}
int main(){
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    vector<vector<int>> adjlist; 
    prepareadjlist(n, m, adjlist); 
    printadjlist(n,adjlist);

    int k=numberofsimplepaths(n,m,adjlist);
    cout<<k;
}
