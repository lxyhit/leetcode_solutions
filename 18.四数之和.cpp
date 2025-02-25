/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.66%)
 * Likes:    2031
 * Dislikes: 0
 * Total Accepted:    669.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> result;
        if(length < 4){
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= length - 4; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] > target/4){
                return result;
            }
            for(int j = i + 1; j <= length - 3; j++){
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j + 1;
                int l = length - 1; 
                while(l > k){
                    // 这里写成target - nums[i] - nums[j] - nums[k] - nums[l]可能会越界
                    // 这里转成 long long后没有此问题
                    if((long)target - (nums[i] + nums[j]) == nums[k]  + nums[l]){
                        result.push_back({nums[i] , nums[j] , nums[k] , nums[l]});
                        // 这里容易越界
                        while(k < l && nums[k] == nums[k+1])k++;
                        while(k < l && nums[l] == nums[l-1])l--;
                        k++;
                        l--;
                    }
                    else if ((long)target - (nums[i] + nums[j]) > nums[k] + nums[l]){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

