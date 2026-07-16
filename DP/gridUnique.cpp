#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    int uniquePaths(int n, int m){
        if(n==0){return 0;}
        if(m==0){return 0;}
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        f(i,n){
            f(j,m){
                if(i==0 && j==0){
                    dp[0][0] = 1;
                }
                int up = 0, left = 0;
                if(i>0){dp[i][j] += dp[i-1][j];}
                if(j>0){dp[i][j] += dp[i][j-1];}
            }
        }
        return dp[n-1][m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> m){
        int nr = m.size();
        if(nr==0){return 0;}
        int nc = m[0].size();
        if(nc==0){return 0;}
        vector<vector<int>> dp(nr+1, vector<int>(nc+1,0));
        f(i,nr){
            f(j,nc){
                if(i==0 && j==0){
                    if(m[0][0] == 1){return 0;}
                    dp[0][0] = 1;
                }
                if(m[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if(i>0){dp[i][j] += dp[i-1][j];}
                if(j>0){dp[i][j] += dp[i][j-1];}
            }
        }
        return dp[nr-1][nc-1];
    }
};

int main() {
    int m = 3;
    int n = 2;
    
    //Create an instance of Solution class
    Solution sol;
    
    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}