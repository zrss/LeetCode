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
     * core idea is the link not swap
     * head != null
     * and use the head node as a pivot node
     * 
     * [head, tail)
     * 
     * @param head
     * @param tail
     * @return [leftPartHead, leftPartEndNode]
     */
    private ListNode[] partition(ListNode head, ListNode tail) {
        //cal avg as the pivot value
        int sum = 0, count = 0;
        
        for (ListNode itr = head; itr != tail; itr = itr.next) {
            sum += itr.val;
            ++count;
        }
        
        float x = (float)sum / count; //notice if int x will lead to infinite loop (for example -39 -38)
        
        boolean same = true;
        
        //l1 <= x
        //l2 > x        
        ListNode l1Head = new ListNode(-1), l1Itr = l1Head;
        ListNode l2Head = new ListNode(-1), l2Itr = l2Head;
        
        for (ListNode itr = head, pre = head; itr != tail; pre = itr, itr = itr.next) {
            if (itr.val != pre.val) {
                same = false;
            }
            
            if (itr.val < x) {
                l1Itr.next = itr;
                l1Itr = itr;
            }
            else {
                l2Itr.next = itr;
                l2Itr = itr;
            }
        }
        
        ListNode [] listNodes = new ListNode[2];
        
        listNodes[0] = l1Head.next;
        
        if (!same) {
            //l1->l2->tail
            l2Itr.next = tail; //if l2Head == l2Itr
            l1Itr.next = l2Head.next;
                    
            listNodes[1] = l1Itr;
        }
        else {
            listNodes[1] = l1Head.next;
        }

        //useless node set to null
        l1Head = null;
        l2Head = null;
        
        return listNodes;
    }
    
    //quick sort for list
    private ListNode quickSort(ListNode head, ListNode tail) {
        ListNode curHead = head;
        
        if (head != tail && head.next != tail) {
            ListNode [] rel = partition(head, tail); //after partition head node play a pivot role
            
            if (rel[0] != null) { //when rel[0] means that remain element is the same
                curHead = quickSort(rel[0], rel[1].next); //maintain head node
                
                rel[1].next = quickSort(rel[1].next, tail); //link the two parts
            }
        }
        
        return curHead;
    }
    
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        int x = 4;
        float y = (float) 4.0;
        
        if (x < y) {
            System.out.println("le");
        }
        else {
            System.out.println("gt");
        }
        
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
        
        head = sortList.quickSort(head, null);
        
        for (ListNode itr = head; itr != null; itr = itr.next) {
            System.out.println(itr.val);
        }
    }

}
