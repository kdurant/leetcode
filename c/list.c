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
 * 链表声明使用的是 struct ListNode * list;
 * list的值是某个struct ListNode的地址
 * 如果
 *
 * @param l
 * @return true
 * @return false
 */

bool list_init(struct ListNode** l)
{
    // 给头结点申请内存空间
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(p == NULL)
        return false;
    else
    {
        p->next = NULL;
        // 二级指针, 修改l指向的内存地址
        *l = p;
    }

    return true;
}

bool list_append(struct ListNode** l, int node)
{
    /**
     * @brief LinkList *q = l;
     *
     */
    struct ListNode* q = *l;  // q指向头结点
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(p == NULL)
        return false;
    else
    {
        p->val  = node;
        p->next = NULL;
        while(q != NULL)
        {
            if(q->next == NULL)
                break;
            else
                q = q->next;
        }
        q->next = p;
    }

    return true;
}

/**
 * @brief 203. 移除链表元素 删除链表中等于给定值 val 的所有节点。
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * 没有头结点的链表
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 1, 2
 * @param head
 * @param val
 * @return struct ListNode*
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if(!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

/**
 * @brief  0206 翻转链表https://leetcode-cn.com/problems/reverse-linked-list
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

/**
 * @brief 0083 删除排序链表中的重复元素
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * @param head
 * @return struct ListNode*
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    struct ListNode* phead = head;
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

void deleteNode(struct ListNode* node)
{
    *node = *(node->next);
}

/**
 * @brief 0021 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 *
 * 合并的是没有头结点的链表
 * @param l1
 * @param l2
 * @return struct ListNode*
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    // struct ListNode *head = malloc(sizeof(struct ListNode));
    // struct ListNode *head = (l1->val <= l2->val) ? l1 : l2;

    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    struct ListNode* head;
    if(l1->val <= l2->val)
    {
        head = l1;
        l1   = l1->next;
    }
    else
    {
        head = l2;
        l2   = l2->next;
    }

    struct ListNode* result = head;

    while((l1 != NULL) && (l2 != NULL))
    {
        if(l1->val <= l2->val)
        {
            head->next = l1;
            l1         = l1->next;
            head       = head->next;
        }
        else
        {
            head->next = l2;
            l2         = l2->next;
            head       = head->next;
        }
    }
    if(l1 == NULL)
        head->next = l2;

    if(l2 == NULL)
        head->next = l1;
    return result;
}

/**
 * @brief 876. 链表的中间结点
 * https://leetcode-cn.com/problems/middle-of-the-linked-list/
 * @param head
 * @return struct ListNode*
 */
struct ListNode* middleNode(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    // head = head->next;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    struct ListNode* l1;
    struct ListNode* l2;
    list_init(&l1);
    list_append(&l1, 1);
    list_append(&l1, 2);
    list_append(&l1, 6);
    list_append(&l1, 3);
    list_append(&l1, 4);
    list_append(&l1, 5);
    list_append(&l1, 6);
    struct ListNode* r = removeElements(l1->next, 6);
    // middleNode(l1);

    // list_init(&l2);
    // list_append(&l2, 2);
    // list_append(&l2, 4);
    // list_append(&l2, 6);

    // struct ListNode *r = mergeTwoLists(l1->next, l2->next);

    // struct ListNode *r = removeElements(l1->next, 6);;
    while(r)
    {
        printf("%d\t", r->val);
        r = r->next;
    }
}