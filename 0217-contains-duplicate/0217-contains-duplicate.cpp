class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // Duplicate found
            if (seen.find(num) != seen.end()) {
                return true;
            }

            // Store the number
            seen.insert(num);
        }

        return false;
    }
};