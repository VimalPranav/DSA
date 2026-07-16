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
    int longestPalinSubseq(string s){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string rev = "";
        for(int i=n-1;i>=0;i--){
            rev += s[i];
        }
        return memoization(n-1, n-1, s, rev, dp);
    }
};

int main() {
    string s = "bbabcbcab";
    
    //Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalinSubseq(s);
    return 0;
}