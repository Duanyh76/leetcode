class Solution {
    public List<String> commonChars(String[] A) {
        int size = A.length;
        int[][] charCount = new int[size][26];
        for (int i = 0; i < size; i++) {
            String a = A[i];
            for (char ch : a.toCharArray()) {
                int index = ch - 'a';
                charCount[i][index]++;
            }
        }
        List<String> list = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < size; j++) {
                min = Math.min(min, charCount[j][i]);
            }
            for (int j = 0; j < min; j++) {
                char ch = (char) ('a' + i);
                list.add(String.valueOf(ch));
            }
        }
        return list;
    }
}