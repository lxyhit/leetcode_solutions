/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.62%)
 * Likes:    2109
 * Dislikes: 0
 * Total Accepted:    541.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num: nums){
            sum+=num;
        }
        // 通过两个定值算出正值的和也是定值，转换为背包问题
        if((sum + target) % 2 != 0 || sum + target < 0) return 0;
        int positive = (sum + target) / 2;
        // 背包的意义是种类数
        vector<int> dp(positive+1, 0);
        // 注意这里是大小为0的背包在放第0个物品时由一种放法
        dp[0] = 1;
        for(int i = 0; i< nums.size(); i++){
            for(int j = positive; j >= nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[positive];
    }
};
// @lc code=end

