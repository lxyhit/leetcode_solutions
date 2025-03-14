/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (64.80%)
 * Likes:    5574
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1){
            return 0;
        }
        int length = height.size();
        int i = 1;
        int result= 0;
        stack<int> stack1;
        stack1.push(0);
        // 单调栈
        for(i = 1; i < length; i++){
            if(height[i]<height[stack1.top()]){
                stack1.push(i);
            }else if(height[i]==height[stack1.top()]){
                // 中间只需要记录一次即可
                stack1.pop();
                stack1.push(i);
            }else{
                while(!stack1.empty() && height[i]>height[stack1.top()]){
                    int mid = stack1.top();
                    stack1.pop();
                    if(!stack1.empty()){
                        int h = min(height[i], height[stack1.top()]) - height[mid];
                        int l = i - stack1.top() - 1;
                        result += l*h;
                    }
                }
                stack1.push(i);
            }
        }
        return result;
    }
};
// @lc code=end

