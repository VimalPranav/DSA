#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

bool isCycle_bfs(int n, vector<int> adj[]){
    int vis[n] = {0};
    vis[0] = 1;
    queue<pair<int, int>> q;
    q.push({0,-1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto i : adj[x]){
            if(i != y){
                if(vis[i] == 1){
                    return true;
                }
                vis[i] = 1;
                q.push({i,x});
            }
        }
    }
    return false;
}
bool isCycle_dfs(vector<int> adj[], int x, int p, int vis[]){
    vis[x] = 1;
    for(auto i : adj[x]){
        if(i != p){
            if(vis[i] == 0){
                return isCycle_dfs(adj,i,x, vis);
            }else{return true;}
        }
    }
    return false;
}


int main(){
    vector<int> adj[4] = {{1}, {0,2}, {1, 3}, {2}};
    bool ans = isCycle_bfs(4, adj);
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";

    int vis[4] = {0};
    bool ans2 = isCycle_dfs(adj,0,-1,vis);
    if (ans2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}