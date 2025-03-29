// Delete Node in a Linked List
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *prev = NULL;
        while (node != nullptr && node->next != NULL)
        {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete (node);
    }
};

// Delete the Middle Node of a Linked List
class Solution
{
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
    ListNode *deleteMiddle(ListNode *head)
    {
        // int n = getLength(head);
        // if(n == 1) return nullptr;

        // int middle = n/2;
        // ListNode* temp = head;
        // for(int i=0; i<middle -1; i++){
        //     temp = temp->next;
        // }
        // temp->next = temp->next->next;

        // return head;

        if (head == NULL || head->next == NULL)
            return nullptr;

        ListNode *prevSlow = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevSlow->next = slow->next;
        delete (slow);
        return head;
    }
};

// Middle of the Linked List
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // while(fast!=NULL && fast->next!=NULL){
        //     slow= slow->next;
        //     fast = fast->next;
        //     if(fast!=NULL){
        //         fast = fast->next;
        //     }
        // }
        // return slow;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Odd Even Linked List
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = head;
        ListNode *pointtoeven = head->next;
        ListNode *even = head->next;

        while (even != NULL && even->next != nullptr)
        {
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = pointtoeven;
        return head;
    }
};

// Linked List Cycle II
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // set<ListNode*> st;
        // ListNode* temp  = head;
        // while(temp!= NULL){
        //     if(st.find(temp) != st.end()){
        //         return temp;
        //     } else{
        //         st.insert(temp);
        //         temp = temp->next;
        //     }
        // }
        // return NULL;

        if (!head || !(head->next))
            return NULL;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        if (slow != fast)
            return NULL;

        ListNode *P = head;
        while (P != slow)
        {
            P = P->next;
            slow = slow->next;
        }
        return P;
    }
};

// Linked List Random Node
class Solution
{
public:
    // vector<int> arr;
    Solution(ListNode *head)
    {
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     arr.push_back(temp->val);
        //     temp= temp->next;
        // }
    }

    int getRandom()
    {
        // int n = arr.size();
        // int random = rand()%n;
        // return arr[random];
    }
};