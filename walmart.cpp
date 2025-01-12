//2099. Find Subsequence of Length K With the Largest Sum



class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> withIndex;
        for (int i = 0; i < nums.size(); i++) {
            withIndex.push_back({nums[i], i});
        }

        // Sort by value (descending)
        sort(withIndex.begin(), withIndex.end(), greater<>());

        // Select the largest `k` elements
        vector<int> indices;
        for (int i = 0; i < k; i++) {
            indices.push_back(withIndex[i].second);
        }

        // Sort indices to preserve original order
        sort(indices.begin(), indices.end());

        // Build the result
        vector<int> ans;
        for (int idx : indices) {
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};
