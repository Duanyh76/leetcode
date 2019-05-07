class Solution {
    public int[] diStringMatch(String S) {
        int[] array = new int[S.length() + 1];
        int maxNum = S.length();
        int minNum = 0;
        for (int index = 0; index < S.length(); index++) {
            char s = S.charAt(index);
            if (s == 'I') {
                array[index] = minNum++;
            } else {
                array[index] = maxNum--;
            }
        }
        array[S.length()] = maxNum;
        return array;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] idids = solution.diStringMatch("IDID");
        System.out.println(idids);
    }
}