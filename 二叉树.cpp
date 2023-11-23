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

//二叉树的最大深度

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftdata = maxDepth(root->left);
    int rightdata = maxDepth(root->right);

    return leftdata > rightdata ? leftdata + 1 : rightdata + 1;
}

//判断是否为平衡二叉树

int depath(struct TreeNode* root){
    if(root == NULL)
        return 0;

    int leftdata = depath(root->left);
    int rightdata = depath(root->right);

    return leftdata > rightdata ? leftdata + 1 : rightdata + 1;
}
bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;

    int leftdepath = depath(root->left);
    int rightdepath = depath(root->right);

    return abs(leftdepath - rightdepath) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

//生成遍历二叉树

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}BT;

BT* CreatTree(char* pstr, int* i) {
    if (pstr[*i] == '#') {
        (*i)++;
        return NULL;
    }
        
    BT* root = (BT*)malloc(sizeof(BT));
    assert(root);
    root->val = pstr[*i];
    (*i)++;
    root->left = CreatTree(pstr, i);
    root->right = CreatTree(pstr, i);
    return root;
}

void InOrder(BT* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);

}
int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    BT* tree = CreatTree(str, &i);
    InOrder(tree);
    return 0;
}
