class Solution {
    public int smallestRangeI(int[] A, int K) {
        int maxNum = 0;
        int minNum = 10000;
        for (int number : A) {
            maxNum = Integer.max(maxNum, number);
            minNum = Integer.min(minNum, number);
        }
        int diff = maxNum - minNum - 2 * K;
        return diff < 0 ? 0 : diff;
    }
}