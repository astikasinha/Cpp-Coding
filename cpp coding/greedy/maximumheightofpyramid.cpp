/*Given n objects, with each object has width wi. We need to arrange them in a pyramidal way such that : 
 

Total width of ith is less than (i + 1)th.
Total number of objects in the ith is less than (i + 1)th.
Input : arr[] = {40, 100, 20, 30}
Output : 2
Top level : 30.
Lower (or bottom) level : 20, 40 and 100
Other possibility can be placing
20 on the top, and at second level any
other 4 objects. Another possibility is
to place 40 at top and other three at the
bottom.

Input : arr[] = {10, 20, 30, 50, 60, 70}
Output : 3 */
#include<bits/stdc++.h>
using namespace std;
int level(int a[],int n){
    int ans=1;

    sort(a,a+n);
    int prevwidth=a[0];
    int prevcount=1;
    int currwidth=0;
    int currcount=0;
    for(int i=0;i<n;i++){
        currwidth=a[i]+currwidth;
        currcount++;
        if(currwidth>prevwidth && currcount>>prevcount){
            prevwidth=currwidth;
            prevcount=-currcount;
            currwidth=0;
            currcount=0;
            ans++;
        }


    }
    return ans;


}
int main(){
    int n;
    cout<<"Enter the number of boxes "<<" ";
    cin>>n;
    int a[n];
    cout<<"Enter the boxes width"<<" ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<level(a,n);
}