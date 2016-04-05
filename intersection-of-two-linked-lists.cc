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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if (!head1 || !head2) {
            return nullptr;
        }
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        if (len1 > len2) {
            swap(head1, head2);
            swap(len1, len2);  // bug: swap(len1, len2);
        }
        for (int i = 0; i < len2 - len1; ++i) {
            head2 = head2->next;
        }
        while (head1 && head2 && head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1 == head2 ? head1 : nullptr;
    }
private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            head = head->next;
            ++length;
        }
        return length;
    }
};
