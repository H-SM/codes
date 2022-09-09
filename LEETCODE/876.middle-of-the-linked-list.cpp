/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
// @lc code=end

