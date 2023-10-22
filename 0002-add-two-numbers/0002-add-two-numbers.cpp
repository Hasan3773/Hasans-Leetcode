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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // given two linked lists that repersent a reversed num
        // add the nums and then return ans as linked list

        // Add each corresponding value of the linked list
        // if result is > 9 carry the left over to the next calc
        // store each value in the new linked list 
        ListNode* newList = new ListNode();
        ListNode* current = newList;
        int carry = 0; 

        while(l1 != NULL || l2 != NULL || carry){
            // assign the num in linked list to the two digs
            int dig1 = (l1 != nullptr) ? l1->val : 0;
            int dig2 = (l2 != nullptr) ? l2->val : 0;

            // calc the digit sum using the carry
            int sum = dig1 + dig2 + carry;

            // create new node and puts the val without the carry in it
            ListNode* newNode = new ListNode(sum % 10);

            // calculates the carry 
            carry = sum / 10;

            // assigns next pointer to the new node
            current->next = newNode;
            // moves current to the next node
            current = current->next;

            // moves l1 and l2 to the next node if possible
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;    
        }

        // assign node pointer to the first val of new list
        ListNode* result = newList->next;
        delete newList;
        return result;
    }
};