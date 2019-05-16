/*
https://leetcode-cn.com/problems/merge-two-sorted-lists/

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 还有递归版本需要实现
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;
        
    struct ListNode *head;
    if(l1->val <= l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    
    struct ListNode *result = head;


    while( (l1 != NULL) && (l2 != NULL) )
    {
        if(l1->val <= l2->val)
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
    }
    if(l1 == NULL)
        head->next = l2;
    
    if(l2 == NULL)
        head->next = l1;
    return result;
}
