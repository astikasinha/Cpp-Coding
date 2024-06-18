#include<iostream>
#include<vector>
using namespace std;

void dfsrec(int i, vector<int> adj[], vector<int>& status, int& time, vector<int>& s, vector<int>& f) {
    time = time + 1;
    s[i] = time;
    status[i] = 1;
    cout << i << " ";
    for(int j=0; j<adj[i].size(); j++){
        int next = adj[i][j];
        if(status[next] == 0){
            dfsrec(next, adj, status, time,s, f);
        }
    }
    time = time + 1;
    f[i] = time;
}

void DFS(int n, vector<int> adj[]) {
    vector<int> status(n, 0), discovery(n), finish(n);
    int time = 0;
    for(int i=0; i<n; i++){
        if(status[i] == 0){
            dfsrec(i, adj, status, time, discovery, finish);
        }
    }
}
int main(){
    int n,e,i,a,b;
    cout<<"Enter number of vertices";
    cin>>n;
    vector<int>adj[n];
    cout<<"Enter number of edges";
    cin>>e;
    for(i=1;i<=e;i++){
        cout<<"Enter the endpoints of edges"<<i<<": ";
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=0;i<n;i++){
        int j=0;
        cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<"order of DFS is:=> ";
    DFS(n,adj);
    

}

/*int main(){
    int n, e,a,b;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    vector<int>adj[n];
    for(int i=1;i<=e;i++){
        cout<<"Enter the points in the edges: "<<i;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        int s=adj[i].size();
        for(int j=0;j<s;j++){
            cout<<adj[i][j];
            cout<<" , ";
        }
        cout<<endl;
    }

    cout << "Order of DFS is: => ";
    DFS(n, adj);
}*/
