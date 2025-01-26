//1385. Find the Distance Value Between Two Arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(int i =0;i<arr1.size();i++){
            bool valid=true;

            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    valid= false;
                }
            }
            if(valid){
                ans++;
            }
        }
        
        return ans;
        
    }
};

//455. Assign Cookies
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};

//2958. Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = 0;
        unordered_map<int, int> frequency;
        
        for (int end = 0; end < nums.size(); end++) {
            frequency[nums[end]]++;
            
            while (frequency[nums[end]] > k) {
                frequency[nums[start]]--;  // Decrement the frequency before moving the start pointer
                start++;
            }
            
            ans = max(ans, end - start + 1);  // Update the max length of the valid subarray
        }
        
        return ans;
    }
};


