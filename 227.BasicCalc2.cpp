#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stk;
        int num = 0;
        char op = '+'; // Default operator before first number

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Build number
            }

            // If non-digit OR end of string
            if ((!isdigit(ch) && !isspace(ch)) || i == s.size() - 1) {
                if (op == '+') {
                    stk.push(num);
                } else if (op == '-') {
                    stk.push(-num);
                } else if (op == '*') {
                    int tmp = stk.top(); stk.pop();
                    stk.push(tmp * num);
                } else if (op == '/') {
                    int tmp = stk.top(); stk.pop();
                    stk.push(tmp / num); // Integer division
                }

                op = ch;
                num = 0;
            }
        }

        // Sum up the stack
        int result = 0;
        while (!stk.empty()) {
            result += stk.top(); stk.pop();
        }
        return result;
    }
};
