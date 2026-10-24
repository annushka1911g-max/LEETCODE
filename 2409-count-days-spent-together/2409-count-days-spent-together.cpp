
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        vector<int> days = {0, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto toDay = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 1; i < month; i++) {
                day += days[i];
            }

            return day;
        };

        int aStart = toDay(arriveAlice);
        int aEnd   = toDay(leaveAlice);
        int bStart = toDay(arriveBob);
        int bEnd   = toDay(leaveBob);

        int start = max(aStart, bStart);
        int end   = min(aEnd, bEnd);

        return max(0, end - start + 1);
    }
};
