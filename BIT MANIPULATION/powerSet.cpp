#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> getPowerSet(vector<int>& nums) {
        int n = nums.size();
        int k = 1<<n;
        vector<vector<int>> ans;
        f(i,k){
            vector<int> s;
            f(j,n){
                if(i & 1<<j){ s.push_back(nums[j]); }
            }
            ans.push_back(s);
        }
        return ans;
    }
};

int main() {
    // Input array
    vector<int> nums = {5, 7, 8};

    // Create object of Solution
    Solution obj;

    // Call function to generate subsets
    vector<vector<int>> subsets = obj.getPowerSet(nums);

    // Print original input array
    cout << "Initial Input Array: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Print all subsets
    cout << "Subsets: " << endl;
    for (auto subset : subsets) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}