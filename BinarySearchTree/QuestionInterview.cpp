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


//Optimal 2 for Diameter of Tree
pair<int, int> diameterFast(Node* root){
  if(root == nullptr){
    pair<int, int> p = make_pair(0,0);
    return p;
  }

  pair<int, int> left = diameterFast(root->left);
  pair<int, int> right = diameterFast(root->right);
  int op1 =  left.first;
  int op2 = right.first;
  int op3 = left.second + right.second + 1;

  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));
  ans.second = max(left.second, right.second) + 1;
  return ans;
}

int diameter(Node* root){
  return diameterFast(root).first;
}

//Balance Tree --> height(left) - height(right) <= 1 for All Nodes
