#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    void dfs(int v, vector<int> adj[], int vis[], stack<int> &s){
            vis[v] = 1;
            for(auto it : adj[v]){
                if(!vis[it]){
                    dfs(it, adj, vis, s);
                    s.push(it);
                }
            }
            return;
        }
public:
    Solution (){}

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans(V);
        int vis[V] = {0};
        stack<int> s;
        f(i,V){
            if(!vis[i]){
                dfs(i, adj, vis, s);
                s.push(i);
            }
        }
        f(i,V){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }

};

int main() {
    int V = 4, E = 3;

    // Adjacency list representation of the graph
    /*  
    5->0<-4
    |     |
    v     v
    2->3->1
    */
    vector<int> adj[V];
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(0);
    // Create an object of Solution
    Solution obj;

    // Get the topological order
    vector<int> res = obj.topoSort(V, adj);

    // Print the result
    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}