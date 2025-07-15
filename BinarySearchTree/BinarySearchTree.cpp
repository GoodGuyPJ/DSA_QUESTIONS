#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

void inorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

// void levelOderTraversal(Node* root){
//   if(root == NULL) return;
//   queue<Node*> q;
//   q.push(root);

//   while(!q.empty()){
//     Node* temp = q.front();
//     q.pop();
//     if(temp == NULL){
//       cout<<endl;
//       if(!q.empty()){
//         q.push(NULL);
//       }
//     }else{
//       cout<<temp->data<<" ";
//       if(temp->left){
//         q.push(temp->left);
//       }
//       if(temp->right){
//         q.push(temp->right);
//       }

//     }
//   }
// }

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

Node *insertIntoBST(Node *&root, int d)
{
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }
  if (d > root->data)
  {
    root->right = insertIntoBST(root->right, d);
  }
  else
  {
    root->left = insertIntoBST(root->left, d);
  }
  return root;
}

void takeInput(Node *&root)
{
  int data;
  cin >> data;

  while (data != -1)
  {
    insertIntoBST(root, data);
    cin >> data;
  }
}

void BSTInsertion(Node *&root, int data){
  if (root == NULL){
    root = new Node(data);
    return;
  }
  if (data > root->data){
    BSTInsertion(root->right, data);
  } else {
    BSTInsertion(root->left, data);
  }
}

void SearchInBST(Node *root, int x)
{
  // if (root == NULL)
  // {
  //   cout << "Element not found in the BST." << endl;
  //   return;
  // }
  // if (root->data == x)
  // {
  //   cout << "Element " << x << " found in the BST." << endl;
  //   return;
  // }
  // else if (x < root->data)
  // {
  //   SearchInBST(root->left, x);
  // }
  // else
  // {
  //   SearchInBST(root->right, x);
  // }

  Node *current = root;
  while(current != NULL)
  {
    if (current->data == x)
    {
      cout << "Element " << x << " found in the BST." << endl;
      return;
    }
    else if (x < current->data)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  } 
}

void MinimumInBST(Node* root){
  if (root == NULL)
  {
    cout << "The BST is empty." << endl;
    return;
  }
  Node* current = root;
  while (current->left != NULL)
  {
    current = current->left;
  }
  cout << "Minimum value in the BST: " << current->data << endl;
}

void MaximumInBST(Node* root){
  if (root == NULL)
  {
    cout << "The BST is empty." << endl;
    return;
  }
  Node* current = root;
  while (current->right != NULL)
  {
    current = current->right;
  }
  cout << "Maximum value in the BST: " << current->data << endl;
}


int main()
{
  Node *root = NULL;
  cout << "Enter the elements of the binary search tree (enter -1 to stop): ";
  takeInput(root);
  cout << "Level order traversal of the binary search tree:" << endl;
  // levelOderTraversal(root);
  levelOrderTraversal(root);

  cout << endl;
  cout << "Inorder traversal of the binary search tree:" << endl;
  inorderTraversal(root);
  cout << endl;
  cout << "Preorder traversal of the binary search tree:" << endl;
  preorderTraversal(root);
  cout << endl;
  cout << "Postorder traversal of the binary search tree:" << endl;
  postorderTraversal(root);
  cout << endl;
  


  //BST insertion
  BSTInsertion(root, 5);

  cout << "After inserting 5, inorder traversal of the binary search tree:" << endl;
  inorderTraversal(root);

// Search into BST
int x = 5;
  SearchInBST(root, x);

  cout << "Searching for " << x << " in the BST." << endl;
  SearchInBST(root, 10); // Searching for an element not in the BST

  /*************************************
   //Inoder Traversal of BST is sorted order
   *************************************/

   //Mininum and Maximum in BST
  MinimumInBST(root);
  MaximumInBST(root);


  return 0;
}