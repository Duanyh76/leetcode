class Solution {
    public int binaryGap(int N) {
        char[] binaryNumber = Integer.toBinaryString(N).toCharArray();
        int maxDistance = 0;
        int index = 0;
        while (index < binaryNumber.length && binaryNumber[index] == 0) {
            index++;
        }
        int oldIndex = index;
        while (index < binaryNumber.length) {
            if (binaryNumber[index] == '1') {
                maxDistance = Math.max(maxDistance, index - oldIndex);
                oldIndex = index;
            }
            index++;
        }
        return maxDistance;
    }
}