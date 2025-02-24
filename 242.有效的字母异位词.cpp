/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (67.11%)
 * Likes:    974
 * Dislikes: 0
 * Total Accepted:    895.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
#include <string>;
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int array[26] = {0};
        int length_S = s.length()-1;
        int length_T = t.length()-1;
        for(int i = 0; i<= length_S; i++){
            array[s[i]-'a'] += 1;
        }
        for(int i = 0; i<= length_T; i++){
            array[t[i]-'a'] -= 1;
        }
        for(int i = 0; i< 26; i++){
            if(array[i]!=0) return false;
        }
        return true;
    }
};
// @lc code=end

