class Solution {
    public int heightChecker(int[] heights) {
        int[] sortedArray = Arrays.copyOf(heights, heights.length);
        Arrays.sort(sortedArray);
        int count = 0;
        for (int index = 0; index < heights.length; index++) {
            if (heights[index] != sortedArray[index]) {
                count++;
            }
        }
        return count;
    }
}