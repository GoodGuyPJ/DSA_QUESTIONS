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
