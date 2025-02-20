package Infix_Postfix;

import java.util.Stack;

public class InfixToPostfix {

    int prec(char c) {
        if (c == '^') {
            return 3;
        } else if (c == '/' || c == '*') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        } else {
            return -1;
        }
    }

    void infixToPostfix(String s) {
        Stack<Character> st = new Stack<>();
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                result.append(c);
            } else if (c == '(') {
                st.push('(');
            } else if (c == ')') {
                while (st.peek() != '(') {
                    result.append(st.pop());
                }
                st.pop();
            } else {
                while (!st.isEmpty() && (prec(c) < prec(st.peek())
                        || prec(c) == prec(st.peek()))) {
                    result.append(st.pop());
                }
                st.push(c);
            }
        }

        // Pop all the remaining elements from the stack
        while (!st.isEmpty()) {
            result.append(st.pop());
        }

        System.out.println(result.toString());
    }

    public static void main(String[] args) {
        InfixToPostfix obj = new InfixToPostfix();
        String exp = "a-b*(c^d-e)^(f/g*h)-i";
        obj.infixToPostfix(exp);
    }
}
