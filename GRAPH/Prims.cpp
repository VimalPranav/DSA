#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution{
public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int vis[V] = {0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int x = it.second;
            if(vis[x] == 1){continue;}
            vis[x] = 1;
            ans += wt;

            for(auto a : adj[x]){
                if(!vis[a[0]]){
                    pq.push({a[1], a[0]});
                }
            }
        }

        return ans;
    }
};

int main(){
    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}