class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index, vector<int>& current) {
        // Add the current subset
        result.push_back(current);

        // Try including every remaining element
        for (int i = index; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);

            // Move to the next element
            backtrack(nums, i + 1, current);

            // Backtrack: remove the last element
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;

        backtrack(nums, 0, current);

        return result;
    }
};