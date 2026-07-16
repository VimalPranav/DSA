#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

void kth_Largest_MaxHeap(vector<int> arr, int k){
    priority_queue<int> pq;
    f(i,arr.size()){
        pq.push(arr[i]);
    }
    int m = k-1;
    while(m>0){
        pq.pop();
        m--;
    }
    cout<<pq.top()<<endl;
}

int partitioning(int l, int r, vector<int> &arr){
    int i = l+1;
    while(i<=r){
        if(arr[i]<arr[l]){
            swap(arr[i],arr[l]);
            l = i;
            i = l+1;
        }else{
            i++;
        }
    }
    return l;
}

int optimal_kth_smallest(vector<int> &arr, int k){
    int n = arr.size();
    if(k > n){
        return -1;
    } 
    int l = 0, r = n - 1;
    while(true){
        int p = arr[l];
        p = partitioning(l,r,arr);
        if(p == k-1){return arr[p];}
        else if(p>k-1){r = p-1;}
        else{l = p+1;}
    }
}

void kth_Smallest_MinHeap(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    f(i,arr.size()){
        pq.push(arr[i]);
    }
    int m = k-1;
    while(m>0){
        pq.pop();
        m--;
    }
    cout<<pq.top()<<endl;
}

int main(){
    vector<int>arr = {1, 2, 6, 4, 5, 3} ;
    kth_Largest_MaxHeap(arr, 3)  ;
    kth_Smallest_MinHeap(arr, 3)  ;
    cout<<optimal_kth_smallest(arr, 1);
}