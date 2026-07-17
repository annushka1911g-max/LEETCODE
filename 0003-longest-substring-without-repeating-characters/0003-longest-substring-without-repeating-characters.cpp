class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++)
        {
            // Duplicate character found inside current window
            if (lastSeen.count(s[right]) &&
                lastSeen[s[right]] >= left)
            {
                left = lastSeen[s[right]] + 1;
            }

            // Update last occurrence
            lastSeen[s[right]] = right;

            // Update answer
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};