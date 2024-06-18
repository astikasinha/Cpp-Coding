
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sum(const vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    string num1, num2;
    for(int digit : arr) {
        pq.push(digit);
    }
    while(!pq.empty()) {
        num1 += (48 + pq.top());
        pq.pop();
        if(!pq.empty()) {
            num2 += (48 + pq.top());
            pq.pop();
        }
    }
    int numA = stoi(num1);
    int numB = stoi(num2);
    return numA + numB;
}

int main() {
    int n;
    cout << "Enter the number of digits in array A: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the digits in array A: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = sum(a);
    cout << result;
}
