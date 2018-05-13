class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if (A == null || A.length == 0) {
            return null;
        }
        int rowSize = A.length;
        int colSize = A[0].length;
        for (int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
            for (int colIndex = 0; colIndex < colSize / 2; colIndex++) {
                int temp = A[rowIndex][colIndex];
                A[rowIndex][colIndex] = A[rowIndex][colSize - 1 - colIndex];
                A[rowIndex][colSize - 1 - colIndex] = temp;
            }
        }
        for (int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
            for (int colIndex = 0; colIndex < colSize; colIndex++) {
                A[rowIndex][colIndex] = 1 - A[rowIndex][colIndex];
            }
        }
        return A;
    }
}