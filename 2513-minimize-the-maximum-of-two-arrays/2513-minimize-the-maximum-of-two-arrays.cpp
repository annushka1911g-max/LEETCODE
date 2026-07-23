class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int minimizeSet(int divisor1, int divisor2,
                    int uniqueCnt1, int uniqueCnt2) {

        long long l = 1;
        long long r = 1e18;

        long long L = (1LL * divisor1 * divisor2) /
                      gcd(divisor1, divisor2);

        while (l < r) {

            long long mid = l + (r - l) / 2;

            long long cnt1 = mid - mid / divisor1;
            long long cnt2 = mid - mid / divisor2;
            long long total = mid - mid / L;

            if (cnt1 >= uniqueCnt1 &&
                cnt2 >= uniqueCnt2 &&
                total >= (long long)uniqueCnt1 + uniqueCnt2)
                r = mid;
            else
                l = mid + 1;
        }

        return (int)l;
    }
};