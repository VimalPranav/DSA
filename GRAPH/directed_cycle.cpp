#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
private:
    bool dfsCheck(int i, vector<int> adj[], int vis[], int pathVis[]){
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                if (dfsCheck(it, adj, vis, pathVis) == true) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
public:
    Solution() {}

    bool isCyclic(int v, vector<int> adj[]){
        int vis[v] = {0};
        int pathVis[v] = {0};

		for (int i = 0; i < v; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}

        return false;
    }
};

int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}