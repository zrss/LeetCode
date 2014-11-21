package com.zrss.leetcode;


public class ReverseLinkedListII {
    //1<=m<=n<=length of list
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) {
            return head;
        }
        
        ListNode vHead = new ListNode(-1);
        vHead.next = head;

        // locate mth node
        ListNode mth = vHead;
        ListNode preMth = null;
        for (int i = 0; i < m; ++i, preMth = mth, mth = mth.next) { }
        
        int count = n - m;
        int i = 0;

        // insert process
        for (ListNode tmp = mth.next; i < count; ++i, tmp = mth.next) {
             mth.next = tmp.next;
             tmp.next = preMth.next;
             preMth.next = tmp;
        }

        ListNode curHead = vHead.next;
        vHead = null;
        return curHead;        
    }
    
    public static void main(String[] args) {
        int[] data = {2, 8, 6, 4, 1};
        
        ListNode vHead = new ListNode(-1);
        ListNode tmp = vHead;
        for (int i:data) {
            tmp.next = new ListNode(i);
            tmp = tmp.next;
        }
        tmp.next = null;
        
        
        for (ListNode itr = vHead.next; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
        
        System.out.println();
        
        ReverseLinkedListII reverseLinkedListII = new ReverseLinkedListII();
        
        vHead.next = reverseLinkedListII.reverseBetween(vHead.next, 3, 4);
        
        for (ListNode itr = vHead.next; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }
}
