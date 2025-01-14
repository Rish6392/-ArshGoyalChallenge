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


