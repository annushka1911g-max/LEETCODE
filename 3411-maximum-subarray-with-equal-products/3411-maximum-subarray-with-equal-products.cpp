
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        long long mx = *max_element(nums.begin(), nums.end());
        long long ml = 1;

       
        for (int x : nums) {
            ml = lcm(ml, (long long)x);
        }

       
        long long limit = mx * ml;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                
                if (prod > limit) {
                    break;
                }

                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
