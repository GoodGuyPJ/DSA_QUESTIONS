#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};

void levelOderTraversal(Node* root){
  if(root == NULL) return;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    if(temp == NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }else{
      cout<<temp->data<<" ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }

    }
  }
}

Node* insertIntoBST(Node* &root, int d){
  if(root == NULL){
    root = new Node(d);
    return root;
  }
  if(d > root->data){
    root-> right = insertIntoBST(root->right, d);
  }else{
    root->left = insertIntoBST(root->left, d);
  }
  return root;
}

void takeInput(Node* &root){
  int data;
  cin >> data;

  while(data != -1){
    insertIntoBST(root, data);
    cin >> data;
  }
  
}

int main() {
    Node* root = NULL;
    cout << "Enter the elements of the binary search tree (enter -1 to stop): ";
    takeInput(root);
    cout << "Level order traversal of the binary search tree:" << endl;
    levelOderTraversal(root);
  return 0;
}