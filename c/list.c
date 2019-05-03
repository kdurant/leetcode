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
 * 链表声明使用的是 struct ListNode * list;
 * list的值是某个struct ListNode的地址
 * 如果
 * 
 * @param l 
 * @return true 
 * @return false 
 */

bool list_init(struct ListNode* * l)
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

bool list_append(struct ListNode* * l, int node)
{
    /**
     * @brief LinkList *q = l;
     * 
     */
	struct ListNode* q = *l;        // q指向头结点
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(p == NULL)
        return false;
    else
    {
		
        p->val = node;
        p->next = NULL;
		while ( q != NULL)
		{
			if (q->next == NULL)
				break;
			else
				q = q->next;
		}
        q->next = p;
    }

    return true;
}

/**
 * @brief 删除链表中等于给定值 val 的所有节点。
 * 
 * @param head 
 * @param val 
 * @return struct ListNode* 
 */
struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode * discard;
    struct ListNode * pHead = head;
	
	if(head == NULL)
		return NULL;


    while(head->next != NULL)
    {
        if(head->next->val == val)
        {
            discard = head->next;
            head->next = head->next->next;

            free(discard);
        }
        else
            head = head->next;
    }	

	return pHead;
}

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

void deleteNode(struct ListNode* node) {
    *node = *(node->next);
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

}
/**
 * @brief 反转一个单链表。
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * @return int 
 */
int main()
{
    struct ListNode * l;
    list_init(&l);
    list_append(&l, 1);
    list_append(&l, 1);
    list_append(&l, 2);
    list_append(&l, 3);
    // list_append(&l, 6);
    // removeElements(l, 6);
    deleteDuplicates(l);
    while(l)
    {
        printf("%d\t", l->val);
        l = l->next;
    }
}