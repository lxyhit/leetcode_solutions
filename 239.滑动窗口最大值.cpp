/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.35%)
 * Likes:    3035
 * Dislikes: 0
 * Total Accepted:    783.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 从左向右滑动窗口寻找其中最大值的特点可以通过单调递减数列满足
        // 因为其只需要记录一组数中单调递减的是哪些，当窗口向右滑动时
        // 小于a[0]的数删去也不会有影响，但是需要记录小于最大值的数
        decreaseQueue queue;
        for(int i = 0; i < k ; i++){
            queue.push(nums[i]);
        }
        int length = nums.size() - 1;
        int tag = k;
        vector<int> result;

        result.push_back(queue.front());
        while(tag <= length){
            queue.push(nums[tag]);
            queue.pop(nums[tag - k]);
            result.push_back(queue.front());
            tag++;
        }
        return result;
    }


private:
    class decreaseQueue{
        public:
            // 不需要显式指明构造函数
            // 尝试从队列前端删除数据
            void pop(int front){
                // 相等也应该移除， 因为队列允许多个相同元素
                if(!queue.empty() && (front >= queue.front())){
                    queue.pop_front();
                }
            }

            void push(int back){
                while(queue.size() > 0 && queue.back() < back){
                    queue.pop_back();
                }
                queue.push_back(back);
            }

            // 获取队列前面的值，假定队列长度大于0
            int front(){
                return queue.front();
            }
        private:
            deque<int> queue;
    };
};
// @lc code=end

