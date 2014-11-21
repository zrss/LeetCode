package com.zrss.leetcode;

import java.util.Stack;

//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

public class ReversePolishNotation {
    public static int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<Integer>();
        
        Integer op1 = null, op2 = null;
        
        for (int i = 0; i < tokens.length; ++i) {
            switch (tokens[i]) {
            case "+": //may be unary operator
                if (stack.size() != 1) {
                    stack.push(stack.pop() + stack.pop());
                }
                break;
            
            case "-": //may be unary operator and notice the sequence
                if (stack.size() != 1) {
                    op2 = stack.pop();
                    op1 = stack.pop();
                    
                    stack.push(op1 - op2);
                } else {
                    stack.push(-stack.pop());
                }
                break;
            
            case "*":       
                stack.push(stack.pop() * stack.pop());
                break;
                
            case "/": //notice the sequence
                op2 = stack.pop();
                op1 = stack.pop();
                
                stack.push(op1 / op2);    
                break;
            default: //number
                stack.push(Integer.valueOf(tokens[i]));
                break;
            }
        }
        
        return stack.pop();
    }

    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        String [] tokens = {"4"};
        System.out.println(evalRPN(tokens));
    }

}
