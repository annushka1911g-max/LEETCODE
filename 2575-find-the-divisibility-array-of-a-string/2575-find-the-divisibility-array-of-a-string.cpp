class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long remainder = 0;

        for (char ch : word) {
            int digit = ch - '0';
            remainder = (remainder * 10 + digit) % m;

            if (remainder == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }

        return ans;
    }
};