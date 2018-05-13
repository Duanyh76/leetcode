class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> partition = new ArrayList<>();
        int beginIndex = 0;
        while (beginIndex < S.length()) {
            int endIndex = S.length() - 1;
            char beginLetter = S.charAt(beginIndex);
            while (S.charAt(endIndex) != beginLetter) {
                endIndex--;
            }
            List<Character> letters = new ArrayList<>();
            for (int index = beginIndex; index < endIndex; index++) {
                char letter = S.charAt(index);
                if (!letters.contains(letter)) {
                    letters.add(letter);
                }
            }
            for (int i = 0; i < letters.size(); i++) {
                char letter = (char) letters.toArray()[i];
                int letterEndIndex = S.length() - 1;
                while (S.charAt(letterEndIndex) != letter) {
                    letterEndIndex--;
                }
                if (letterEndIndex > endIndex) {
                    while (endIndex != letterEndIndex) {
                        if (!letters.contains(S.charAt(endIndex))) {
                            letters.add(S.charAt(endIndex));
                        }
                        endIndex++;
                    }
                }
            }
            int partitionCount = endIndex - beginIndex + 1;
            partition.add(partitionCount);
            beginIndex = endIndex + 1;
        }
        return partition;
    }
}

class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> partition = new ArrayList<>();
        int[] letterPosition = new int[26];
        for (int i = 0; i < S.length(); i++) {
            letterPosition[S.charAt(i) - 'a'] = i;
        }
        int beginIndex = 0;
        int endIndex = 0;
        for (int i = 0; i < S.length(); i++) {
            endIndex = Math.max(endIndex, letterPosition[S.charAt(i) - 'a']);
            if (endIndex == i) {
                partition.add(endIndex - beginIndex + 1);
                beginIndex = i + 1;
            }
        }
        return partition;
    }
}