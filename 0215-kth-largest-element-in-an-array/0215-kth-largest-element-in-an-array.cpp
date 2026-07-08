class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

            priority_queue<int, vector<int>, greater<int>> minHeap;

     //insert first k elements

    for(int i = 0; i < k; i++)
    {
        minHeap.push(nums[i]);
    }

    // remaining elements

    for (int i = k; i<nums.size(); i++)

    {
        if (nums[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

       return minHeap.top();
    }

};