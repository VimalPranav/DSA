#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    Solution() {}

    int MinimumEffort(vector<vector<int>> h){
        int n = h.size();
        int m = h[0].size();
        if(n==1 && m==1){
            return 0;
        }
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        vector<vector<int>> eff (n, vector<int>(m, 1e9));

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == m-1){
                return eff[r][c];
            }
            f(i,4){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neff = max(abs(h[nr][nc] - h[r][c]),diff);
                    if(neff < eff[nr][nc]){
                        eff[nr][nc] = neff;
                        pq.push({neff,{nr,nc}});
                    }                    
                }            
            }
        }
        return 0;
    }

};

int main() {
    // Input h (heights)
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    // Find the minimum effort path
    int ans = obj.MinimumEffort(heights);

    // Output the result
    cout << ans << endl;

    return 0;
}