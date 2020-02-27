class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList();
        generate(list, "", 0, 0, n);
        return list;
    }
    
    private void generate(List<String> list, String p, int left, int right, int size){
        if(p.length() == 2 * size){
            list.add(p);
            return;
        }
        if(left < size){
            generate(list, p + "(", left + 1, right, size);
        }
        if(right < left){
            generate(list, p + ")", left, right + 1, size);
        }
    }
}