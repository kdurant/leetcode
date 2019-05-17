/*
https://leetcode-cn.com/problems/remove-linked-list-elements/

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

没有头结点的链表
*/


struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode * discard;
	struct ListNode * pHead;
	while (head != NULL && head->val == val) {      // 列表就第一个节点就是要删除的值
        head = head->next;
    }
    if(head == NULL)
        return NULL;
    pHead = head;

    while(head->next)
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


struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}