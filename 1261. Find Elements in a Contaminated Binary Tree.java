class FindElements {    
    private Set<Integer> record = new HashSet();
    public FindElements(TreeNode root) {
        init(root, 0);
    }
    
    public void init(TreeNode node, int defaultValue){
        if(node == null){
            return;
        }
        record.add(defaultValue);
        init(node.left, defaultValue * 2 + 1);
        init(node.right, defaultValue * 2 + 2);
    }
    
    public boolean find(int target) {
        return record.contains(target);
    }
}