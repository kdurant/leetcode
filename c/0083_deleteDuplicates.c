/*
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode * phead = head;
    while(head->next != NULL && head != NULL)
    {
        if(head->val == head->next->val)
        {
            head->next = head->next->next;
        }
        else
            head = head->next;
    }
    return phead;
}