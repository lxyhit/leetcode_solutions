/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.length();
        if(length == 1){
            return false;
        }
        vector<int> result = findNextArray(s);
        int first = result[length - 1];
        int stride = first + 1;
        // 这里取余等于0排除了重复子串大于length/2的情况，此时可以证明下面的条件为重复子串的充分必要条件
        if((first != 0 || s.length() == 2) && length % (length - stride) == 0 && s[first] == s[length-1]){
            return true;
        }else{
            return false;
        }
    }
private:
    vector<int> findNextArray(string s){
        vector<int> result(s.length());
        int i = -1; int j = 0;
        result[0] = -1;
        while(j < s.length() - 1){
            if(i == -1 || s[i] == s[j]){
                i++;
                j++;
                result[j] = i;
            }else{
                i = result[i];
            }
        }
        return result;
    }
};
// @lc code=end

