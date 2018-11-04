class Solution {
    public int[] sortArrayByParity(int[] A) {
        return Arrays
                .stream(A)
                .boxed()
                .sorted((a, b) -> Integer.compare(a % 2, b % 2))
                .mapToInt(a -> a)
                .toArray();
    }
}