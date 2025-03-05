/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.58%)
 * Likes:    4653
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 4.7M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([])"
 * 
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> kind1;
        for(int tag = 0; tag < s.length(); tag++){
            if(s[tag] == '(' || s[tag] == '[' || s[tag] == '{'){
                    kind1.push(s[tag]);
            }else{
                // 防止pop一个空的栈
                if(kind1.size()==0)
                    return false;
                char right = s[tag];
                char left = kind1.top();
                // 正确的顺序闭合的意思是当检测到一个右括号的时候其相邻的左括号一定是相对应匹配的
                if((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')){
                    kind1.pop();
                    continue;
                }
                return false;
            }
        }
        if(kind1.size() == 0){
            return true;
        }
        return false;
    }
};
// @lc code=end

