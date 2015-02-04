package com.zrss.leetcode;

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;
        
        //set two iterator one's step is 1 and another is 2
        //if there exists a cycle then two iterator can meet
        for (ListNode i1 = head, i2 = head; i2 != null; ) {
            i2 = i2.next;
            
            if (i2 != null)
                i2 = i2.next;
            
            i1 = i1.next;
            
            if (i1 == i2)
                return true;
        }
        
        return false;
    }
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
    }

}
