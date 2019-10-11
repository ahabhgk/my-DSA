/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.95%)
 * Likes:    6114
 * Dislikes: 1590
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while (l1 != NULL || l2 != NULL) {
      l1 = l1 == NULL ? new ListNode(0) : l1;
      l2 = l2 == NULL ? new ListNode(0) : l2;
      int sum = l1->val + l2->val + cur->val;
      if (sum >= 10) {
        cur->next = new ListNode(1);
      } else {
        if (l1->next != NULL || l2->next != NULL) 
          cur->next = new ListNode(0);
      }
      cur->val = sum % 10;
      cur = cur->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    return head;
  }
};
// @lc code=end

