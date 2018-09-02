class Solution {
    List<Integer> leafA = new ArrayList<>();
    List<Integer> leafB = new ArrayList<>();

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        getLeafSet(root1,leafA);
        getLeafSet(root2,leafB);
        return leafA.equals(leafB);
    }
    private void getLeafSet(TreeNode node,List<Integer> leafSet){
        if(node.left==null&&node.right==null){
            leafSet.add(node.val);
        }
        if(node.left!=null){
            getLeafSet(node.left,leafSet);
        }
        if(node.right!=null){
            getLeafSet(node.right,leafSet);
        }
    }
}