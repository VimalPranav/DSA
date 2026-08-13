#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution { // abcde abfce
private:
    int memoization(int i1, int i2, string s1, string s2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0){return 0;}
        if(s1[i1] == s2[i2]){
            return 1 + memoization(i1-1, i2-1, s1, s2, dp);
        }
        if(dp[i1][i2] != -1){return dp[i1][i2];}
        return dp[i1][i2] = 0;
    }
public:
    int longestCommonSubsequence(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        int ans = 0;
        f(i1,n1){
            f(i2,n2){
                int a = memoization(i1, i2, s1, s2, dp);
                ans = max(ans, a);
            }
        }
        return ans;
    }
    int longestCommonSubsequenceTub(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        int ans = 0;

        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s1[i1-1] == s2[i2-1]){
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                    ans = max(ans, dp[i1][i2]);
                }else{
                    dp[i1][i2] = 0;
                }
            }
        }
        return ans;
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "abcce";

    Solution sol;
    cout << "LCS: " << sol.longestCommonSubsequence(s1, s2) << endl;
    cout << "LCS: " << sol.longestCommonSubsequenceTub(s1, s2) << endl;

    return 0;
}