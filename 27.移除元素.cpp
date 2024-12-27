#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 不能写成int start,end = 0;前一个值不会初始化
        int start = 0;
        int end = 0;
        // 快指针每次走1， 慢指针当快指针指向的值不等于val时前进并进行替换
        int size = nums.size();
        while(end < size){
            if(nums[end] != val){
                nums[start] = nums[end];
                start ++ ; 
            }
            end ++;
        }
        return start; 
    }
};
// @lc code=end

