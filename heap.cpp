#include <bits/stdc++.h>
using namespace std;

class Heap{
private:
    int lc(int i){
        return 2*i + 1;
    }
    int rc(int i){
        return 2*i + 2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    bool hlc(int i){return lc(i)<size;}
    bool hrc(int i){return rc(i)<size;}
    bool hp(int i){return parent(i)>=0;}

public:
    int size;
    int capacity;
    int* arr;
    
    Heap(int n){
        capacity = n;
        size = 0;
        arr = new int[capacity];
    }

    void heapifyUp(int k){
        while(k!=0 && arr[parent(k)] > arr[k]){
            swap(arr[parent(k)], arr[k]);
            k = parent(k);
        }
    }

    void heapifyDown(int k){
        while(hlc(k)){
            int smaller_child_ind = lc(k);
            if(hrc(k) && arr[rc(k)]<arr[lc(k)]){smaller_child_ind = rc(k);}
            if(arr[k]<=arr[smaller_child_ind]){
                break;
            }else{
                swap(arr[k], arr[smaller_child_ind]);
            }
            k = smaller_child_ind;
        }
    }

    void Insert(int data){
        if(size == capacity){
            cout<<"full";
            return;
        }

        arr[size] = data;
        heapifyUp(size);
        size++;
    }

    int get_min(){
        return arr[0];
    }
    int pop_min(){
        int k = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapifyDown(0);
        return k;
    }

    void decrease_key(int i, int value){
        arr[i] = value;
        heapifyUp(i);
    }

    void Delete(int i){
        arr[i] = arr[size-1];
        size--;
        heapifyDown(i);
    }
};

bool isMinHeap(vector<int> arr){
    int n = arr.size();
    int i = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[(i-1)/2]){return false;}
    }
    return true;
}

int main(){
    Heap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout<<h.get_min()<<endl;

    h.Insert(-1);
    cout << "Min value is " << h.get_min() << endl;

    h.decrease_key(3, -2);
    cout << "Min value is " << h.get_min() << endl;

    h.Delete(0);
    cout << "Min value is " << h.get_min() << endl;

    vector<int> nums = {10, 20, 30, 21, 23};

    cout << (isMinHeap(nums) ? "true" : "false") << endl;

    return 0;
}