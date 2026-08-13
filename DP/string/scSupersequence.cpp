#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution { // brute groot -> bgrooute
private:
    string mem(int i, int j, string &s1, string &s2, vector<vector<string>> &dp){
        if(i == s1.length() || j == s2.length()){
            return dp[i][j] = (i == s1.length()) ? s2.substr(j) : s1.substr(i);
        }
        if(dp[i][j] != ""){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = s1[i] + mem(i+1, j+1, s1, s2, dp);
        }
        string x = s1[i] + mem(i+1, j, s1, s2, dp);
        string y = s2[j] + mem(i, j+1, s1, s2, dp);
        if(x == ""){
            return dp[i][j] = y;
        }
        if(y == ""){
            return dp[i][j] = x;
        }
        return dp[i][j] = (x.length() <= y.length()) ? x : y;
    }
public:
    string shortestSupersequence(string s1, string s2){
        vector<vector<string>> dp(s1.length() + 1, vector<string>(s2.length() + 1, ""));
        return mem(0, 0, s1, s2, dp);
    }
};

int main() {

    // Define input strings
    string s1 = "dynamic";
    string s2 = "program";

    // Create object of Solution class
    Solution obj;

    // Call the function and print result
    cout << "The Shortest Common Supersequence is " << obj.shortestSupersequence(s1, s2);

    return 0;
}