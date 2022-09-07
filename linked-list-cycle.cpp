#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr)
    { }
};

//* using slow and fast pointer
class Solution {

    public:
        bool hasCycle(ListNode *head) {

            ListNode* slowPointer= head, *fastPointer= head;

            while(fastPointer != NULL && fastPointer->next != NULL && fastPointer->next->next != NULL) {
                fastPointer= fastPointer->next->next;
                slowPointer= slowPointer->next;

                if(fastPointer == slowPointer)
                    return true;
            }

            return false;
        }
};