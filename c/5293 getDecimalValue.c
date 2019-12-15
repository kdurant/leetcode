/*
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

 

示例 1：



输入：head = [1,0,1]
输出：5
解释：二进制数 (101) 转化为十进制数 (5)
示例 2：

输入：head = [0]
输出：0
示例 3：

输入：head = [1]
输出：1
示例 4：

输入：head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
输出：18880
示例 5：

输入：head = [0,0]
输出：0
 

提示：

链表不为空。
链表的结点总数不超过 30。
每个结点的值不是 0 就是 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer
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

int getDecimalValue(struct ListNode* head)
{
    int stack[30];
    int index = 0;
    int i;

    int result = 0;
    while(head != NULL)
    {
        stack[index] = head->val;
        head         = head->next;
        index++;
    }
    index--;
    for(i = index; i >= 0; i--)
    {
        result += stack[i] << (index - i);
    }
    return result;
}

int main()
{
    struct ListNode* l1;
    list_init(&l1);
    list_append(&l1, 1);
    list_append(&l1, 0);
    list_append(&l1, 1);
    list_append(&l1, 1);

    printf("%d\n", getDecimalValue(l1->next));
    return 0;
}