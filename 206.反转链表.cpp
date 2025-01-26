/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.31%)
 * Likes:    3773
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 非递归解法
        // ListNode* first = head;
        // //注意这里当first为空时会直接报错
        // ListNode* second = head!=nullptr? head->next:nullptr;
        // if(first == nullptr || second == nullptr){
        //     return head;
        // }else{
        //     ListNode* tag = second->next;
        //     first->next = nullptr;
        //     while(tag!=nullptr){
        //         second->next = first;
        //         first = second;
        //         second = tag;
        //         tag = second->next;
        //     }
        //     second->next = first;
        //     return second;
        // }

        // 递归解法
        // 递归条件
        ListNode* first = head;
        ListNode* second = head!=nullptr? head->next:nullptr;
        if(first == nullptr || second == nullptr){
            return head;
        }else{
            ListNode* tag = second->next;
            second->next = first;
            first->next = nullptr;
            //如果最开头的逻辑和后面不一样可以为后面的逻辑新开一个递归函数
            return reverse(second,tag);
        }
    }
    ListNode* reverse(ListNode* head, ListNode* next) {
        if(next == nullptr){
            return head;
        }else{
            ListNode* tag = next->next;
            next->next = head;
            return reverse(next,tag);
        }
    }
};
// @lc code=end

