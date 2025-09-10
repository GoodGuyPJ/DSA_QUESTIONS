//Height of Binary Search Tree

int height(struct Node* node){
  if(node == nullptr){
    return 0;
  }
  int left = height(node->left);
  int right = height(node->right);
  int ans = max(left, right) +1;

  return ans;
}

//Diameter of Tree
int diameter(Node* root){
  if(root == nullptr){
    return 0;
  }

  int op1 = diameter(root->left);
  int op2 = diameter(root->right);
  int op3 = height(root->left) + height(root->right) + 1;

  int ans = max(op1, max(op2, op3));
  return ans;
}