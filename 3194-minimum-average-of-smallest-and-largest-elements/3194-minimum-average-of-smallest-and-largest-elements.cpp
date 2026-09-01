class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        int minSum = INT_MAX;

        while (left < right) {

            int sum = nums[left] + nums[right];

            minSum = min(minSum, sum);

            left++;
            right--;
        }

        return minSum / 2.0;
    }
};