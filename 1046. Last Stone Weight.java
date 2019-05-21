class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> stoneQueue = new PriorityQueue<>(stones.length, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        Arrays.stream(stones).forEach(stone -> stoneQueue.add(stone));
        while (stoneQueue.size() != 1) {
            Integer bigStone = stoneQueue.poll();
            Integer smallStone = stoneQueue.poll();
            Integer newStone = bigStone - smallStone;
            stoneQueue.add(newStone);
        }
        return stoneQueue.peek();
    }
}