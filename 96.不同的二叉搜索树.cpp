/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n<=2) return n;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<=n; i++){
            dp[i] = 0;
            if((i-1)%2 == 0){
                int times = (i - 1) /2 - 1;
                for(int j = 0; j<=times; j++){
                    dp[i] += dp[j]*dp[i-1-j]*2; 
                }
                dp[i] += dp[(i - 1) /2]*dp[(i - 1) /2];
            }else{
                int times = (i - 1) /2;
                for(int j = 0; j<=times; j++){
                    dp[i] += dp[j]*dp[i-1-j]*2; 
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

