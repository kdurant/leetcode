/*
不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);        
hashSet.add(2);        
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)

注意：

所有的值都在 [1, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int max;
    int cnt;
    int hashset[10000];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate()
{
    MyHashSet* hashset = NULL;
    hashset            = (MyHashSet*)malloc(sizeof(MyHashSet));

    if(hashset)
    {
        hashset->max = 0;
        hashset->cnt = 0;
        memset(hashset->hashset, 0, sizeof(hashset->hashset));
    }
    return hashset;
}

void myHashSetAdd(MyHashSet* obj, int key)
{
    int count = obj->max;
    for(int i = 0; i < count; i++)
    {
        if(key == obj->hashset[i])
            return;
    }

    obj->hashset[count] = key;
    obj->cnt++;
    obj->max++;
}

void myHashSetRemove(MyHashSet* obj, int key)
{
    int count = obj->max;
    for(int i = 0; i < count; i++)
    {
        if(key == obj->hashset[i])
        {
            obj->hashset[i] = 0;
            break;
        }
    }
    obj->cnt--;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key)
{
    int count = obj->max;

    for(int i = 0; i < count; i++)
    {
        if(key == obj->hashset[i])
            return true;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj)
{
    if(obj)
        free(obj);
}

/*
["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
[   [],       [1],  [2],   [1],       [3],      [2],    [2],      [2],     [2]]
[  null,      null, null,  true,      false,    null,  true,     null,     false]
 */
int main(void)
{
    MyHashSet* HashSet = NULL;
    HashSet            = myHashSetCreate();

    if(HashSet == NULL)
    {
        printf("create HashSet err\n");
        return 0;
    }

    myHashSetAdd(HashSet, 1);
    myHashSetAdd(HashSet, 2);

    printf("%d \n", myHashSetContains(HashSet, 1));
    printf("%d \n", myHashSetContains(HashSet, 3));

    myHashSetAdd(HashSet, 2);
    printf("%d \n", myHashSetContains(HashSet, 2));

    myHashSetRemove(HashSet, 2);
    printf("%d \n", myHashSetContains(HashSet, 2));

    myHashSetFree(HashSet);

    return 0;
}

