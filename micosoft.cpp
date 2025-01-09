// 1(easy- Image Smoother)

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image
        int m = img.size();
        int n = img[0].size();

        // Create a new image of the same dimension as the input image.
        vector<vector<int>> ans(m, vector<int>(n));

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all possible nine indicies
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // if the indicies from valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                // store the rounded down value in ans[i][j].
                ans[i][j] = sum / count;
            }
        }

        return ans;
    }
};


// 2 (medium - 462. Minimum Moves to Equal Array Elements II)


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Sort the array to find the median
        sort(nums.begin(), nums.end());

        // Find the median
        int median = nums[n / 2];

        // Calculate the total moves required to make all elements equal to the median
        for (int i = 0; i < n; i++) {
            ans += abs(nums[i] - median);
        }

        return ans;
    }
};



// 3(medium--Wiggle Sort)


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Create a temporary array to store the wiggle sorted result
        vector<int> temp = nums;
        
        // Step 3: Fill the array in wiggle order
        int mid = (n - 1) / 2; // Middle element
        int end = n - 1;       // Last element
        int index = 0;         // Index for filling `nums`
        
        // Fill odd indices with the smaller half (reversed)
        for (int i = mid; i >= 0; --i) {
            nums[index] = temp[i];
            index += 2;
        }
        
        // Fill even indices with the larger half (reversed)
        index = 1;
        for (int i = end; i > mid; --i) {
            nums[index] = temp[i];
            index += 2;
        }
    }
};


// 4 (easy -Count the Number of Incremovable Subarrays I)


class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool flag = true;
                int last = -1;

                for (int k = 0; k < i; k++) {
                    if (last >= nums[k]) {
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }

                for (int k = j + 1; k < n; k++) {
                    if (last >= nums[k]) {
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }

                if (flag) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


// 5 (medium - find the winner of the circular game)

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        
        int startindex=0;

        while(circle.size()>1){
            int removalindex = (startindex+k-1)%circle.size();

            circle.erase(circle.begin()+removalindex);

            startindex=removalindex;
        }

        

        return circle.front(); // returns remaining element in the circle
    }
};


//6(medium - count number of nice subarray)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarray =0, initialgap =0,qsize =0,start=0;
        for(int end =0;end<nums.size();end++){
            //if current element is odd,increament qsize by 1.
            if(nums[end]%2==1){
                qsize++;
            }
            // if qsize is k ,calculate initialgap and add it to the answer
            if(qsize ==k){
                initialgap =0;
                //calculate the number of even elements in the beginning of subarray
                while(qsize ==k){
                    qsize-=nums[start]%2;
                    initialgap++;
                    start++;
                }
            }
            subarray+=initialgap;
        }
        return subarray;
    }
};

//7(187. Repeated DNA Sequences)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mpp;
        for(int i=0;i+10<=s.length();i++){
            mpp[s.substr(i,10)]++;
        }

        for(auto& i:mpp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
       return ans;

    }
};
