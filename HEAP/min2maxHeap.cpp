#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int k){
    int n = arr.size();
    int lc = 2*k+1;
    int rc = 2*k+2;

    int maxi = k;
    if(lc < n && arr[lc] > arr[maxi]){maxi = lc;}
    if(rc < n && arr[rc] > arr[maxi]){maxi = rc;}

    if(maxi != k){
        swap(arr[k], arr[maxi]);
        maxHeapify(arr, maxi);
    }
}

void min2max(vector<int> &arr){
    int n = arr.size();
    for(int i=(n-1)/2;i>=0;i--){
        maxHeapify(arr, i);
    }
}

int main(){
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    min2max(arr);

    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";

    return 0;
}