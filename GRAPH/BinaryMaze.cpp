#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    Solution() {}

    int shortestPath(vector<vector<int>> grid, pair<int, int> s,  pair<int, int> d){
        if(s.first == d.first && s.second == d.second){return 0;}
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{s.first,s.second}});

        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        vector<vector<int>> dist (n, vector<int>(m, 1e9));
        dist[s.first][s.second] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            f(i,4){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && dis+1 < dist[nr][nc]){
                    dist[nr][nc] = dis + 1;
                    q.push({dist[nr][nc], {nr,nc}});
                }
                if(nr == d.first && nc == d.second && grid[nr][nc] == 1){
                    return dist[nr][nc];
                }
            }
        }

        return -1;
    }

};

int main() {
    // Driver Code
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    // Define the grid
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0},
                                 {1, 0, 0, 1}};

    Solution obj;

    // Call the method to find the shortest path
    int res = obj.shortestPath(grid, source, destination);

    // Output the result
    cout << res << endl;

    return 0;
}