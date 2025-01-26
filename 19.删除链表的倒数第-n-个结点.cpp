/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (49.92%)
 * Likes:    3016
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tag = 1;
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;
        // 找到倒数第n+1个节点，这里计数时注意n为1时对应头节点所以n为n时对应第n个节点
        while (tag < n+1 && fastPointer!=nullptr)
        {
            fastPointer = fastPointer->next;
            tag++;
        }

        if(fastPointer==nullptr && tag == n+1){
            ListNode* actualHead = head->next;
            delete head;
            return actualHead;
        }else if(fastPointer==nullptr){
            //没有满足条件的点
            return head;
        }else{
            while(fastPointer->next!=nullptr){
                fastPointer = fastPointer->next;
                slowPointer = slowPointer->next;
            }
            ListNode *second = slowPointer->next;
            slowPointer->next = second->next;
            delete second;
            return head;
        }
    }
};

// AI修正后的结果
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // 1. 处理空链表
//         if (!head) return nullptr;
        
//         ListNode *fast = head;
//         ListNode *slow = head;
        
//         // 2. 快指针先走n步
//         for (int i = 0; i < n; i++) {
//             if (!fast) return head;  // n大于链表长度
//             fast = fast->next;
//         }
        
//         // 3. 如果fast为空,说明要删除头节点
//         if (!fast) {
//             ListNode* newHead = head->next;
//             delete head;
//             return newHead;
//         }
        
//         // 4. 同时移动快慢指针
//         while (fast->next) {
//             fast = fast->next;
//             slow = slow->next;
//         }
        
//         // 5. 删除目标节点
//         ListNode* toDelete = slow->next;
//         slow->next = toDelete->next;
//         delete toDelete;
        
//         return head;
//     }
// };
// @lc code=end

