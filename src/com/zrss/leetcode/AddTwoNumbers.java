package com.zrss.leetcode;

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode i1 = l1;
        ListNode i2 = l2;
        
        ListNode rel = new ListNode(-1);
        ListNode iR = rel;
        
        int carry = 0;
        
        while (i1 != null && i2 != null) {
            int val = i1.val + i2.val;
            val += carry;
            carry = val / 10;
            ListNode digit = new ListNode(val % 10);
            iR.next = digit;
            iR = digit;
            
            i1 = i1.next;
            i2 = i2.next;
        }
        
        ListNode remain = (i1 != null) ? i1 : i2;
        
        while (remain != null) {
            int val = remain.val + carry;
            carry = val / 10;
            ListNode digit = new ListNode(val % 10);
            iR.next = digit;
            iR = digit;
            
            remain = remain.next;
        }
        
        if (carry > 0) {
            ListNode digit = new ListNode(carry);
            iR.next = digit;
            iR = digit;
        }
        
        iR.next = null;
        
        return rel.next;
    }
    
    public static void main(String[] args) {
        ListNode l1 = new ListNode(9);
        l1.next = new ListNode(9);
        l1.next.next = new ListNode(9);
        
        ListNode l2 = new ListNode(9);
        l2.next = new ListNode(9);
        l2.next.next = new ListNode(9);
        
        AddTwoNumbers addTwoNumbers = new AddTwoNumbers();
        
        ListNode rel = addTwoNumbers.addTwoNumbers(l1, l2);
        
        for (ListNode itr = rel; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }
}
