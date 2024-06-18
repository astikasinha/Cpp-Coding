/*You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 A pair (c, d) can follow another pair (a, b) if b < c. 
 Chain of pairs can be formed in this fashion. Find the longest chain which can be formed 
 from a given set of pairs. 
Source: Amazon Interview | Set 2
For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, 
then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}*/
#include<bits/stdc++.h>
using namespace std;

struct pairs {
    int a, b;
};

bool comparison(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maxlength(struct pairs arr[], int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i].a, arr[i].b});
    }
    sort(v.begin(), v.end(), comparison);
    
    int i = 0;
    int j = 1;
    int c = 1;
    int n1 = v.size();
    while (j < n1) {
        if (v[i].second < v[j].first) {
            i = j;
            c++;
            j++;
        }
        else{
            j++;
        }
    }
    return c;
}

int main() {
    pairs arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of maximum size chain is " << maxlength(arr, n); 
}
