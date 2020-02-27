class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> pair = new HashMap();
        pair.put('(', ')');
        pair.put('[', ']');
        pair.put('{', '}');
        Set<Character> leftSet = pair.keySet();
        Stack<Character> stack = new Stack();
        for (char c : s.toCharArray()) {
            if (leftSet.contains(c)) {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char d = stack.pop();
                if (pair.get(d) != c) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}