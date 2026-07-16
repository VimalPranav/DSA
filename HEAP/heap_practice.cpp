#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    int lchild(int k){
        return 2*k+1;
    }
    int rchild(int k){
        return 2*k+2;
    }
    int parent(int k){
        return (k-1)/2;
    }
public:
    int capacity;
    int* arr;
    int size;

    MinHeap(int n){
        capacity = n;
        arr = new int[capacity];
        size = 0;
    }
    void Insert(int val){
        if(size == capacity){
            cout<<"FULL";
            return;
        }
        int k = size;
        arr[size] = val;
        size++;
        
        while(k && arr[k] < arr[parent(k)]){
            swap(arr[k], arr[parent(k)]);
            k = parent(k);
        }
    }
    void Heapify(int i){
        int rc = rchild(i);
        int lc = lchild(i);
        if(lc >= size){
            return;
        }
        int min_child;

        if(rc < size && arr[lc]>arr[rc]){min_child = rc;}
        else{min_child = lc;}
        if(arr[i]>arr[min_child]){
            swap(arr[i], arr[min_child]);
            Heapify(min_child);            
        }
    }
    int getMin(){
        if(size == 0){
            exit(0);
        }
        return arr[0];
    }
    int ExtractMin(){
        if(size == 0){
            exit(0);
        }
        int m = arr[0];
        arr[0] = arr[size-1];
        size--;
        Heapify(0);
        return m;
    }
    void DecreaseKey(int i, int val){
        arr[i] = val;
        while(i && arr[i] < arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void Delete(int i){
        arr[i] = arr[size-1];
        size--;
        Heapify(i);
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

bool isMinHeap(vector<int> arr){
    int n = arr.size();
    if(n == 0 || n == 1){
        return true;
    }
    int i = 0;
    for(int i=1;i<n;i++){
        if(arr[i] < arr[(i-1)/2]){
            return false;
        }
    }
    return true;
}

int main(){
    MinHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.DecreaseKey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(1);
    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    return 0;
}