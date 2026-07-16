#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int memoization(int n, vector<vector<int>> &dp, vector<vector<int>> p, int k){
    if(dp[n][k] != -1){return dp[n][k];}
    if(n==0){
        int maxi = 0;
        f(i,p[0].size()){
            if(i != k){
                maxi = max(maxi, p[0][i]);
            }
        }
        return dp[0][k] = maxi;
    }
    int maxi = 0;
    f(i,p[n].size()){
        if(i != k){
            int a = p[n][i] + memoization(n-1,dp,p,i);
            maxi = max(maxi, a);
        }
    }
    return dp[n][k] = maxi;
}

int ninjaTraining_mem(int n, vector<vector<int>> p){
    if(n==0){return 0;}
    int k = p[0].size();
    if(k==0){return 0;}
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return memoization(n-1, dp, p, k);
}

int ninjaTraining_tub(int n, vector<vector<int>> p){ //{10, 40, 70}, {20, 50, 180}, {30, 60, 90}
    if(n==0){return 0;}
    int k = p[0].size();
    if(k==0){return 0;}
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    for(int i=0;i<k;i++){
        dp[0][i] = p[0][i];
    }
    for(int i=1;i<n;i++){
        f(j,k){
            f(l,k){
                if(j != l){
                    dp[i][j] = max(dp[i][j], dp[i-1][l] + p[i][j]);
                }
            }
        }
    }
    int maxi = 0;
    f(i,k){
        maxi = max(maxi, dp[n-1][i]);
    }
    return maxi;
}

int main() {
    // Define the points matrix
    vector<vector<int>> points = {{10, 40, 70},
                                   {20, 50, 80},
                                   {30, 60, 90}};

    int n = points.size();  // Get the number of days
    // Call the ninjaTraining function to find the maximum points and print the result
    cout << ninjaTraining_mem(n, points)<<endl;    
    cout << ninjaTraining_tub(n, points);

    return 0;
}