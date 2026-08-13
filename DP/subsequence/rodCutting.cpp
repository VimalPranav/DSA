#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int mem(int idx, vector<int>& price, int t, vector<vector<int>>& dp) {
        if(t == 0) return 0;
        if(idx < 0) return 0;
        if(dp[t][idx] != -1) return dp[t][idx];
        int notTaken = mem(idx - 1, price, t, dp);
        int taken = 0;
        if(t >= idx+1) taken = price[idx] + mem(idx, price, t-idx-1, dp);
        return dp[t][idx] = max(taken, notTaken);
    }
public:
    int rodCutting(vector<int>& price, int t){
        vector<vector<int>> dp(t + 1, vector<int>(price.size(), -1));
        return mem(price.size() - 1, price, t, dp);
    }
};

int main(){
    int n = 8;

    // Price list where price[i] is the value of rod of length i+1
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    // Create object of Solution class
    Solution obj;

    // Call rodCutting function and print the result
    int maxValue = obj.rodCutting(price, n);
    cout << "The maximum obtainable value is: " << maxValue << endl;

    return 0;
}