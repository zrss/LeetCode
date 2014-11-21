package com.zrss.leetcode;

public class InsertSortList {
    
    public ListNode insertionSortList(ListNode head) {
        ListNode vHead = new ListNode(-1);
        ListNode itrSource = head; //unsorted part
        
        while (itrSource != null) {
            boolean cont = true;
            
            ListNode itrSorted = vHead;
            while (cont && itrSorted.next != null) { //insert into middle
                if (itrSource.val < itrSorted.next.val) {
                    ListNode cpy = itrSorted.next;
                    itrSorted.next = itrSource;
                    
                    ListNode tmp = itrSource.next;
                    itrSource.next = cpy;
                    
                    itrSource = tmp;
                    
                    cont = false;
                }
                
                itrSorted = itrSorted.next;
            }
            
            if (cont) { //insert into tail
                itrSorted.next = itrSource;
                itrSource = itrSource.next;
                
                itrSorted.next.next = null;
            }
        }
        
        return vHead.next;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Integer [] nums = {10, 1, 6};
        
        ListNode head = null;
        ListNode pre = null;
        
        for (Integer i:nums) {
            ListNode itr = new ListNode(i);
            
            if (head == null)
                head = itr;
            
            if (pre != null)
                pre.next = itr;
            
            pre = itr;
        }
        
        InsertSortList insertSortList = new InsertSortList();
        
        head = insertSortList.insertionSortList(head);
        
        for (ListNode itr = head; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }

}
