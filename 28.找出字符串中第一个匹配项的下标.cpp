/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (44.43%)
 * Likes:    2368
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.8M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> nextArray = calculateNextArray(needle);
        int length = needle.size();
        int i = 0; int j = 0;
        // 注意这里i也不能越界
        while(j < length && i < haystack.size()){
            if(j == -1 || haystack[i] == needle[j]){
                i++; j++;
            }else{
                j = nextArray[j];
            }
        }
        if(j == length){
            return i - length;
        }else{
            return -1;
        }
    }
private:
    vector<int> calculateNextArray(string a) {
        int length = a.size();
        vector<int> result(length);
        result[0] = -1;
        int j = 0; int i = -1;
        // 注意这里是length-1
        while(j < length - 1){
            if(i == -1 || a[i] == a[j]){
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

