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

/**
 * Definition for partition method result value
 *
 */
class PartitionResult {
    ListNode head;
    ListNode tail;
    ListNode pre_pivot;
    ListNode pivot_node;
    
    public PartitionResult(ListNode head, ListNode tail) {
        // TODO Auto-generated constructor stub
        this.head = head;
        this.tail = tail;
        pre_pivot = null;
        pivot_node = null;
    }
}

public class SortList {
    ListNode head = null;
    
    private void swap(ListNode prei, ListNode i, ListNode prej, ListNode j) {
        if (i != prej) { //i isn't adjacent to j
            if (prei != null) //prei == null means i is the list's head
                prei.next = j;
            
            ListNode cpy = j.next;
            j.next = i.next;
            
            prej.next = i;
            i.next = cpy; 
        }
        else { //i adjacent to j means i == prej
            if (prei != null) //prei == null means i is the list's head
                prei.next = j;
            
            ListNode cpy = j.next;
            j.next = i;
            i.next = cpy;
        }
    }
    
    /**
     * partition [p, r] inplace and return [head, tail, pre_pivot, pivot_node]
     * 
     * @param preP
     * @param p
     * @param r
     * @param nextR
     * @return
     */
    private PartitionResult partition(ListNode prep, ListNode p, ListNode r) {
        int pivot_element = r.val;
        
        PartitionResult partitionResult = new PartitionResult(p, r);
        
        ListNode i = prep;
        ListNode prei = null;
        ListNode prej = prep;
       
        for (ListNode j = p; j != r; prej = j, j = j.next) {
            if (j.val <= pivot_element) {
                
                prei = i;
                
                //++i
                if (i != null) {
                    i = i.next;
                }
                else {
                    i = partitionResult.head;
                    partitionResult.head = j; //modify cur head
                    
                    if (this.head == i)
                        this.head = j;
                }

                //swap i node and j node
                if (i != j) {
                    swap(prei, i, prej, j);
                    
                    //swap i and j reference
                    ListNode cpy = i;
                    i = j;
                    j = cpy;
                }
            }
        }
        
        //swap i + 1 node and r node
        if (i != null) {
            prei = i;
            i = i.next;
        }
        else {
            i = partitionResult.head;
            partitionResult.head = r;
            
            if (this.head == i)
                this.head = r;
        }
        
        swap(prei, i, prej, r);
        
        ListNode cpy = i;
        i = r;
        r = cpy;
        
        //modify tail
        partitionResult.tail = i;
        
        //set new pre pivot node and pivot node
        partitionResult.pre_pivot = prej;
        partitionResult.pivot_node = i; 
                
        return partitionResult;
    }
    
    
    /**
     * single linked list quickSort [head, tail]
     * @param head
     * @param tail
     * @return
     */
    private void quickSort(ListNode preHead, ListNode head, ListNode tail) {        
        if (head != null && tail != null && head != tail) {
            PartitionResult partitionResult = partition(preHead, head, tail);
            
            quickSort(preHead, partitionResult.head, partitionResult.pre_pivot);
            
            if (partitionResult.pivot_node != partitionResult.tail)
                quickSort(partitionResult.pivot_node, partitionResult.pivot_node.next, partitionResult.tail);
        }
    }
    
    public void sortList(ListNode head) {
        this.head = head;
        ListNode tail = null;
        
        for (ListNode itr = head; itr != null; tail = itr, itr = itr.next);
        
        quickSort(null, head, tail);
    }
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        Integer [] nums = {10, 1, 3, 4, 6, 2};
        
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
        
        sortList.sortList(head);
        
        for (ListNode itr = sortList.head; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }

}
