class Solution {
    public int longestOnes(int[] A, int K) {
        List<Integer> zeroIndexList = getList(A);
        if (zeroIndexList.size() <= K) {
            return A.length;
        }

        int maxLength = Math.max(zeroIndexList.get(K),
                A.length - zeroIndexList.get(zeroIndexList.size() - K - 1) - 1);

        int zeroNum = zeroIndexList.size();
        for (int index = 0; index < zeroNum - K - 1; index++) {
            int endIndex = index + K + 1;
            int preValue = zeroIndexList.get(index);
            int sufValue = zeroIndexList.get(endIndex);
            int length = sufValue - preValue - 1;
            maxLength = Math.max(maxLength, length);
        }
        return maxLength;
    }


    private List<Integer> getList(int[] a) {
        List<Integer> list = new ArrayList<>();
        for (int index = 0; index < a.length; index++) {
            if (a[index] == 0) {
                list.add(index);
            }
        }
        return list;
    }
}

class Solution {
    public int longestOnes(int[] A, int K) {
        int maxLength = 0;
        int changeCount = 0;
        int length = 0;
        for (int index = 0; index < A.length; index++) {
            if (A[index] == 1) {
                length++;
            } else if (changeCount < K) {
                length++;
                changeCount++;
            } else {
                // already change K zeros
                int preIndex = index - length;
                while (A[preIndex++] == 1) {
                    length--;
                }
            }
            maxLength = Math.max(maxLength, length);
        }
        return maxLength;
    }
}