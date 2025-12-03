#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

void selection_sort(vector<int> &arr, int n){
    f(i,n-1){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}
void bubble_sort(vector<int> &arr, int n){
    for(int j=n;j>0;j--){
        f(i,j-1){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
}
void insertion_sort(vector<int> &arr, int n){    
    f(i,n){
        for(int j=i;j>0;j--){
            if(arr[j]>=arr[j-1]){
                break;
            }else{
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

int partition(vector<int> &arr, int low, int high){
    int p = arr[low];
    int l = low, r = high;
    while(l<=r){
        while(arr[l]<=p && l<=high){l++;}
        while(arr[r]>p && r>=low){r--;}
        if(l<r){
            swap(arr[l],arr[r]);
        }
    }
    swap(arr[low],arr[r]);
    return r;
}
void quick_sort(vector<int> &arr, int low, int high){
    if(low>=high){return;}
    int p_index = partition(arr,low,high);
    quick_sort(arr,low,p_index-1);
    quick_sort(arr,p_index+1,high);
}

void merge(vector<int> &arr, int low, int high, int mid){
    vector<int> ans;
    int l = low;
    int r = mid + 1;
    while(l<=mid && r<=high){
        if(arr[l]<=arr[r]){
            ans.push_back(arr[l]);
            l++;
        }else{
            ans.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
        ans.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        ans.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = ans[i-low];
    }
}

void divide(int low, int high, vector<int> &arr){
    if(low >= high){return;}
    int mid = (low + high)/2;
    divide(low,mid,arr);
    divide(mid+1,high,arr);
    merge(arr,low,high,mid);
}

void merge_sort(vector<int> &arr, int n){
    divide(0, n-1, arr);
}

void heapify(vector<int>& arr, int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    cout << "Before selection sort: " << "\n";
    f(i,n) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 1
    bubble_sort(arr, n);

    f(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 2
    arr = {13, 46, 24, 52, 20, 9};

    selection_sort(arr, n);

    f(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 3
    arr = {13, 46, 24, 52, 20, 9};

    insertion_sort(arr, n);

    f(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 4
    arr = {13, 46, 24, 52, 20, 9};

    quick_sort(arr, 0, n-1);

    f(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 5
    arr = {13, 46, 24, 52, 20, 9};

    merge_sort(arr, n);

    f(i,n) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 6
    arr = {13, 46, 24, 52, 20, 9};

    heap_sort(arr, n);

    f(i,n) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}