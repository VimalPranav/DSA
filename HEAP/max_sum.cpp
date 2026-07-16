#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

vector<int> maxSum(vector<int> nums1, vector<int> nums2, int k){
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    priority_queue<pair<int, pair<int,int>>> pq;
    set<pair<int,int>> visited;
    pq.push({nums1[0]+nums2[0], {0, 0}});
    visited.insert(pq.top().second);
    vector<int> result;

    while(k-- && !pq.empty()){
        result.push_back(pq.top().first);
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if(i+1<nums1.size() && !visited.count({i+1, j})){
            pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            visited.insert({i+1, j});
        }
        if(j+1<nums2.size() && !visited.count({i, j+1})){
            pq.push({nums1[i]+nums2[j+1], {i, j+1}});
            visited.insert({i, j+1});
        }
    }
    return result;
}

int main(){
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {4, 6};
    int k = 2;

    vector<int> result = maxSum(nums1, nums2, k);
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}