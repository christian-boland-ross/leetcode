class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        return reverseList(head, nullptr);
    }

    ListNode* reverseList(ListNode* head, ListNode* previous)
    {
        if (head == nullptr)
            return previous;

        ListNode* next = head->next;
        head->next = previous;

        return reverseList(next, head);
    }
};