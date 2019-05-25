/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    private List<List<Integer>> tree = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        getLevelOrder(root, 0);
        return tree;
    }

    private void getLevelOrder(Node root, int levelIndex) {
        if (root == null) {
            return;
        }
        if (tree.size() <= levelIndex) {
            // new level
            List<Integer> levelList = new ArrayList<>();
            levelList.add(root.val);
            tree.add(levelList);
        } else {
            // exit level
            List<Integer> levelList = tree.get(levelIndex);
            levelList.add(root.val);
        }
        for (Node child : root.children) {
            getLevelOrder(child, levelIndex + 1);
        }
    }
}