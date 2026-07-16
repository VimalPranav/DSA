#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int orangesRotting(vector<vector<int>> v){
    if(v.empty()) return 0;
    int rows = v.size();
    int cols = v[0].size();
    int mins = -1;
    queue<pair<int, int>> q;
    f(i,rows){
        f(j,cols){
            if(v[i][j] == 2) q.push({i,j});
        }
    }

    while(!q.empty()){
        mins++;
        int size = q.size();
        f(i, size){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            if(x+1 < rows && v[x+1][y] == 1){
                v[x+1][y] = 2;
                q.push({x+1, y});
            }
            if(y+1 < cols && v[x][y+1] == 1){
                v[x][y+1] = 2;
                q.push({x, y+1});
            }
            if(x-1 >=0 && v[x-1][y] == 1){
                v[x-1][y] = 2;
                q.push({x-1, y});
            }
            if(y-1 >=0 && v[x][y-1] == 1){
                v[x][y-1] = 2;
                q.push({x, y-1});
            }
        }

    }

    f(i,rows){
        f(j,cols){
            if(v[i][j] == 1) return -1; 
        }
    }

    return mins;
}

int main() {

    // Input grid with 2 = rotten, 1 = fresh, 0 = empty
    vector<vector<int>> v{{2, 1, 1}, 
                          {0, 1, 1}, 
                          {1, 0, 1}};
    
    // Call the function to calculate minimum time required
    int rotting = orangesRotting(v);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;

    return 0;
}