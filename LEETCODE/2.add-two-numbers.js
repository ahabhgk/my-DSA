/*
 * @lc app=leetcode id=2 lang=javascript
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.90%)
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
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let first = l1, second = l2
  const head = new ListNode(0)
  let cur = head

  while (first || second) {
    first = first ? first : new ListNode(0)
    second = second ? second : new ListNode(0)
    const sum = first.val + second.val + cur.val
    if (sum >= 10) {
      cur.next = new ListNode(1)
    } else {
      if (first.next || second.next) {
        cur.next = new ListNode(0)
      }
    }
    cur.val = sum % 10
    first = first.next
    second = second.next
    cur = cur.next
  }

  return head
};
// @lc code=end

