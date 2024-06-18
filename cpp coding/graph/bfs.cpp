#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,e,a,b;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    vector<int>adjlist[n];
    for(int i=1;i<=e;i++){
        cout<<"Enter the points in the edges: "<<i;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        int s=adjlist[i].size();
        for(int j=0;j<s;j++){
            cout<<adjlist[i][j];
            cout<<" , ";
        }
        cout<<endl;
    }
    queue<int>q;
    vector<int>status(n);
    q.push(0);
    status[0]=1;
    cout<<"BFS order: ";
    while(q.size()!=0){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        int s=adjlist[x].size();
        for(int j=0;j<s;j++){
            int y;
            y=adjlist[x][j];
            if(status[y]==0){
                status[y]=1;
                q.push(y);
            }
        }
    }
}
