#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13] = {0}; 
    
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }
    
    for(int i=0;i<13;i++){
        if(hash[i]!=0){
            cout<<i<<": "<<hash[i]<<endl;
        }
    }
    
    return 0;
}