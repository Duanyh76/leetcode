bool isMirror(struct TreeNode *left, struct TreeNode *right)
{
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    if(left->val != right->val)
        return false;
    return isMirror(left->right, right->left) && isMirror(left->left, right->right);
}

bool isSymmetric(struct TreeNode* root)
{
    if(!root)
        return true;
    return isMirror(root->left, root->right);
}