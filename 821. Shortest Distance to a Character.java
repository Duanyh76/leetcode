class Solution {
    public int[] shortestToChar(String S, char C) {
        int size = S.length();
        int[] distanceArray = new int[size];
        List<Integer> keyPosition = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            if (C == S.charAt(i)) {
                keyPosition.add(i);
            }
        }
        for (int i = 0; i < size; i++) {
            int minDistance = Integer.MAX_VALUE;
            if (C == S.charAt(i)) {
                minDistance = 0;
            } else {
                for (Integer position : keyPosition) {
                    minDistance = Integer.min(minDistance, Math.abs(i - position));
                }
            }
            distanceArray[i] = minDistance;
        }
        return distanceArray;
    }

}