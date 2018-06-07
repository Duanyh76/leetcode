class Solution {
    public int singleNonDuplicate(int[] nums) {
        int count = 0;
        for (int num : nums) {
            count ^= num;
        }
        return count;
    }
}

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int firstIndex = 0;
        int secondIndex = 1;
        int size = nums.length;
        while (secondIndex < size) {
            if (nums[firstIndex] != nums[secondIndex]) {
                break;
            }
            firstIndex = secondIndex + 1;
            secondIndex = firstIndex + 1;
        }
        return nums[firstIndex];
    }
}

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int beginIndex = 0;
        int endIndex = nums.length - 1;
        while (beginIndex < endIndex) {
            int midIndex = beginIndex + (endIndex - beginIndex) / 2;
            if (midIndex % 2 == 1) {
                midIndex--;
            }
            if(nums[midIndex]!=nums[midIndex+1]){
                endIndex=midIndex;
            }else{
                beginIndex=midIndex+2;
            }
        }
        return nums[beginIndex];
    }
}