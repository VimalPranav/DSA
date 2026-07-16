#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int longest_substring(string str){
    int n = str.length();
    int l = 0, r = 0;
    int hash[256];
    f(i, 256){
        hash[i] = -1;
    }
    int maxi = 0;
    f(i, n){
        if(hash[str[i]]!=-1 && hash[str[i]]>=l){
            l = hash[str[i]] + 1;
            hash[str[i]] = i;
        }else{
            maxi = max(maxi, int(i-l+1));
            hash[str[i]] = i;
        }
    }
    return maxi;
}

int main(){
    string str;
    cin>>str;
    int l = longest_substring(str);
    cout<<l;

    return 0;
}