// 1(168. Excel Sheet Column Title)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber > 0){
            columnNumber--;
            result = char(columnNumber % 26+'A')+result;
            columnNumber/=26;
        }
        return result;
    }
};

//2(2461. Maximum Sum of Distinct Subarrays With Length K)


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long x=0;

        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            x+=nums[i];

            // if the window exceeds k,remove the leftmost element
            if(i>=k){
                mp[nums[i-k]]--;
                 if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            x-=nums[i-k];
            }
           //check if the current window has exactly k element
           if(mp.size()==k){
            ans=max(ans,x);
           }
        }

        return ans;
    }
};

//3(387. First Unique Character in a String)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq; // Map to store frequency of characters
        
        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Find the index of the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1; // No unique character found
    }
};
