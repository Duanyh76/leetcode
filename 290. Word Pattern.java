class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern.length() != str.split(" ").length) {
            return false;
        }
        Map<Character, Integer> patternMap = new HashMap<>();
        int index = 0;
        List<Integer> patternList = new ArrayList<>();
        for (char letter : pattern.toCharArray()) {
            if (!patternMap.containsKey(letter)) {
                patternMap.put(letter, index++);
            }
            int letterValue = patternMap.get(letter);
            patternList.add(letterValue);
        }
        Map<String, Integer> strMap = new HashMap<>();
        index = 0;
        int position = 0;
        for (String word : str.split(" ")) {
            if (!strMap.containsKey(word)) {
                strMap.put(word, index++);
            }
            int wordValue = strMap.get(word);
            if (patternList.get(position++) != wordValue) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        Map index = new HashMap();
        for (Integer i = 0; i < pattern.length(); i++) {
            if (index.put(pattern.charAt(i), i) != index.put(words[i], i)) {
                return false;
            }
        }
        return true;
    }
}