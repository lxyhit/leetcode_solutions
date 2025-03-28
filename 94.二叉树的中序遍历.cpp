/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (77.80%)
 * Likes:    2210
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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

#include<vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        stack<TreeNode*> tag;
        if(root == nullptr){
            return a;
        }else{
            TreeNode* cur = root;
            while(cur != nullptr || !tag.empty()){
                if(cur != nullptr){
                    tag.push(cur);
                    cur = cur->left;
                }else{
                    cur = tag.top();
                    tag.pop();
                    a.push_back(cur->val);
                    cur = cur->right;
                }
            }
            return a;
        }
    }
    // void traverse(vector<int> &a, TreeNode* root){
    //     if (root != nullptr){
    //         traverse(a,root->left);
    //         a.push_back(root->val);
    //         traverse(a,root->right);
    //     }
    // }
};
// @lc code=end

