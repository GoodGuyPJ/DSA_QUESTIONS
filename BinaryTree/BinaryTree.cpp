#include<bits/stdc++.h>
using namespace std;

class node {
  public: 
  int data;
  node* left;
  node* right;

  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node * buildTree(node* root) {
  int d;
  cin>> d;
  if (d == -1) {
    return NULL;
  } 
  root = new node(d);
  root->left = buildTree(root->left);
  root->right = buildTree(root->right);
  return root;
}

void levelordertarversal(node* root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL); // to mark the end of the current level
  while(!q.empty()){
    node* temp = q.front();
    q.pop();
if(temp == NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
      continue;
    }
    if(temp->left){
      q.push(temp->left);
    }
    if(temp->right){
      q.push(temp->right);
    }

  }
}


int main() {
  node* root = nullptr;
  root = buildTree(root);
}