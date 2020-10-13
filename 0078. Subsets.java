class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int[] mask = new int[nums.length];
        List<List<Integer>> result = new ArrayList<>();
        boolean go = true;
        while (go) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                if (mask[i] == 1) {
                    list.add(nums[i]);
                }
            }
            result.add(list);

            go = false;
            for (int i = nums.length - 1; i >= 0; i--) {
                if (mask[i] == 0) {
                    mask[i] = 1;
                    go = true;
                    break;
                }
                mask[i] = 0;
            }
        }
        return result;
    }
}