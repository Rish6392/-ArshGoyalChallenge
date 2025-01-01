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
