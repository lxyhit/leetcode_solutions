/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (80.62%)
 * Likes:    939
 * Dislikes: 0
 * Total Accepted:    997.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int length =  s.size();
        for(int i = 0; i < length/2 ; i++){
            char tag;
            tag = s[i];
            s[i] = s[length-1-i];
            s[length-1-i] = tag;
        }
    }
};
// @lc code=end

