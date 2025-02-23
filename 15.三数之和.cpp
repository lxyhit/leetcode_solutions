/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(nums[0] > 0){ 
                return result;
            }
            // 这里不能让i=0，不然会出现问题
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = length - 1;
            while(k > j){
                if(nums[i] + nums[j] + nums[k] == 0){
                    result.push_back({nums[i] , nums[j] , nums[k]});
                    // 注意这里判断条件两个条件不能反不然j = k时会越界
                    while(j < k &&(nums[j] == nums[j+1])){
                        j++;
                    }
                    while((nums[k] == nums[k-1]) && j < k){
                        k--;
                    }
                    j++;
                    k--;
                }else{
                    if(nums[i] + nums[j] + nums[k] > 0 ){
                        k--;
                    }
                    if(nums[i] + nums[j] + nums[k] < 0 ){
                        j++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

