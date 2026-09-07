class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // left ko even tak le jao
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }

            // right ko even tak le jao
            while (left < right && nums[right] % 2 != 0) {
                right--;
            }

            // left = odd, right = even
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        return nums;
    }
};