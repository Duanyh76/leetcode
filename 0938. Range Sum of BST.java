class Solution {
    private List<Integer> values = new ArrayList<>();

    public int rangeSumBST(TreeNode root, int L, int R) {
        getValues(root);
        int rangeSum = values.stream()
                .filter(value -> value >= L && value <= R)
                .reduce(0, (x, y) -> x + y);
        return rangeSum;
    }

    private void getValues(TreeNode root) {
        if (root == null) {
            return;
        }
        values.add(root.val);
        getValues(root.left);
        getValues(root.right);
    }
}

class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) {
            return 0;
        }
        if (root.val > R) {
            return rangeSumBST(root.left, L, R);
        }
        if (root.val < L) {
            return rangeSumBST(root.right, L, R);
        }
        return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
    }
}

class Solution {
    private int rangeSum = 0;

    public int rangeSumBST(TreeNode root, int L, int R) {
        travel(root, L, R);
        return rangeSum;
    }

    private void travel(TreeNode root, int l, int r) {
        if (root == null) {
            return;
        }
        if (root.val >= l && root.val <= r) {
            rangeSum += root.val;
        }
        travel(root.left, l, r);
        travel(root.right, l, r);
    }
}