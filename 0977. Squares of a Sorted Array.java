class Solution {
    public int[] sortedSquares(int[] A) {
        int midIndex = getMidIndex(A);
        int[] squares = new int[A.length];
        int squareIndex = 1;
        int negIndex = midIndex - 1;
        int posIndex = midIndex + 1;
        squares[0] = A[midIndex] * A[midIndex];
        while (squareIndex < A.length) {
            int negValue = getValue(negIndex, A);
            int posValue = getValue(posIndex, A);
            if (negValue < posValue) {
                squares[squareIndex] = negValue;
                negIndex--;
            } else {
                squares[squareIndex] = posValue;
                posIndex++;
            }
            squareIndex++;
        }
        return squares;
    }

    private int getValue(int index, int[] a) {
        if (index >= 0 && index < a.length) {
            return a[index] * a[index];
        }
        return Integer.MAX_VALUE;
    }

    private int getMidIndex(int[] a) {
        int posIndex = 0;
        for (; posIndex < a.length; posIndex++) {
            if (a[posIndex] >= 0) {
                break;
            }
        }
        if (posIndex == 0) {
            return posIndex;
        }
        if (posIndex == a.length) {
            return posIndex - 1;
        }
        if (a[posIndex] * a[posIndex] > a[posIndex - 1] * a[posIndex - 1]) {
            return posIndex - 1;
        }
        return posIndex;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] a = {-2, 0, 1, 2};
        int[] ints = solution.sortedSquares(a);
        System.out.println(ints);
    }
}