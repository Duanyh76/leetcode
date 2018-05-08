class Solution {
    public int compress(char[] chars) {
        int beginIndex = 0;
        int size = chars.length;
        int count = 0;
        for (int endIndex = 0; endIndex < size; endIndex++) {
            count++;
            if (endIndex == size - 1 || chars[endIndex + 1] != chars[endIndex]) {
                chars[beginIndex] = chars[endIndex];
                beginIndex++;
                if (count != 1) {
                    char[] countArray = String.valueOf(count).toCharArray();
                    for (char num : countArray) {
                        chars[beginIndex++] = num;
                    }
                }
                count = 0;
            }
        }
        return beginIndex;
    }
}