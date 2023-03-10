// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy{0};
        dummy.next = head;
        auto *prev = &dummy, *cur = dummy.next;
        
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        for (auto *indirect = &head; *indirect != nullptr; ) {
            if ((*indirect)->val == val) {
                *indirect = (*indirect)->next;
                continue;
            }
            indirect = &((*indirect)->next) ; 
        }
        return head;
    }
};