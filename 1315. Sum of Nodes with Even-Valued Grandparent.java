class Solution {
    private int sum = 0;
    public int sumEvenGrandparent(TreeNode root) {
        if(root.val % 2 == 0){
            sumGrandchild(root);
        }
        if(root.left != null){
            sumEvenGrandparent(root.left);
        }
        if(root.right != null){
            sumEvenGrandparent(root.right);
        }
        return sum;
    }
    
    private void sumGrandchild(TreeNode root){
        if(root.left != null){
            sumChild(root.left);
        }
        if(root.right != null){
            sumChild(root.right);
        }
    }
    
    private void sumChild(TreeNode root){
        if(root.left != null){
            sum += root.left.val;
        }
        if(root.right != null){
            sum += root.right.val;
        }
    }
}