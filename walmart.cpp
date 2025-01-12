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

// 532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> a;
        for (int i : nums) {
            a[i]++;
        }
        int ans = 0;
        for (auto x : a) {
            if (k == 0) {
                if (x.second > 1) {
                    ans++;
                }
            } else {
                if (a.find(x.first + k) != a.end()) { // avoid dupliacation
                    ans++;
                }
            }
        }
        return ans;
    }
};

/// 1208. Get Equal Substrings Within Budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int left = 0, right = 0;
        int cost = 0;
        int maxLength = 0;

        while (right < n) {
            // Add the cost of the current character
            cost += abs(s[right] - t[right]);
            right++;

            // If the cost exceeds maxCost, shrink the window from the left
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};

