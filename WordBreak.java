package com.zrss.leetcode;

import java.util.Set;
import java.util.TreeSet;

public class WordBreak {
    
    public boolean wordBreak(String s, Set<String> dict) {
        String temp = s;
        
        for (String w:dict) {
            while (temp.startsWith(w)) { //trap
                if (temp.length() != w.length())
                    temp = temp.substring(w.length());
                else
                    return true;
            }
            
            if (!temp.equals(s)) {
                boolean rel = wordBreak(temp, dict);
                
                if (!rel)
                    temp = s;
                else
                    return true;
            }
        }
        
        return false;
    }
    
    public static void main(String[] args) {
        WordBreak wordBreak = new WordBreak();
        
        Set<String> dict = new TreeSet<>();
        dict.add("a");
        dict.add("aa");
        dict.add("aaa");
        dict.add("aaaa");
        dict.add("aaaaa");
        dict.add("aaaaaa");
        dict.add("aaaaaaa");
        dict.add("aaaaaaaa");
        dict.add("aaaaaaaaa");
        dict.add("aaaaaaaaaa");
        
        System.out.println(wordBreak.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict));
    }
}
