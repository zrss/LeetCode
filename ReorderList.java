package com.zrss.leetcode;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class ReorderList {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)
            return;
        
        //locate nodes that need to insert
        ListNode mid = head.next;
        
        for (ListNode itr = head.next; itr != null; ) {
            itr = itr.next;
            
            if (itr != null)
                itr = itr.next;
            
            mid = mid.next;
        }
        
        //reverse inserted nodes
        ListNode rListHead = new ListNode(-1);
        
        for (ListNode itr = mid; itr != null; ) {
            ListNode tmp = rListHead.next;
            rListHead.next = itr;
            
            ListNode cpy = itr.next;
            itr.next = tmp;
            
            itr = cpy;
        }
        
        ListNode source = head;
        
        //insert into right position
        for (ListNode itr = rListHead.next; itr != null; ) {
            ListNode tmp = source.next;
            source.next = itr;
            
            ListNode cpy = itr.next;
            itr.next = tmp;
            
            itr = cpy;
            source = tmp;
        }
        
        //set tail as null
        if (source.next == mid) {
            source.next = null;
        }
        else {
            source.next.next = null;
        }
        
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub

    }

}
