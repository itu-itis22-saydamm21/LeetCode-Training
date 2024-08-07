class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string result;
        int index = 0;
        
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000, below_20, tens) + (thousands[index].empty() ? "" : " " + thousands[index]) + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            index++;
        }
        
        return result;
    }
    
private:
    string helper(int num, vector<string>& below_20, vector<string>& tens) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return below_20[num];
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 != 0 ? " " + below_20[num % 10] : "");
        } else {
            return below_20[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100, below_20, tens) : "");
        }
    }
};

