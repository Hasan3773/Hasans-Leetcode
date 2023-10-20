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
    ListNode* reverseList(ListNode* head) {
        // I get given the head of a singly linked list 
        // Goal is to reverse it and return the new head

        // use three pointer, current, prev & next
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(current != NULL){
            // assigns next pointer to the og next node
            next = current->next;

            // reverses the current og nodes pointer to the new directions
            current->next = prev;

            // we are done with this node so we set it as prev
            prev = current;

            // set current as next node to move on
            current = next;
        }
        // once we are done we set the head as the last node we operated on
        head = prev;

        return head;
    }
};