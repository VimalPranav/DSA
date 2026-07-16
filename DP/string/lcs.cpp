#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int memoization(int i1, int i2, string s1, string s2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0){return 0;}
        if(s1[i1] == s2[i2]){return 1 + memoization(i1-1, i2-1, s1, s2, dp);}
        if(dp[i1][i2] != -1){return dp[i1][i2];}
        return dp[i1][i2] = max(memoization(i1-1,i2,s1,s2,dp), memoization(i1,i2-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2){
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return memoization(s1.size()-1, s2.size()-1, s1, s2, dp);
    }
    int longestCommonSubsequenceTub(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s1[i1] == s2[i2]){
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                }else{
                    dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    Solution sol;
    cout << "LCS: " << sol.longestCommonSubsequence(s1, s2) << endl;
    cout << "LCS: " << sol.longestCommonSubsequenceTub(s1, s2) << endl;

    return 0;
}