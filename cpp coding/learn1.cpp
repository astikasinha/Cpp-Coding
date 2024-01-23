#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucketsort(double a[],int size ){
    vector<double>bucket[15];
    for(int i=0;i<15;i++){
        int x=a[i]*10;
        bucket[x].push_back(a[i]);
    }
    for(int i=0;i<15;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<bucket[i].size();j++){
            cout<<bucket[i][j]<<" ";
        }
    }
}
int main(){
    /*vector<int>V;
    cout<<V.size()<<"\n"<<endl;
    V.push_back(21);
    V.push_back(12);
    V.push_back(3);
    V.push_back(14);
    V.push_back(7);
    int N=V.size();
    for(int i=0;i<N;i++){
        cout<<V[i]<< " ";
    }
    cout<<"\n";
    for(auto i:V){
        cout<<i<< " ";
    }
    sort(V.begin(),V.end());
    cout<<"\n";
    for(auto i:V){
        cout<<i<< " ";
    }*/
    //cout<<V.size();
    /*vector<int>V[5];
    V[0].push_back(11);
    V[0].push_back(2);
    V[0].push_back(31);
    V[0].push_back(14);
    V[1].push_back(53);
    V[1].push_back(16);
    V[1].push_back(70);
    V[2].push_back(85);
    V[2].push_back(19);
    V[2].push_back(1);
    V[2].push_back(114);
    V[2].push_back(102);
    V[3].push_back(213);
    V[3].push_back(140);
    V[4].push_back(195);
    V[4].push_back(60);
    V[4].push_back(917);
    V[4].push_back(188);
    V[4].push_back(197);
    V[4].push_back(200);
    for(int i=0;i<5;i++){
        sort(V[i].begin(),V[i].end());
    }
    cout<<"\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<V[i].size();j++){
            cout<<V[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    double a[]={0.77,0.34,0.98,0.03,0.46,0.33,0.39,0.86,0.48,0.66,0.23,0.14,0.60,0.17,0.38,0.71};
    bucketsort(a,15);
}