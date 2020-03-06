```cpp
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */

/**
 * @brief 思路简单，但不满足算法复杂度要求
 *
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> node_set;
        while(headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }

        while(headB)
        {
            if(node_set.find(headB) != node_set.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
```