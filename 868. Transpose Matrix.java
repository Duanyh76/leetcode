class Solution {
    public int[][] transpose(int[][] A) {
        int rowSize = A[0].length;
        int colSize = A.length;
        int[][] matrix = new int[rowSize][colSize];
        for (int rowIndex = 0; rowIndex < rowSize; rowIndex++) {
            for (int colIndex = 0; colIndex < colSize; colIndex++) {
                matrix[rowIndex][colIndex] = A[colIndex][rowIndex];
            }
        }
        return matrix;
    }
}