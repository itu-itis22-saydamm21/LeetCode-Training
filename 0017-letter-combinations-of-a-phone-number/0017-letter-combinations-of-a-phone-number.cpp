#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
public:
    void backtrack(const string& digits, int index, const string& current_combination, const vector<string> &digit_to_char, vector<string>& result){
        if(index == digits.length()){
            result.push_back(current_combination);
            return;
        }

        char current_digit = digits[index];
        const string &letters = digit_to_char[current_digit - '0'];
        for(char letter : letters){
            backtrack(digits, index + 1, current_combination + letter, digit_to_char, result);
        }
    }
    vector<string> letterCombinations(string digits){
        if (digits.empty()) return {};

        vector<string> digit_to_char = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> result;

        backtrack(digits, 0 , "" , digit_to_char, result);
        return result;
        
    }
};