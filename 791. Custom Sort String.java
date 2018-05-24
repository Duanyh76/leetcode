class Solution {
    public String customSortString(String S, String T) {
        int[] map = new int[26];
        for (int i = 0; i < T.length(); i++) {
            char letter = T.charAt(i);
            map[letter - 'a']++;
        }
        StringBuilder sortedString = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            char letter = S.charAt(i);
            for (int times = 0; times < map[letter - 'a']; times++) {
                sortedString.append(letter);
            }
            map[letter - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            char letter = (char) ('a' + i);
            for (int times = 0; times < map[i]; times++) {
                sortedString.append(letter);
            }
        }
        return sortedString.toString();
    }
}