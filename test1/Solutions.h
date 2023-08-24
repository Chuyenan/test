//
// Created by 14911 on 2023/8/19.
//

#ifndef TEST_SOLUTIONS_H
#define TEST_SOLUTIONS_H

#include <vector>
using namespace std;

vector<vector<int>> nSum(vector<int>& nums, int pos, int target, int n) {
    if (n == 1) {
        while (pos < nums.size()) {
            if (nums[pos] == target) {
                return {{nums[pos]}};
            }
            ++pos;
        }
        return {};
    }
    if (pos >= nums.size()) {
        return {};
    }
    vector<vector<int>> res;
    for (int i = pos; i < nums.size(); ++i) {
        auto tmp = nSum(nums, i + 1, target - nums[i], n - 1);
        for (auto t : tmp) {
            t.emplace_back(nums[i]);
            res.emplace_back(t);
        }
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
    }
    return res;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    return nSum(nums, 0, target, 4);
}
void sumHelper() {
    vector<int> a = {1,0,-1,0,-2,2};
    auto res = fourSum(a, 0);
    for (const auto& i: res) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

#endif //TEST_SOLUTIONS_H
