//二叉树前序遍历，且返回节点值

int TreeSize(struct TreeNode* root){
    return root == NULL ? 0 : TreeSize(root -> left) + TreeSize(root -> right) + 1;
}
void _preorder(struct TreeNode* root, int* a, int* i){
    if(root == NULL){
        return;
    }
    a[(*i)] = root->val;
    (*i)++;
    _preorder(root->left, a, i);
    _preorder(root->right, a, i);
    
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
      int size = TreeSize(root);
      int* a = (int*)malloc(size * sizeof(int));
      int i = 0;
      _preorder(root, a, &i);
    
      *returnSize = size;

      return a;
}

//二叉树中序遍历，且返回节点值

int TreeSize(struct TreeNode* root){
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inorder(struct TreeNode* root, int* a, int* i){
    if(root == NULL){
        return;
    }
    _inorder(root->left, a, i);
    a[(*i)] = root->val;
    (*i)++;
    _inorder(root->right, a, i);

}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* a = (int*)malloc(size* sizeof(int));
    int i = 0;

    _inorder(root, a, &i);

    *returnSize = size;

    return a;
}

//二叉树后序遍历，且返回节点值

int TreeSize(struct TreeNode* root){
    return root == NULL ? 0 : TreeSize(root ->left) + TreeSize(root -> right) + 1;
}
void _postorder(struct TreeNode* root, int* a, int* i){
    if(root == NULL){
        return;
    }
    _postorder(root->left, a, i);
    _postorder(root->right, a, i);
    a[(*i)] = root->val;
    (*i)++;
    
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* a = (int*)malloc(size * sizeof(int));
    int i = 0;

    _postorder(root, a, &i);

    *returnSize = size;

    return a;
}
