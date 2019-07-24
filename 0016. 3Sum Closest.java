class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestGap = Integer.MAX_VALUE;
        for (int index = 0; index < nums.length - 2; index++) {
            int beginIndex = index + 1;
            int endIndex = nums.length - 1;
            while (beginIndex < endIndex) {
                int sum = nums[index] + nums[beginIndex] + nums[endIndex];
                int gap = 0;
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    beginIndex++;
                } else {
                    endIndex--;
                }
                if (Math.abs(closestGap) > Math.abs(target - sum)) {
                    closestGap = target - sum;
                }
            }
        }
        return target - closestGap;
    }
}