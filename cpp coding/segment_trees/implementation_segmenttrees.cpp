
#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> tree; // Segment tree
    int n; // Size of the input array

    // Constructor to build the segment tree
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n); // Resize to ensure enough space
        build(1, 0, n - 1, nums);
    }

    // Public method to update a value at a given index
    void update(int index, int value) {
        updateTree(1, 0, n - 1, index, value);
    }

    // Public method to query the sum in a range
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

private:
    // Helper method to build the segment tree
    void build(int node, int start, int end, vector<int>& nums) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Helper method to update the segment tree
    void updateTree(int node, int start, int end, int index, int value) {
        if(start == end) {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if(index <= mid) {
            updateTree(2 * node, start, mid, index, value);
        } else {
            updateTree(2 * node + 1, mid + 1, end, index, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Helper method to query the segment tree
    int query(int node, int start, int end, int left, int right) {
        if(start > right || end < left) {
            return 0;
        }
        if(left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int q1 = query(2 * node, start, mid, left, right);
        int q2 = query(2 * node + 1, mid + 1, end, left, right);
        return q1 + q2;
    }
};

// Main function should be outside of the class definition
int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    
    cout << "sumRange(0, 2) -> Expected: 1, Got: " << numArray.sumRange(0, 2) << endl;
    cout << "sumRange(2, 5) -> Expected: -1, Got: " << numArray.sumRange(2, 5) << endl;
    cout << "sumRange(0, 5) -> Expected: -3, Got: " << numArray.sumRange(0, 5) << endl;
    numArray.update(0, 1); // Update the value at index 0 to 1
    cout << "After updation sumRange(0, 5) -> Expected: 0, Got: " << numArray.sumRange(0, 5) << endl;
    
    return 0;
}


