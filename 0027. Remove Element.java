class Solution {
    public int removeElement(int[] nums, int val) {
        int aIndex = 0;
        for(int index = 0 ;index < nums.length; index++){
            if(nums[index] != val){
                nums[aIndex] = nums[index];
                aIndex++;
            }
        }
        return aIndex;
    }
}