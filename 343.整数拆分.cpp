/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (64.39%)
 * Likes:    1463
 * Dislikes: 0
 * Total Accepted:    393.2K
 * Total Submissions: 609.8K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 
 * 返回 你可以获得的最大乘积 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                // 这里需要考虑dp[j] 和 j的大小关系，因为j = 1 * j但是dp[j]没考虑这种情况 
                int left = max(j, dp[j]);
                int right = max(i-j, dp[i-j]);
                dp[i] = max(dp[i], left * right);
            }
        }
        return dp[n];
    }
};
// @lc code=end

