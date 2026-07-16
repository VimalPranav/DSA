#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution{
private:
    int n;
    vector<int> size, parent;
    int findUPar(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc){
        int n = acc.size();

        size.resize(n+1,0);
        parent.resize(n+1);
        f(i,n){
            parent[i] = i;
        }   
        unordered_map<string, int> mapMailNode;
        f(i,n){
            for(int j=1;j<acc[i].size();j++){
                string mail = acc[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    int x = i;
                    int y = mapMailNode[mail];
                    int ux = findUPar(x);
                    int uy = findUPar(y);
                    if(size[ux] < size[uy]){
                        parent[ux] = uy;
                        size[uy] = max(size[ux]+1, size[uy]);
                    }else{
                        parent[uy] = ux;
                        size[ux] = max(size[uy]+1, size[ux]);
                    }
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it : mapMailNode){
            int up = findUPar(it.second);
            mergedMail[up].push_back(it.first);
        }
        vector<vector<string>> ans;
        f(i,n){
            if(mergedMail[i].empty()){continue;}
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(acc[i][0]);
            for(auto m : mergedMail[i]){
                temp.push_back(m);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    // Input accounts
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    // Create Solution object
    Solution obj;

    // Call function
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    // Print output
    for (auto &acc : ans) {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}