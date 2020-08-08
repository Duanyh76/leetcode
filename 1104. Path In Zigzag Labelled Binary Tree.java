class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int level = 1;
        int endValue = 2;
        while(endValue <= label){
            level++;
            endValue *= 2;
        }
        
        Stack<Integer> stack = new Stack();
        do{
            level--;
            endValue /= 2;
            stack.push(label);
            label /= 2;
            int beginValue = endValue / 2;
            int gap = label - beginValue;
            label = endValue - 1 - gap;
        }while(label != 0);
        
        List<Integer> list = new ArrayList<>();
        while(!stack.isEmpty()){
            list.add(stack.pop());
        }
        return list;
    }
}