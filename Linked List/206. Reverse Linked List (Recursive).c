/// Time Complexity: O(n)
/// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode * recur(struct ListNode * head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode * tmp = head->next;
    head->next = NULL;
    struct ListNode * node = recur(tmp);
    tmp->next = head;
    return node;
}

/* Wrong Code
struct ListNode * recur(struct ListNode * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // The major problem here is the next node of head is not null before             // recursion so we are still passing the original list after the finished part     // when we concatenate the current node to the finshed list
    struct ListNode * tmp = recur(head->next);
    head->next = NULL;
    tmp->next = head;
    return tmp;
}
*/

struct ListNode* reverseList(struct ListNode* head){
    return recur(head);
}
