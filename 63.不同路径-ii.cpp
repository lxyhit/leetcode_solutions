/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (42.12%)
 * Likes:    1388
 * Dislikes: 0
 * Total Accepted:    604.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m -
 * 1][n - 1]）。机器人每次只能向下或者向右移动一步。
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
 * 
 * 返回机器人能够到达右下角的不同路径数量。
 * 
 * 测试用例保证答案小于等于 2 * 10^9。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int length = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<vector<int>> dp(length, vector<int>(width));
        bool tag = false;
        for(int i = 0; i < length; i++){
            if(!tag){
                if(obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
                else{
                    tag = true;
                    dp[i][0] = 0;
                }
            }else{
                dp[i][0] = 0;
            }
        }
        tag = false;
        for(int i = 0; i < width; i++){
            if(!tag){
                if(obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
                else{
                    tag = true;
                    dp[0][i] = 0;
                }
            }else{
                dp[0][i] = 0;
            }
        }
        if(length > 1 && width > 1){
            for(int i = 1; i < length; i++){
                for(int j = 1; j < width; j++){
                    if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[length-1][width-1];
    }
};
// @lc code=end

