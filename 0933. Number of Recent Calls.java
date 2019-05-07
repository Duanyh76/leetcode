class RecentCounter {
    private Queue<Integer> queue;

    public RecentCounter() {
        queue = new PriorityQueue<>();
    }

    public int ping(int t) {
        queue.add(t);
        while (queue.size() > 0 && queue.peek() < t - 3000) {
            queue.poll();
        }
        return queue.size();
    }
}