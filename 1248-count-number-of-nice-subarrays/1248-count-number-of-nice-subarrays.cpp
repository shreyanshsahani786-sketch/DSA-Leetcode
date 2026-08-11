class Solution {
public:

    int atMost(vector<int>& nums, int k) {

        if(k < 0)
            return 0;

        int left = 0;
        int oddCount = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Count odd numbers ke liye
            if(nums[right] % 2 == 1)
                oddCount++;

            // Shrink window 
            while(oddCount > k) {

                if(nums[left] % 2 == 1)
                    oddCount--;

                left++;
            }

            // Count valid subarrays
            ans += (right - left + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};