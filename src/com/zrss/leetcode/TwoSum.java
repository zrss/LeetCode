package com.zrss.leetcode;

import java.util.Arrays;

class Element implements Comparable<Element> {
    int value;
    int index;
    
    @Override
    public int compareTo(Element arg0) {
        // TODO Auto-generated method stub
        return this.value - arg0.value;
    }
    
    public Element(int value, int index) {
        this.value = value;
        this.index = index;
    }
}

public class TwoSum {
    public int[] twoSum(int[] numbers, int target) {
        Element[] elements = new Element[numbers.length];
        
        for (int i = 0; i < numbers.length; ++i) {
            elements[i] = new Element(numbers[i], i);
        }
        
        Arrays.sort(elements);
       
        boolean cont = true;
        int[] rel = new int[2];
        
        for (int index1 = 0; cont && index1 < elements.length; ++index1) {
            int remain = target - elements[index1].value;
            
            int index2 = binarySearch(elements, index1 + 1, elements.length, remain);
            
            if (index2 != -1) {
                cont = false;
                int rIndex1 = elements[index1].index + 1;
                int rIndex2 = elements[index2].index + 1;
                
                if (rIndex1 < rIndex2) {
                    rel[0] = rIndex1;
                    rel[1] = rIndex2;
                } else {
                    rel[0] = rIndex2;
                    rel[1] = rIndex1;
                }
            }
        }
        
        return rel;
    }
    
    private int binarySearch(Element[] numbers, int start, int end, int key) {
        while (start < end) {
            int mid = (start + end) >> 1;
            if (numbers[mid].value == key) {
                return mid;
            }
            else if (numbers[mid].value > key) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        TwoSum twoSum = new TwoSum();
        int[] data = {5, 75, 25};
        
        int[] rel = twoSum.twoSum(data, 100);
        
        System.out.println(rel[0]);
        System.out.println(rel[1]);
    }
}
