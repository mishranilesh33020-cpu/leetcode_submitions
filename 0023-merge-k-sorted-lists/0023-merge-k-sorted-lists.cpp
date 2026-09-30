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
    ListNode* merge2(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }

        p->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        for (int gap = 1; gap < n; gap *= 2) {
            for (int i = 0; i + gap < n; i += gap * 2) {
                lists[i] = merge2(lists[i], lists[i + gap]);
            }
        }

        return n ? lists[0] : nullptr;
    }
};