//
// Created by greg on 19-4-27.
//

#include <iostream>
using namespace std;

/**
 * 	输入: 7->1->6->null, 5->9->2->null
	输出: 2->1->9->null

 	样例解释:
	617 + 295 = 912
	912 转换成链表:  2->1->9->null
 * */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val):val(val), next(nullptr){};
};

int getVariable(ListNode* &l){
    int x = 0;
    if (l!= nullptr){
        x = l->val;
        l = l->next;
    }
    return x;
}

ListNode * addLists(ListNode * l1, ListNode * l2) {
    // write your code here
    int x = 0, y = 0, sum = 0, carry = 0;
    ListNode* h = new ListNode(0), *tmp = h;
    while (l1!= nullptr || l2!= nullptr){
        x = getVariable(l1);
        y = getVariable(l2);
        sum = carry + x + y;
        tmp->next = new ListNode(sum%10);
        tmp = tmp->next;

        carry = sum / 10;
    }

    if (carry > 0){
        tmp->next = new ListNode(carry%10);
    }
    return h->next;
}

ListNode * addLists1(ListNode * l1, ListNode * l2) {
    // write your code here
    int x = 0, y = 0, sum = 0, carry = 0;
    ListNode* h = nullptr, **t = &h;     // 不同上面的写法 *t=h
    while (l1!= nullptr || l2!= nullptr){
        x = getVariable(l1);
        y = getVariable(l2);
        sum = carry + x + y;
        ListNode* node = new ListNode(sum%10);
        *t = node;
        t = (&node->next);

        carry = sum / 10;
    }

    if (carry > 0){
        ListNode* node = new ListNode(carry%10);
        *t = node;
    }
    return h->next;
}

int main(){
    int arr1[] = {1, 6, 3};
    ListNode* l1 = new ListNode(arr1[0]), *tmp = l1;
    for (int i=1; i<3; i++){
        tmp->next = new ListNode(arr1[i]);
        tmp = tmp->next;
    }

    int arr2[] = {4, 5, 6};
    ListNode* l2 = new ListNode(arr2[0]);
    tmp = l2;
    for (int i=1; i<3; i++){
        tmp->next = new ListNode(arr2[i]);
        tmp = tmp->next;
    }

    ListNode* res = addLists1(l1, l2);
    while (res!= nullptr){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;

    return 0;
}