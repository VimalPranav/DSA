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
    string findOrder(string dict[], int n, int k){
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int p = 0;
            while(p < s1.size() && p < s2.size() && s1[p] == s2[p]){
                p++;
            }
            if(p < s1.size() && p < s2.size()){
                adj[s1[p]-'a'].push_back(s2[p]-'a');
            }
        }
        stack<int> s;
        int vis[k] = {0};
        for(int i=0;i<k;i++){
            if(!vis[i]){
                dfs(i, adj, vis, s);
                s.push(i);
            }
        }
        string result = "";
        while(!s.empty()){
            result += (char)(s.top() + 'a');
            s.pop();
        }
        return result;
    }
};

int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string ans = obj.findOrder(dict, N, K);

    // Print result
    for (auto ch : ans) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}