#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int memoization(int t, vector<int> &dp, vector<int> cns){
        if(t==0){return 0;}
        if(t<0){return -1;}
        if(dp[t] != -2){return dp[t];}
        int mini = INT_MAX;
        f(j,cns.size()){
            int rez = memoization(t-cns[j], dp, cns);
            if(rez>=0 && rez<mini){
                mini = 1 + rez;
            }
        }

        dp[t] = (mini == INT_MAX) ? -1 : mini;
        return dp[t];
    }
public:
    int coinChange(vector<int> cns, int amt){
        int n = cns.size();
        if(n==0){return 0;}
        vector<int> dp(amt+1, -2);
        return memoization(amt,dp,cns);
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}