/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (57.67%)
 * Likes:    657
 * Dislikes: 0
 * Total Accepted:    348.8K
 * Total Submissions: 600.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.length();
        int tag = length / (2*k);
        int remains = length - tag * 2 * k;
        for(int j = 0; j < tag; j++){
            int start = j*2*k;
            int end = start + (k-1);
            // for(int i = 0; i < k/2; i++){
            //     char middle;
            //     middle = s[start + i];
            //     s[start + i] = s[end - i];
            //     s[end - i] = middle;
            // }
            // reverse比较快
            reverse(s.begin()+start,s.begin()+end+1);
        }
        if(remains >= k && remains < 2 * k){
            int start = length - remains;
            int end = start + (k-1);
            for(int i = 0; i < k/2; i++){
                char middle;
                middle = s[start + i];
                s[start + i] = s[end - i];
                s[end - i] = middle;
            }
        }else{
            int start = length - remains;
            int end = length - 1;
            for(int i = 0; i < remains/2; i++){
                char middle;
                middle = s[start + i];
                s[start + i] = s[end - i];
                s[end - i] = middle;
            }
        }
        return s;
    }
};
// @lc code=end

