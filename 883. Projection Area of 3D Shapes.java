class Solution {
    public int projectionArea(int[][] grid) {
        int count = 0;
        int row = grid.length;
        int col = grid[0].length;
        for (int rowIndex = 0; rowIndex < row; rowIndex++) {
            int maxRowNumber = 0;
            for (int colIndex = 0; colIndex < col; colIndex++) {
                if (grid[rowIndex][colIndex] > 0) {
                    maxRowNumber = Integer.max(maxRowNumber, grid[rowIndex][colIndex]);
                    count++;
                }
            }
            count += maxRowNumber;
        }
        for (int colIndex = 0; colIndex < col; colIndex++) {
            int maxColNumber = 0;
            for (int rowIndex = 0; rowIndex < row; rowIndex++) {
                if (grid[rowIndex][colIndex] > 0) {
                    maxColNumber = Integer.max(grid[rowIndex][colIndex], maxColNumber);
                }
            }
            count += maxColNumber;
        }
        return count;
    }
}