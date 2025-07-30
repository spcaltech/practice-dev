#include <string>
#include <vector>

class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";

        return trim(helper(num));
    }

private:
    const std::vector<std::string> below20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    const std::vector<std::string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    const std::vector<std::string> thousands = {
        "", "Thousand", "Million", "Billion"
    };

    std::string helper(int num) {
        if (num == 0) return "";

        std::string result;
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                result = convertLessThan1000(num % 1000) + (thousands[i].empty() ? "" : " " + thousands[i]) + 
                         (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            ++i;
        }

        return result;
    }

    std::string convertLessThan1000(int num) {
        if (num == 0) return "";
        else if (num < 20) return below20[num];
        else if (num < 100) {
            return tens[num / 10] + (num % 10 ? " " + below20[num % 10] : "");
        } else {
            return below20[num / 100] + " Hundred" + (num % 100 ? " " + convertLessThan1000(num % 100) : "");
        }
    }

    std::string trim(const std::string& str) {
        int left = 0, right = str.size() - 1;
        while (left < str.size() && str[left] == ' ') ++left;
        while (right >= 0 && str[right] == ' ') --right;
        return str.substr(left, right - left + 1);
    }
};
