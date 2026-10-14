#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

vector<vector<int>> nearest(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        if(r+1<n && dist[r+1][c] == -1){
            dist[r+1][c] = dist[r][c] + 1;
            q.push({r+1,c});
        }
        if(r-1>=0 && dist[r-1][c] == -1){
            dist[r-1][c] = dist[r][c] + 1;
            q.push({r-1,c});
        }
        if(c+1<m && dist[r][c+1] == -1){
            dist[r][c+1] = dist[r][c] + 1;
            q.push({r,c+1});
        }
        if(c-1>=0 && dist[r][c-1] == -1){
            dist[r][c-1] = dist[r][c] + 1;
            q.push({r,c-1});
        }

    }
    return dist;
}

int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	vector<vector<int>> ans = nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    return 0;
}