class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int size = m * n;
        int[] numList = new int[size];
        int index = 0;
        for (int mIndex = 0; mIndex < m; mIndex++) {
            for (int nIndex = 0; nIndex < n; nIndex++) {
                numList[index++] = grid[mIndex][nIndex];
            }
        }
        index = size - (k % size);
        List<List<Integer>> shiftedGrid = new ArrayList<>();
        for (int mIndex = 0; mIndex < m; mIndex++) {
            List<Integer> list = new ArrayList<>();
            for (int nIndex = 0; nIndex < n; nIndex++) {
                if (index == size) {
                    index = 0;
                }
                list.add(numList[index++]);
            }
            shiftedGrid.add(list);
        }
        return shiftedGrid;
    }
}