/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (57.38%)
 * Likes:    1272
 * Dislikes: 0
 * Total Accepted:    703.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 * 
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // 整体思路：将整个字符串反转，再将每个单词反转。因为将开头和末尾的字符串反转较为麻烦。
        removeExtraSpaces(s);
        int start = 0;
        int end = s.size() - 1;
        reverseWords(s, start, end);
        for(int i = 0; i <= end; i++){
            if(i == end || s[i + 1] == ' ' ){
                reverseWords(s, start, i);
                start = i + 2;
            }
        }
        return s;
    }
private:
    // reverse的end不包括end，需要给下标加一
    void reverseWords(string &s, int start, int end){
        reverse(s.begin() + start, s.begin() + end + 1);
    }

    void removeExtraSpaces(string &s){
        int fastIndex = 0 , slowIndex = 0;
        int length = s.size();
        // 跳过前导空格
        while(fastIndex <= length-1 && s[fastIndex] == ' ') fastIndex++;
        for(; fastIndex <= length-1 ; fastIndex++){
            if(s[fastIndex] == ' ' && fastIndex != length-1 && s[fastIndex+1] == ' '){
                continue;
            }
            s[slowIndex++] = s[fastIndex];
        }
        // resize 指的是最终的字符个数
        if(s[slowIndex-1] == ' '){
            s.resize(slowIndex - 1);
        }else{
            s.resize(slowIndex);
        }
    }
};
// @lc code=end

