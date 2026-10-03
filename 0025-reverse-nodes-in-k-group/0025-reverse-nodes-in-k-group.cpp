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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode** link = &head;
        ListNode* curr = head; 
        while (curr) {
            ListNode* kth = curr;

            for (int i = 1; i < k && kth; ++i)
                kth = kth->next;
            if (!kth) break;
            ListNode* nextGroup = kth->next;
            ListNode* prev = nextGroup;
            ListNode* node = curr;

            for (int i = 0; i < k; ++i) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            *link = kth;
            link = &curr->next;
            curr = nextGroup;
        }

        return head;
    }
};