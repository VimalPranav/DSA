#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    // iterating over the map:
    for(auto it : mp){
            cout << it.first << "->" << it.second << endl;
        }

    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int f;
        cin>>f;
        cout<<mp[f]<<endl;
    }
    
    return 0;
}