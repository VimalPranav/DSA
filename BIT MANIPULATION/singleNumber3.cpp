#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums){
        int n = nums.size();
        int XOR = 0;
        f(i,n){
            XOR ^= nums[i];
        }
        int r = (XOR & (XOR - 1)) ^ XOR;
        int a = 0, b = 0;
        f(i,n){
            if(nums[i] & r){
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    numbers in the given array */
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}