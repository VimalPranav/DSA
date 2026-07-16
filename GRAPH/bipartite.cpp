#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    Solution() {}

    bool isBipartite(int n, vector<int> adj[]) {
        if(n == 0) return true;
        vector<int> color(n, -1);
        queue<int> q;
        color[0] = 0;
        q.push(0);

        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i : adj[x]){
                if(color[i] == -1){
                    color[i] = 1 - color[x];
                    q.push(i);
                }else if(color[i] == color[x]){
                    return false;
                }
            }
        }

        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
	
	// V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}