/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 用虚拟节点来统一计算过程
        ListNode *dummyHead = new ListNode();  
        dummyHead->next = head;
        ListNode *cur;
        cur = dummyHead;
        while(cur!=nullptr){
            if(cur->next!=nullptr && cur->next->val==val){
                // 这里即使下下一个节点为空也没有问题
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// @lc code=end

