class Solution {
    private List<Integer> list = new LinkedList();
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        traver(root1);
        traver(root2);
        Collections.sort(list);
        return list;
    }
    
    private void traver(TreeNode node){
        if(node == null){
            return;
        }
        list.add(node.val);
        traver(node.left);
        traver(node.right);
    }
}