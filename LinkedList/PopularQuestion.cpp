// Delete Node in a Linked List1
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* prev = NULL;

      while(node != NULL && node->next !=NULL){
        node->val = node->nex->val;
        prev = node;
        node = node->next;
        delete(node);
      }
    }
  }

  // Delete the Middle Node of a Linked List
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
    // int getLength(ListNode* head){
    //     ListNode* temp = head;
    //     int cnt=0;
    //     while(temp!=NULL){
    //         cnt++;
    //         temp= temp->next;
    //     }
    //     return cnt;
    // }
    ListNode* deleteMiddle(ListNode* head) {
        // int n = getLength(head);
        // if(n == 1) return nullptr;

        // int middle = n/2;
        // ListNode* temp = head;
        // for(int i=0; i<middle -1; i++){
        //     temp = temp->next;
        // }
        // temp->next = temp->next->next;

        // return head;

        if(head == NULL || head->next== NULL) return nullptr;

        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next!=NULL){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevSlow->next = slow->next;
        delete(slow);
        return head;
    }
};