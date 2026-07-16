#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int memoization(int n, vector<int> &dp, vector<int> h){
        if(n == 0){return 0;}
        if(n==1 || n==2){return abs(h[n] - h[0]);}
        if(dp[n] != -1){return dp[n];}
        int left = memoization(n-1, dp, h) + abs(h[n] - h[n-1]);
        int right = memoization(n-2, dp, h) + abs(h[n] - h[n-2]);
        return dp[n] = min(left,right);
    }
public:
    int frogJumpmem(vector<int> h){
        int n = h.size();
        vector<int> dp(n+1,-1);
        return memoization(n-1, dp, h);
    }

    int frogJumptub(vector<int> h){
        int n = h.size();
        if(n == 0){return 0;}
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);
        if(n==1){return dp[1];}
        dp[2] = abs(h[2] - h[0]);
        if(n==2){return dp[2];}

        for(int i=3;i<n;i++){
            dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
        }
        return dp[n-1];
    }
};

class Sol_k {
private:
    int memoization(int n, vector<int> &dp, vector<int> h, int k){
        if(n == 0){return 0;}
        if(n==1 || n==2){return abs(h[n] - h[0]);}
        if(dp[n] != INT32_MAX){return dp[n];}
        f(i,k){
            dp[n] = min(dp[n],  memoization(n-i-1, dp, h, k) + abs(h[n] - h[n-i-1]));
        }
        
        return dp[n];
    }
public:
    int frogJumpmem(vector<int> h, int k){
        int n = h.size();
        vector<int> dp(n+1,INT32_MAX);
        return memoization(n-1, dp, h, k);
    }

    int frogJumptub(vector<int> h, int k){
        int n = h.size();
        if(n == 0){return 0;}
        vector<int> dp(n+1,INT32_MAX);
        dp[0] = 0;

        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                if(j>i){continue;}
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
        return dp[n-1];
    }
};

int main(){
    // Define the heights array
    vector<int> height{30, 10, 60, 10, 60, 50};

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJumpmem(height) << endl; // Expected: 40
    cout << sol.frogJumptub(height) << endl;

    vector<int> h{15, 4, 1, 14, 15, 0};
    int k = 3;

    Sol_k solk;

    // Compute and print the minimum energy
    cout << solk.frogJumpmem(h, k) << endl; 
    cout << solk.frogJumptub(h, k) << endl;

    return 0;
}