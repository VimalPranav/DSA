#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int memoization(int n, vector<int> &dp, vector<int> h){
        if(n < 0){return 0;}
        if(n == 0){return h[0];}
        if(dp[n] != -1){return dp[n];}
        return dp[n] = max(h[n] + memoization(n-2, dp, h), memoization(n-1, dp, h));
    }
public:
    int maximumNonAdjacentSum_mem(vector<int> h){
        int n = h.size();
        vector<int> dp(n+1,-1);
        return memoization(n-1, dp, h);
    }

    int maximumNonAdjacentSum_tub(vector<int> h){
        int n = h.size();
        if(n == 0){return 0;}
        vector<int> dp(n+1,-1);
        dp[0] = h[0];
        for(int i=1;i<n;i++){
            if(i==1){
                dp[1] = max(h[0],h[1]);
                continue;
            }
            dp[i] = max(h[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

    int maximumNonAdjacentSum_cycle(vector<int> h){
        int n = h.size();
        if(n==0){return 0;};
        if(n==1){return h[0];}
        if(n==2){return max(h[0],h[1]);}
        vector<int> dp(n+1,-1);
        dp[0] = h[0];
        for(int i=1;i<n-1;i++){
            if(i==1){
                dp[1] = max(h[0],h[1]);
                continue;
            }
            dp[i] = max(h[i] + dp[i-2], dp[i-1]);
        }
        int x = dp[n-2];

        f(i,n){dp[i] = -1;}
        dp[0] = 0;
        dp[1] = h[1];     
        for(int i=2;i<n;i++){
            dp[i] = max(h[i] + dp[i-2], dp[i-1]);
        } 
        int y = dp[n-1];
        return max(x,y);

    }
};

int main() {
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;

    // Output the result
    cout << obj.maximumNonAdjacentSum_mem(arr)<<endl;
    cout << obj.maximumNonAdjacentSum_tub(arr)<<endl;
    cout << obj.maximumNonAdjacentSum_cycle(arr)<<endl;
    return 0;
}