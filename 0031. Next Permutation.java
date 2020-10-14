class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length < 2) {
            return;
        }
        for (int i = nums.length - 2; i >= 0; i--) {
            int key = nums[i];
            int switchIndex = i;
            for (int j = nums.length - 1; j > i; j--) {
                if (nums[j] > key) {
                    if (switchIndex == i) {
                        switchIndex = j;
                        continue;
                    }
                    if (nums[switchIndex] > nums[j]) {
                        switchIndex = j;
                    }
                }
            }
            if (switchIndex != i) {
                int temp = nums[i];
                nums[i] = nums[switchIndex];
                nums[switchIndex] = temp;
                Arrays.sort(nums, i + 1, nums.length);
                return;
            }
        }
        Arrays.sort(nums);
    }

//    public static void main(String[] args) {
//        Solution solution = new Solution();
//        int[] nums = {4, 2, 0, 2, 3, 2, 0};
//        solution.nextPermutation(nums);
//        System.out.println(nums);
//    }
}