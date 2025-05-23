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

// Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (!head->next)
        {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slow_prev = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        slow_prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// Merge k Sorted Lists
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
class Solution
{
public:
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode *partitionandMerge(int start, int end, vector<ListNode *> &lists)
    {
        if (start > end)
        {
            return NULL;
        }
        if (start == end)
        {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode *L1 = partitionandMerge(start, mid, lists);
        ListNode *L2 = partitionandMerge(mid + 1, end, lists);

        return mergeTwoSortedLists(L1, L2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;

        return partitionandMerge(0, k - 1, lists);
    }
};

// Remove Zero Sum Consecutive Nodes from Linked List
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        int prefixsum = 0;
        unordered_map<int, ListNode *> mp;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;

        while (head != NULL)
        {
            prefixsum += head->val;

            if (mp.find(prefixsum) != mp.end())
            {
                ListNode *p = mp[prefixsum];
                ListNode *start = p;
                int pSum = prefixsum;
                while (start != head)
                {
                    start = start->next;
                    pSum += start->val;
                    if (start != head)
                        mp.erase(pSum);
                }
                p->next = start->next;
            }
            else
            {
                mp[prefixsum] = head;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};

// Swapping Nodes in a Linked List | 1 Pass | 2 Pass
// Approach-1 (Making use of length of LinkedList)
class Solution
{
public:
    int FindLength(ListNode *head)
    {
        int l = 0;

        while (head)
        {
            head = head->next;
            l++;
        }
        return l;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        // Kth Node from Start
        // Kth Node from End = Length-K+1 Node from Beginning

        int Length = FindLength(head);

        int k_1 = k;
        ListNode *temp1 = head;
        while (k_1 > 1)
        {
            temp1 = temp1->next;
            k_1--;
        }

        int k_2 = Length - k + 1;
        ListNode *temp2 = head;
        while (k_2 > 1)
        {
            temp2 = temp2->next;
            k_2--;
        }

        swap(temp1->val, temp2->val);
        return head;
    }
};

// Approach-2 (Using only One Pass)
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *p1 = NULL;
        ListNode *p2 = NULL;

        ListNode *temp = head;

        while (temp)
        {

            if (p2 != NULL)
                p2 = p2->next;

            k--;
            if (k == 0)
            {
                p1 = temp;
                p2 = head;
            }

            temp = temp->next;
        }

        swap(p1->val, p2->val);
        return head;
    }
};

// Swap Nodes in Pairs
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == nullptr)
        {
            return head;
        }

        ListNode *temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};

// Maximum Twin Sum of a Linked List | 3 Approaches
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        // Approch 1
        vector<int> vec;
        ListNode *curr = head;
        while (curr != NULL)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        int result = 0;
        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        return result;

        // Approch 2
        stack<int> st;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            st.push(curr->val);
            curr = curr->next;
        }
        int l = st.size();
        curr = head;
        int count = 1;
        int result = 0;
        while (count <= l / 2)
        {
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop();
            count++;
        }
        return result;

        // Approach 3
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *prev = NULL;
        ListNode *nextNode = NULL;
        while (mid != NULL)
        {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        int result = 0;
        ListNode *curr = head;
        while (prev != NULL)
        {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }

        return result;
    }
};

// Add Two Numbers II
class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        int sum = 0, carry = 0;
        ListNode *ans = new ListNode();
        while (l1 != NULL || l2 != NULL)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }
        return carry == 0 ? ans->next : ans;
    }
};

// Follow Up Qn Also without reveseing the LinkedList using stack
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        while (l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0, carry = 0;
        ListNode *ans = new ListNode();
        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }
        return carry == 0 ? ans->next : ans;
    }
};

// Partition List
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *smallP = small;
        ListNode *largeP = large;

        while (head != NULL)
        {
            if (head->val < x)
            {
                smallP->next = head;
                smallP = smallP->next;
            }
            else
            {
                largeP->next = head;
                largeP = largeP->next;
            }
            head = head->next;
        }
        largeP->next = NULL;
        smallP->next = large->next;

        return small->next;
    }
};