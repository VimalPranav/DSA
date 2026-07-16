#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int memoization (int n, vector<int> &dp){
    if(n==0 || n==1){return 1;}
    if(dp[n]!=-1){return dp[n];}
    return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<memoization(n,dp)<<endl;

    int prev2 = 1;
    int prev = 1;

    for(int i=2;i<n;i++){
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    cout<<prev+prev2<<endl;

    return 0;
}