#include <bits/stdc++.h>
using namespace std;

int main() {
    // for integer array    
    /*int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13] = {0};
    
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int f;
        cin>>f;
        cout<<hash[f]<<endl;
    }*/

    // for string
    string s;
    cin>>s;
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a'] += 1;         // use of ascii values ('A' = 65, 'a' = 97)
    }
    int k2;
    cin>>k2;
    for(int i=0;i<k2;i++){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    
    return 0;
}