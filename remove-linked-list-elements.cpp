#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x= 0)
        : val(x), next(nullptr)
    { }
};

class Solution {

    public:
        ListNode* removeElements(ListNode* head, int val) {

            if(head == NULL)
                return head;

            head->next= removeElements(head->next, val);

            if(head->val == val)
                return head->next;

            else return head;
        }
};

int main( ) {

    exit(0);
}