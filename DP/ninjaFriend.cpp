#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    int memoization(int i, int j1, int j2, vector<vector<vector<int>>> &dp, int n, int m, vector<vector<int>> grid){
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return -1e9;
        }
        if(i == n-1){
            if(j1 == j2){return grid[i][j1];}
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1){return dp[i][j1][j2];}
        vector<int> dj = {-1,0,1};
        int cur = (j1 == j2)? grid[i][j1] : grid[i][j1] + grid[i][j2];
        f(a,3){
            f(b,3){
                int cj1 = j1 + dj[a];
                int cj2 = j2 + dj[b];
                int ans = cur + memoization(i+1, cj1, cj2, dp, n, m, grid);
                dp[i][j1][j2] = max(dp[i][j1][j2], ans);
            }
        }
        return dp[i][j1][j2];
    }
public:
    int maximumChocolates_mem(int n, int m, vector<vector<int>> grid){
        if( n==0 || m==0){return 0;}
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1)));
        return memoization(0, 0, m-1, dp, n, m, grid);
    }
    int maximumChocolates_tub(int n, int m, vector<vector<int>> grid){
        if( n==0 || m==0){return 0;}
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, 0)));

        for(int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            f(j1,m){
                f(j2,m){
                    int cur = (j1 == j2)? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    int dj[3] = {-1,0,1};
                    f(a,3){
                        f(b,3){
                            int cj1 = j1 + dj[a];
                            int cj2 = j2 + dj[b];
                            if(cj1<0 || cj2<0 || cj1>=m || cj2>=m){continue;}
                            int k = cur + dp[i+1][cj1][cj2];
                            dp[i][j1][j2] = max(k, dp[i][j1][j2]);
                        }
                    }
                }
            }
        }

        return dp[0][0][m-1];

    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size(), m = grid[0].size();
    Solution obj;
    cout << obj.maximumChocolates_mem(n, m, grid) << endl;
    cout << obj.maximumChocolates_tub(n, m, grid) << endl;
    return 0;
}