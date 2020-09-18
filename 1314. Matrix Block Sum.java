class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int row = mat.length;
        int col = mat[0].length;
        int[][] answer = new int[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                addValue(mat, answer, i, j, K);
            }
        }
        return answer;
    }
    
    private void addValue(int[][] mat, int[][] answer, int rowIndex, int colIndex, int K){
        int beginRow = Math.max(0, rowIndex - K);
        int endRow = Math.min(mat.length - 1, rowIndex + K);
        int beginCol = Math.max(0, colIndex - K);
        int endCol = Math.min(mat[0].length - 1, colIndex + K);
        int value = mat[rowIndex][colIndex];
        for(int i = beginRow; i <= endRow; i++){
            for(int j = beginCol; j <= endCol; j++){
                answer[i][j] += value;
            }
        }
    }
}