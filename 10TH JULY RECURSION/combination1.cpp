#include <bits/stdc++.h>
using namespace std;

void findcombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds)
{
    if (ind == arr.size())
        return;

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findcombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    findcombination(ind + 1, target, arr, ans, ds);
}

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> ds;

        findcombination(0, target, candidates, ans, ds);
        return ans;
    }
};