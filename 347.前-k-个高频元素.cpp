/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.52%)
 * Likes:    1971
 * Dislikes: 0
 * Total Accepted:    675.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 使用unordered_set统计元素数量，使用小根堆弹出不需要的元素
        unordered_map<int,int> map;
        for(int num: nums){
            if(map.find(num) == map.end()){
                map.insert({num,0});
            }else{
                // 通过->first获取元素
                map.find(num)->second ++;
            }
        }
        
        // priority_queue会把排序之后最后的元素放在最顶端，因此在这里就是最小的元素在最顶端
        priority_queue <pair<int,int>, vector<pair<int,int>>, mycomparsion> pri_que;

        for(auto it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            // 保持最大的k个元素
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> result;
        for(int i = 0 ; i < k; i++){
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return result;
    }
private:
    // 定义插入小根堆的比较器
    class mycomparsion{
        public:
            // 重载函数调用方法
            // lhs 和 rhs作用之后返回true那么lhs会到队列的最前面
            bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
                return lhs.second > rhs.second;
            }
    };
};
// @lc code=end

