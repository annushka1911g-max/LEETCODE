class Solution {
public:
    unordered_set<string> result;

    void solve(string &s, int index,
               int leftCount, int rightCount,
               int leftRemove, int rightRemove,
               string current) {

        
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 &&
                leftCount == rightCount) {
                result.insert(current);
            }
            return;
        }

        char c = s[index];

        
        if (c == '(' && leftRemove > 0) {
            solve(s, index + 1,
                  leftCount, rightCount,
                  leftRemove - 1, rightRemove,
                  current);
        }

        if (c == ')' && rightRemove > 0) {
            solve(s, index + 1,
                  leftCount, rightCount,
                  leftRemove, rightRemove - 1,
                  current);
        }

        
        if (c != '(' && c != ')') {
            solve(s, index + 1,
                  leftCount, rightCount,
                  leftRemove, rightRemove,
                  current + c);
        }
        else if (c == '(') {
            solve(s, index + 1,
                  leftCount + 1, rightCount,
                  leftRemove, rightRemove,
                  current + c);
        }
        else {
           
            if (rightCount < leftCount) {
                solve(s, index + 1,
                      leftCount, rightCount + 1,
                      leftRemove, rightRemove,
                      current + c);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0, 0, 0,
              leftRemove, rightRemove, "");

        return vector<string>(result.begin(), result.end());
    }
};