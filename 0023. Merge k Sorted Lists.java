class Solution {
    private Queue<ListNode> nodeQueue = new PriorityQueue<>(new Comparator<ListNode>() {
        @Override
        public int compare(ListNode o1, ListNode o2) {
            return o1.val - o2.val;
        }
    });


    public ListNode mergeKLists(ListNode[] lists) {
        for (ListNode list : lists) {
            ListNode node = list;
            while (node != null) {
                nodeQueue.add(node);
                node = node.next;
            }
        }
        ListNode head = nodeQueue.poll();
        ListNode node = head;
        while (!nodeQueue.isEmpty()) {
            node.next = nodeQueue.poll();
            node.next.next = null;
            node = node.next;
        }
        return head;
    }
}

class Solution {
    private Queue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode>() {
        @Override
        public int compare(ListNode o1, ListNode o2) {
            return o1.val - o2.val;
        }
    });


    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        for (ListNode head : lists) {
            if (head != null) {
                queue.add(head);
            }
        }
        if (queue.isEmpty()) {
            return null;
        }
        ListNode head = queue.poll();
        ListNode node = head;
        while (!queue.isEmpty()) {
            ListNode queueHead = queue.peek();
            while (node.next != null && node.next.val < queueHead.val) {
                node = node.next;
            }
            if (node.next != null) {
                queue.add(node.next);
            }
            node.next = queue.poll();
            node = node.next;
        }
        return head;
    }
}