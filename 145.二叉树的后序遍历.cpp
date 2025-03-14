/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (77.32%)
 * Likes:    1227
 * Dislikes: 0
 * Total Accepted:    882.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 
 * 输出：[3,2,1]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 * 
 * 输出：[4,6,7,5,2,9,8,3,1]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 
 * 输出：[]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [1]
 * 
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;
        stack<TreeNode*> tag;
        TreeNode* cur = root;
        if(cur) tag.push(cur);
        else return result;
        while(!tag.empty()){
            cur = tag.top();
            tag.pop();
            result.push_back(cur->val);
            if(cur->left) tag.push(cur->left);
            if(cur->right) tag.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

