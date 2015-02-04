package com.zrss.leetcode;

import java.util.ArrayList;

//For example,
//Given s = "the sky is blue",
//return "blue is sky the".

public class ReverseWords {
    public static String reverseWords(String s) {
        String [] parts = s.split(" "); //get each word
        
        ArrayList<String> arrayList = new ArrayList<String>();
        
        for (String word:parts) {
            if (!word.equals(""))
                arrayList.add(word);
        }
        
        if (arrayList.size() == 0)
            return "";
        
        StringBuilder stringBuilder = new StringBuilder();
        
        for (int i = arrayList.size() - 1; i > 0; --i) { //reverse each word
            stringBuilder.append(arrayList.get(i) + " ");
        }
        
        stringBuilder.append(arrayList.get(0));
        
        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println(reverseWords(" 1"));
    }

}
