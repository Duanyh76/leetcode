class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode a = head;
        for(int index = 0; index < n; index++){
            a = a.next;
        }
        if(a == null){
            return head.next;
        }
        ListNode b = head;
        while(a.next != null){
            a = a.next;
            b = b.next;
        }
        b.next = b.next.next;
        return head;
    }
}