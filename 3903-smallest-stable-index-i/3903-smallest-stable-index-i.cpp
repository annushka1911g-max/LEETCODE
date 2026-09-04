class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // right[i] = minimum value from i to n-1
        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        // Maximum value from 0 to i
        int leftMax = 0;

        for (int i = 0; i < n; i++) {

            leftMax = max(leftMax, nums[i]);

            int instability = leftMax - right[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};