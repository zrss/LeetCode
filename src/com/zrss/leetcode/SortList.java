package com.zrss.leetcode;

/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class SortList {
    /**
     * core idea is the link not swap
     * head != null
     * and use the head node as a pivot node
     * 
     * [head, tail)
     * 
     * @param head
     * @param tail
     * @return current head node
     */
    private ListNode partition(ListNode head, ListNode tail) {   
        int x = head.val;
        
        //l1 <= x
        //l2 > x        
        ListNode l1Head = new ListNode(-1), l1Itr = l1Head;
        ListNode l2Head = new ListNode(-1), l2Itr = l2Head;
        
        for (ListNode itr = head.next; itr != tail; itr = itr.next) {
            if (itr.val <= x) {
                l1Itr.next = itr;
                l1Itr = itr;
            }
            else {
                l2Itr.next = itr;
                l2Itr = itr;
            }
        }
        
        //l1->x->l2->tail
        l1Itr.next = head;
        l2Itr.next = tail; //if l2Head == l2Itr
        head.next = l2Head.next;
        
        //useless node set to null
        ListNode relHead = l1Head.next;
        l1Head = null;
        l2Head = null;
        
        return relHead;
    }
    
    //quick sort for list
    private ListNode quickSort(ListNode head, ListNode tail) {
        ListNode curHead = head;
        
        if (head != tail) {
            curHead = partition(head, tail); //after partition head node play a pivot role
            
            curHead = quickSort(curHead, head); //maintain head node
            
            head.next = quickSort(head.next, tail); //link two parts
        }
        
        return curHead;
    }
    
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        Integer [] nums = {1,3,3,1,3,1,3,3,2,3,2,2,1,1,1,3,2,2,1,1,2,2,2,3,3,1,1};
        
        ListNode head = null;
        ListNode pre = null;
        
        for (int i = 0; i < nums.length; ++i) {
            ListNode itr = new ListNode(nums[i]);
            
            if (head == null)
                head = itr;
            
            if (pre != null)
                pre.next = itr;
            
            pre = itr;
        }
        
        SortList sortList = new SortList();
        
        head = sortList.quickSort(head, null);
        
        for (ListNode itr = head; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }

}
