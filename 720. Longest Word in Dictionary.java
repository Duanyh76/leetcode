class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words);
        Set<String> dictionary = new HashSet<>();
        String keyWord = "";
        for (String word : words) {
            if (word.length() == 1 || dictionary.contains(word.substring(0, word.length() - 1))) {
                keyWord = word.length() > keyWord.length() ? word : keyWord;
                dictionary.add(word);
            }
        }
        return keyWord;
    }
}