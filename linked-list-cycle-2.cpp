#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr)
    { }
};

/*
    * Proof of Floyd's algorithm

    When the two pointers meet at the same point in the cyclic part,

    A + (x*C + B) = 2 * {A + (y*C + B)}

    => A + B= (x - y)*C

    => A + B= k*C

    After the 2 pointers meet, take the slow pointer to the beginning of the list. Then make the slow and fast pointers move with same speed. They
    will meet at the beginning of the cycle.
*/

class Solution {

    public:
        ListNode* detectCycle(ListNode* head) {
            ListNode* slowPointer= head, *fastPointer= head;

            bool isCycleDetected= false;

            while(fastPointer != NULL && fastPointer->next != NULL && fastPointer->next->next != NULL) {

                fastPointer= fastPointer->next->next;
                slowPointer= slowPointer->next;

                if(slowPointer == fastPointer) {
                    isCycleDetected= true;

                    break;
                }
            }

            if(!isCycleDetected)
                return NULL;

            slowPointer= head;

            while(slowPointer != fastPointer) {

                slowPointer= slowPointer->next;
                fastPointer= fastPointer->next;
            }

            return fastPointer;
        }
};