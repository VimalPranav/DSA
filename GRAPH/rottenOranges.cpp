#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int rotten_oranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int t = 0;
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    f(i,n){
        f(j,m){
            if(grid[i][j] == 2){
                q.push({{i,j}, t});
                vis[i][j] = 2;
            }
        }
    }
    
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        t = q.front().second;
        q.pop();
        
        if(r-1>=0 && grid[r-1][c] == 1 && vis[r-1][c] != 2){
            q.push({{r-1, c}, t+1});
            vis[r-1][c] = 2;
        }
        if(c+1<m && grid[r][c+1] == 1 && vis[r][c+1] != 2){
            q.push({{r, c+1}, t+1});
            vis[r][c+1] = 2;
        }
        if(r+1<n && grid[r+1][c] == 1 && vis[r+1][c] != 2){
            q.push({{r+1, c}, t+1});
            vis[r+1][c] = 2;
        }
        if(c-1>=0 && grid[r][c-1] == 1 && vis[r][c-1] != 2){
            q.push({{r, c-1}, t+1});
            vis[r][c-1] = 2;
        }
    }
    f(i,n){
        f(j,m){
            if(vis[i][j] == 1){
                return -1;
            }
        }
    }
    return t;
}

vector<vector<int>> floodFill(vector<vector<int>>image, int sr, int sc, int fclr){
    vector<vector<int>> ans = image;
    int n = image.size();
    int m = image[0].size();
    int sclr = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr,sc});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[sr][sc] = 1;
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        ans[r][c] = fclr;

        if(r-1>=0 && image[r-1][c] == sclr && vis[r-1][c] != 1){
            q.push({r-1, c});
            vis[r-1][c] = 1;
        }
        if(c+1<m && image[r][c+1] == sclr && vis[r][c+1] != 1){
            q.push({r, c+1});
            vis[r][c+1] = 1;
        }
        if(r+1<n && image[r+1][c] == sclr && vis[r+1][c] != 1){
            q.push({r+1, c});
            vis[r+1][c] = 1;
        }
        if(c-1>=0 && image[r][c-1] == sclr && vis[r][c-1] != 1){
            q.push({r, c-1});
            vis[r][c-1] = 1;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
    int rotting = rotten_oranges(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;

    vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
		
	vector<vector<int>> ans = floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
    }

    return 0;
}