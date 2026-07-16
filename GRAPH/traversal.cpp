#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Traversal{
    public:
        vector<int> bfs(int n, vector<int> adj[]){
            int vis[n] = {0};
            vis[0] = 1;
            queue<int> q;
            vector<int> bfs;
            q.push(0);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                bfs.push_back(x);
                for(auto i : adj[x]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
            return bfs;
        }

        void dfs(int v, vector<int> adj[], int vis[], vector<int> &ans2){
            vis[v] = 1;
            ans2.push_back(v);
            for(auto it : adj[v]){
                if(vis[it] == 0){
                    dfs(it, adj, vis, ans2);
                }
            }
        }

        int provinces(vector<vector<int>> adjM, int v){
            vector<int> adjL[v];
            int cnt = 0;
            vector<int> ans;
            f(i,v){
                f(j,v){
                    if (adjM[i][j] == 1 && i != j) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                    }
                }
            }
            int vis[v] = {0};
            f(i,v){
                if(vis[i] == 0){
                    cnt++;
                    dfs(i, adjL, vis, ans);
                }
            }
            return cnt;
        }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Traversal obj;
    vector <int> ans = obj.bfs(5, adj);
    
    f(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout<<endl;

    vector <int> ans2;
    int vis[5] = {0};
    obj.dfs(0, adj, vis, ans2);

    f(i, ans2.size()){
        cout << ans2[i] << " ";
    }
    cout<<endl;

     vector<vector<int>> adjM = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = 3;
    cout << obj.provinces(adjM, V) << endl;

    return 0;
}