#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr)
    { }
};

class Solution {

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode* result= NULL, *resultNodePointer= NULL;
            int carry= 0;

            while(l1 != NULL && l2 != NULL) {
                int sum= l1->val + l2->val + carry;

                carry= sum / 10;
                sum= sum % 10;

                if(result == NULL) {

                    result= new ListNode(sum);

                    resultNodePointer= result;
                }

                else {
                    resultNodePointer->next= new ListNode(sum);
                    resultNodePointer= resultNodePointer->next;
                }

                l1= l1->next;
                l2= l2->next;
            }

            while(l1 != NULL) {

                l1->val= l1->val + carry;

                carry= l1->val / 10;
                l1->val= l1->val % 10;

                resultNodePointer->next= l1;
                resultNodePointer= resultNodePointer->next;

                l1= l1->next;
            }

            while(l2 != NULL) {

                l2->val= l2->val + carry;

                carry= l2->val / 10;
                l2->val= l2->val % 10;

                resultNodePointer->next= l2;
                resultNodePointer= resultNodePointer->next;

                l2= l2->next;
            }

            if(carry != 0)
                resultNodePointer->next= new ListNode(carry);

            return result;
        }
};