#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    bool memoization(int i, int t, vector<int> arr, vector<vector<int>> &dp){
        if(t == 0){return true;}
        if(i == 0){return (arr[0] == true);}
        
        if(dp[i][t] != -1){return dp[i][t];}
        bool notTake = memoization(i-1, t, arr, dp);
        bool take = false;
        if(t>=arr[i]){
            take = memoization(i-1, t-arr[i], arr, dp);
        }

        return dp[i][t] = notTake || take;
    }

    int Cmemoization(int i, int t, vector<int> a, vector<vector<int>> &dp){
        if(t == 0){return 1;}
        if(t<0){return 0;}
        if(i == 0){
            if(t-a[0] == 0){return 1;}
            return 0;
        }
        if(dp[i][t] != -1){return dp[i][t];}
        return dp[i][t] = Cmemoization(i-1, t, a, dp) + Cmemoization(i-1, t-a[i], a, dp);
    }
public:
    bool subsetSumToKmem(int n, int k, vector<int> arr){
        if(n==0){return true;}
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return memoization(n-1, k, arr, dp);
    }

    bool subsetSumToktub(int n, int k, vector<int> arr){
        if(n==0){return true;}
        vector<vector<bool>> dp(n, vector<bool>(k + 1, -1));
        dp[0][arr[0]] = true;

        for(int i=1;i<n;i++){
            for(int t=1;t<k;t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t>=arr[i]){take = dp[i-1][t-arr[i]];}
                dp[i][t] = notTake || take;
            }
        }

        return dp[n-1][k];
    }

    int countSubsetsMem(vector<int> nums, int t){
        int n = nums.size();
        if(n==0){return true;}
        vector<vector<int>> dp(n, vector<int>(t + 1, -1));
        return Cmemoization(n-1, t, nums, dp);
    }
    int countSubsetsTub(vector<int> nums, int t){
        int n = nums.size();
        if(n==0){return true;}
        vector<vector<int>> dp(n, vector<int>(t + 1, 0));
        dp[0][0] = 1;
        if(nums[0]<=t){dp[0][nums[0]] = 1;}
        for(int i=1;i<n;i++){
            f(k,t+1){
                int notTake = dp[i-1][k];
                int take = 0;
                if(nums[i]<=k){take = dp[i-1][k-nums[i]];}
                dp[i][k] = take + notTake;
            }
        }
        return dp[n-1][t];
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToKmem(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";
    
    cout<<endl;

    if (sol.subsetSumToKmem(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    cout<<endl;

    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    Solution obj;
    cout << obj.countSubsetsMem(nums, target) << endl;
    cout << obj.countSubsetsTub(nums, target) << endl;

    return 0;
}