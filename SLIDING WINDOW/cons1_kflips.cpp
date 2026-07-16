#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

int longest_substring(vector<int> nums, int k){
    int n = nums.size();
    int l = 0, r = 0;
    int maxi = 0;
    queue<int> q;
    
    f(i,n){
        if(nums[i] == 0){q.push(i);}
        if(q.size()>k){
            l = q.front() + 1;
            q.pop();
        }
        maxi = max(maxi, r-l+1);
        r++;
    }
    
    return maxi;
}

int main(){
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 3;
    
    cout<<longest_substring(nums, k)<<endl;

    return 0;
}