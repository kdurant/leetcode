/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
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
struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    struct ListNode* tmp;
    struct ListNode* prev = NULL;
    while(head)
    {
        tmp        = head->next;  // 先保存下一个结点的地址, 防止丢失链表信息
        head->next = prev;        // 将当前head 插入到 prev 前面
        prev       = head;        // prev 和 head一样
        head       = tmp;         // 链表可以继续迭代
    }
    return prev;
}
