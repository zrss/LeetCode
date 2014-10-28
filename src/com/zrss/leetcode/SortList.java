package com.zrss.leetcode;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

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
     * merge l1 and l2 list
     * 
     * @param l1
     * @param l2
     * @return
     */
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1), itr = head;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                itr.next = l1;
                itr = l1;
                l1 = l1.next;
            }
            else {
                itr.next = l2;
                itr = l2;
                l2 = l2.next;
            }
        }
        
        //deal l1 or l2 remain element
        ListNode remail = null;
        
        if (l1 == null && l2 != null) {
            remail = l2;
        }
        else if (l2 == null && l1 != null) {
            remail = l1;
        }
        
        itr.next = remail;
        
        ListNode relHead = head.next;
        head = null;
        
        return relHead;
    }
    
    private ListNode mergeSort(ListNode head, ListNode tail) {
        if (head.next == tail) { //single node
            head.next = null;
            return head;
        }
            
        //locate the middle node
        //2 * mid = len
        //itr += 2; mid += 1;
        ListNode itr = head, mid = head;
        while (itr != tail) {
            itr = itr.next;
            
            if (itr != tail) {
                itr = itr.next;
            }
            
            mid = mid.next;
        }
        
        ListNode l1 = mergeSort(head, mid);
        
        ListNode l2 = mergeSort(mid, tail);
        
        return merge(l1, l2);
    }

    public ListNode sortList(ListNode head) {
        return mergeSort(head, null);
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        ArrayList<Integer> nums = new ArrayList<Integer>();
        
        String textDataFile = "C:\\textDataFile.txt";
        
        try {
            InputStreamReader inputStreamReader = new InputStreamReader(new FileInputStream(textDataFile));
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
            
            String total = bufferedReader.readLine();
            
            bufferedReader.close();
            
            String [] parts = total.split(",");

            for (String i:parts) {
                nums.add(Integer.valueOf(i));
            }
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
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
        
        SortList sortList = new SortList();
        
        head = sortList.mergeSort(head, null);
        
        for (ListNode itr = head; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }

}
