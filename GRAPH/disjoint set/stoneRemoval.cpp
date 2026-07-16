#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution{
private:
    int n;
    unordered_map<int, int> parent;
    int findUPar(int x){
        if(parent.find(x) == parent.end())
            parent[x] = x;
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }
public:
    int removeStones(vector<vector<int>> &stones){
        int n = stones.size(); 
        f(i,n){
            int x = stones[i][0];
            int y = stones[i][1] + 200;
            int ux = findUPar(x);
            int uy = findUPar(y);
            parent[uy] = ux;
        }
        unordered_set<int> us;
        f(i,n){
            us.insert(findUPar(stones[i][0]));
        }
        return n - us.size();
    }
};

int main() {
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };

    Solution obj;
    cout << obj.removeStones(stones) << endl;
    return 0;
}