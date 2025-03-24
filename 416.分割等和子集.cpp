/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 能转化为背包容量为sum(nums)/2的01背包问题，背包的价值就是背包中含有数的值的和
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum % 2 != 0) return false;
        int capcity = sum/2;
        vector<int> dp(capcity+1, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = capcity; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (capcity == dp[capcity]) return true;
        return false;
    }
};
// @lc code=end

