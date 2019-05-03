/*
https://leetcode-cn.com/problems/reverse-linked-list/
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

/**
 * @brief 
 * 1. 保存head->next, 用作下一次迭代
 * 2. 将当前 head 插入到 prev 前面
 * 3. 当前head 变为 prev
 * 4. 将head->next当作head继续迭代
 * @param head 
 * @return struct ListNode* 
 */
struct ListNode* reverseList(struct ListNode* head){

    if(head == NULL)
        return NULL;
    struct ListNode * tmp;
    struct ListNode * prev = NULL;
    while(head)
    {
        tmp = head->next;   // 先保存下一个结点的地址, 防止丢失链表信息
        head->next = prev;  // 将当前head 插入到 prev 前面
        prev = head;        // prev 和 head一样
        head = tmp;         // 链表可以继续迭代

    }
    return prev;
}