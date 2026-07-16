#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> dist (V,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,S});
    dist[S] = 0;

    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int d = it.first;
        pq.pop();
        for(auto iti : adj[node]){
            int adj_node = iti[0];
            int wt = iti[1];
            if(d+wt<dist[adj_node]){
                dist[adj_node] = d + wt;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    return dist;
}

vector<int> dj(int V, vector<vector<int>> adj[], int S){
    vector<int> dist(V+1,1e9);
    dist[S] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,S});
    while(!pq.empty()){
        auto node = pq.top();
        int d = node.first;
        int x = node.second;
        pq.pop();
        for(auto it : adj[x]){
            if(d+it[1] < dist[it[0]]){
                dist[it[0]] = d+it[1];
                pq.push({dist[it[0]], it[0]});
            }
        }
    }

    f(i,V){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    return dist;
}

int main(){
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dj(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}