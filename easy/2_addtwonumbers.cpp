/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* current1 = l1;
        ListNode* current2 = l2;
        bool carry = false;

        while(current1 != nullptr)
        {
            int val2 = (current2 != nullptr) ? current2->val : 0;
                        
            current1->val += val2 + carry;

            carry = current1->val / 10;
            current1->val %= 10;

            if (current1->next == nullptr &&
                (!(current2 == nullptr || current2->next == nullptr) || carry))
            {    
                current1->next = new ListNode(0);
            }

            current1 = current1->next;
            if (current2 != nullptr)
                current2 = current2->next;

            }
        
        return l1;
    }
};