#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution{
private:
    int n;
    vector<int> rank, parent;
    int findUPar(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }
public:
    int makeConnected(int n, vector<vector<int>> &con){
        if(con.size()< n-1){
            return -1;
        }
        rank.resize(n+1,0);
        parent.resize(n+1);
        f(i,n){
            parent[i] = i;
        }   
        f(i,con.size()){
            int x = con[i][0];
            int y = con[i][1];
            int ux = findUPar(x);
            int uy = findUPar(y);
            if(rank[ux] < rank[uy]){
                parent[ux] = uy;
                rank[uy] = max(rank[ux]+1, rank[uy]);
            }else{
                parent[uy] = ux;
                rank[ux] = max(rank[uy]+1, rank[ux]);
            }
        }
        unordered_set<int> us;
        f(i,n){
            us.insert(findUPar(i));
        }
        return us.size()-1;
    }
};

int main() {
    int n = 9;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{2,3},{4,5},{5,6},{7,8}};
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}