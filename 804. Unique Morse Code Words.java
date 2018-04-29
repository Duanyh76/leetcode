class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set set = new HashSet();
        for (String word : words) {
            String temp = "";
            int length = word.length();
            for (int i = 0; i < length; i++) {
                int index = word.charAt(i) - 'a';
                temp += morse[index];
            }
            set.add(temp);
        }
        int count = set.size();
        return count;
    }
}