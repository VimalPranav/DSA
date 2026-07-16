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

    int Cmemoization(int i, int t, vector<int> &a, vector<vector<int>> &dp, int sum, int total){
        if(i < 0){
            if(abs(total - 2 * sum) == t) {
                return 1;
            }
            return 0;
        }

        if(dp[i][sum] != -1){return dp[i][sum];}
        return dp[i][sum] = Cmemoization(i-1, t, a, dp, sum, total) + Cmemoization(i-1, t, a, dp, sum+a[i], total);
    }

public:
    int minSubsetSumDifferenceMem(vector<int> a, int n){
        if(n==0){return 0;}
        int total = 0;
        f(i,n){
            total += a[i];
        }
        vector<vector<int>> dp(n, vector<int>(total+1, -1));
        f(i,total){
            bool b = memoization(n-1, i, a, dp);
        }
        int minDiff = INT16_MAX;
        f(i,total){
            if(dp[n-1][i] == true){
                minDiff = min(minDiff, (int)abs(total - 2*i));
            }
        }
        return minDiff;
    }
    int minSubsetSumDifferenceTub(vector<int> a, int n){
        if(n==0){return 0;}
        int total = 0;
        f(i,n){
            total += a[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(total+1, false));
        f(i,n){
            dp[i][0] = 0;
        }
        if(a[0]<=total){
            dp[0][a[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<total;t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t>=a[i]){take = dp[i-1][t-a[i]];}
                dp[i][t] = take || notTake;
            }
        }
        int minDiff = INT16_MAX;
        f(i,total){
            if(dp[n-1][i] == true){
                minDiff = min(minDiff, (int)abs(total - 2*i));
            }
        }
        return minDiff;
    }

    int countPartitions(vector<int> a, int d){
        int n = a.size();
        int total = 0;
        f(i,n){
            total += a[i];
        }
        vector<vector<int>> dp(n, vector<int>(total+1, -1));
        return Cmemoization(n-1, d, a, dp, 0, total)/2;
    }
};

int main() {
    vector<int> arr = {8, 6, 5};
    int n = arr.size();

    Solution sol;
    cout << "The minimum absolute difference is: " << sol.minSubsetSumDifferenceMem(arr, n) << endl;
    cout << "The minimum absolute difference is: " << sol.minSubsetSumDifferenceTub(arr, n) << endl;

    vector<int> a = {1, 1, 2, 3};
    int d = 1;
    cout << sol.countPartitions(a, d) << endl;

    return 0;
}