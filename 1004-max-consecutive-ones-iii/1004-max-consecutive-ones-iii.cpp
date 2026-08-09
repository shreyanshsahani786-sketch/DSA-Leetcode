class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Expand window
            if (nums[right] == 0)
                zeroCount++;

            // Shrink window if invalid
            while (zeroCount > k) {

                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            if (zeroCount <= k)

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};