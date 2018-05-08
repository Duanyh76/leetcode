class Solution {
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftPath = longestUnivaluePath(root.left);
        int rightPath = longestUnivaluePath(root.right);
        int maxChildPath = Math.max(leftPath, rightPath);
        if (root.right != null && root.left != null && root.val != root.right.val && root.val != root.left.val) {
            return maxChildPath;
        }
        int keyValue = root.val;
        int count = keyValuePath(root.left, keyValue) + keyValuePath(root.right, keyValue);
        return Math.max(count, maxChildPath);
    }

    int keyValuePath(TreeNode node, int keyValue) {
        if (node == null || node.val != keyValue) {
            return 0;
        }
        return 1 + Math.max(keyValuePath(node.left, keyValue), keyValuePath(node.right, keyValue));
    }
}`