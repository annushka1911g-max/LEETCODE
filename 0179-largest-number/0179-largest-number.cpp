class Solution {
public:
    static bool compare(string &a, string &b)
    {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums)
    {
        vector<string> arr;

        // Convert integers to strings
        for (int num : nums)
        {
            arr.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(arr.begin(), arr.end(), compare);

        // If the largest element is 0,
        // then all elements are 0
        if (arr[0] == "0")
            return "0";

        string ans = "";

        // Concatenate all strings
        for (string s : arr)
        {
            ans += s;
        }

        return ans;
    }
};