#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class DisjointSet{
private:
    int n;
    vector<int> rank, parent;
public:
    DisjointSet(int edj) {
        n = edj;
        rank.resize(n+1,0);
        parent.resize(n+1);
        f(i,n){
            parent[i] = i;
        }
    }

    int findUPar(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }

    void unionByRank(int x, int y){
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
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}