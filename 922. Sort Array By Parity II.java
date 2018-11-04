class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] oddArray = Arrays
                .stream(A)
                .filter(a -> a % 2 == 1)
                .toArray();
        int[] evenArray = Arrays
                .stream(A)
                .filter(a -> a % 2 == 0)
                .toArray();
        int size = oddArray.length;
        int aIndex = 0;
        for (int index = 0; index < size; index++) {
            A[aIndex++] = evenArray[index];
            A[aIndex++] = oddArray[index];
        }
        return A;
    }
}