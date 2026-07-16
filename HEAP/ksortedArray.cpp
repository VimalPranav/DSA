#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

// nlogk timecomplexity
vector<int> kSorted(vector<int> arr, int k){ 
    int n = arr.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    if(k>=n-1){
        sort(arr.begin(), arr.end());
        return arr;
    }
    f(i,k+1){
        pq.push(arr[i]);
    }
    for(int i=k+1;i<n;i++){
        ans.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;  
    vector<int> sortedArr = kSorted(arr, k);

    f(i,sortedArr.size()){
        cout<<sortedArr[i]<<" ";
    }

    return 0;
}