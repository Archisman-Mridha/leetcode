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

    private:
        void recursiveHelper(ListNode *result, ListNode *list1, ListNode *list2) {

            if(list1 == NULL)
                result->next= list2;

            else if(list2 == NULL)
                result->next= list1;

            else {
                if(list1->val <= list2->val) {
                    result->next= new ListNode(list1->val);

                    recursiveHelper(result->next, list1->next, list2);
                }

                else {
                    result->next= new ListNode(list2->val);

                    recursiveHelper(result->next, list1, list2->next);
                }
            }
        }

    public:
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
            ListNode* result= new ListNode( );

            recursiveHelper(result, list1, list2);

            return result->next;
        }
};

int main( ) {

    exit(0);
}