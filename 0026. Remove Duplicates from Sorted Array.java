class Solution {
    public int removeDuplicates(int[] nums) {
        int aIndex = 0;
        for(int index = 1; index < nums.length; index++){
            if(nums[index] != nums[aIndex]){
                aIndex++;
                nums[aIndex] = nums[index];
            }
        }    
        return aIndex + 1;
    }
}