class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int satisfiedCount = getSatisfiedCount(customers, grumpy);
        int maxStatisfiedX = 0;
        for (int index = 0; index < grumpy.length; index++) {
            if (grumpy[index] == 1) {
                int satisfiedNum = 0;
                for (int xIndex = index; xIndex < index + X && xIndex < grumpy.length; xIndex++) {
                    if (grumpy[xIndex] == 1) {
                        satisfiedNum += customers[xIndex];
                    }
                }
                maxStatisfiedX = Math.max(maxStatisfiedX, satisfiedNum);
            }
        }
        return maxStatisfiedX + satisfiedCount;
    }

    private int getSatisfiedCount(int[] customers, int[] grumpy) {
        int count = 0;
        for (int index = 0; index < customers.length; index++) {
            if (grumpy[index] == 0) {
                count += customers[index];
            }
        }
        return count;
    }
}