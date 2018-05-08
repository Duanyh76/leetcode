class Solution {
    public int repeatedStringMatch(String A, String B) {
        StringBuilder builder = new StringBuilder();
        int maxLength = B.length() + A.length();
        int count = 0;
        while (builder.length() <= maxLength) {
            builder.append(A);
            count++;
            if (builder.toString().contains(B)) {
                return count;
            }
        }
        return -1;
    }
}