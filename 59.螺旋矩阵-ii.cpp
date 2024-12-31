#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        int number = 1;
        for(int round = 0; round < n/2; round++){
            //注意点1：这里不能全写满，应该左闭右开或者左开右闭
            for(int i = round; i < n-round-1; i++){
                result[round][i] = number;
                number ++;
            }
            for(int i = round; i < n-round-1; i++){
                result[i][n-round-1] = number;
                number ++;
            }
            for(int i = n-round-1; i> round; i--){
                result[n-round-1][i] = number;
                number ++;
            }
            for(int i = n-round-1; i> round; i--){
                result[i][round] = number;
                number ++;
            }
        }
        // 注意点2:这里需要额外进行判断
        if( n%2 != 0){
            result[n/2][n/2] = number;
        }
        return result;
    }
};
// @lc code=end

