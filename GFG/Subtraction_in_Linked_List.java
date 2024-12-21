package GFG;

//! Difficulty -> Hard

//? You are given two linked lists that represent two large positive numbers. 
//? From the two numbers represented by the linked lists, subtract the smaller number from the larger one. 
//? Look at the examples to get a better understanding of the task.

import java.util.Scanner;

// Node Class
class Node {
    int data;
    Node next;

    Node(int val) {
        data = val;
        next = null;
    }
}

// Linked List Class
class LinkedList {
    Node head;
    Node tail;

    LinkedList() {
        head = null;
        tail = null;
    }

    // creates a new node with given value and appends it at the end of the linked
    // list
    void insert(int val) {
        if (head == null) {
            head = new Node(val);
            tail = head;
        } else {
            tail.next = new Node(val);
            tail = tail.next;
        }
    }
}

public class Subtraction_in_Linked_List {
    static void printList(Node n) {
        while (n != null) {
            System.out.print(n.data);
            n = n.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            LinkedList LL1 = new LinkedList();
            String l1 = sc.next();
            for (int j = 0; j < n; ++j) {
                int x = Character.getNumericValue(l1.charAt(j));
                LL1.insert(x);
            }

            int m = sc.nextInt();
            LinkedList LL2 = new LinkedList();
            String l2 = sc.next();
            for (int j = 0; j < m; ++j) {
                int x = Character.getNumericValue(l2.charAt(j));
                LL2.insert(x);
            }

            Solution ob = new Solution();
            Node res = ob.subLinkedList(LL1.head, LL2.head);
            printList(res);
        }

        sc.close();
    }
}

class Solution {
    public Node subLinkedList(Node head1, Node head2) {
        // code here
        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();

        Node node1 = head1;
        Node node2 = head2;

        while (node1 != null) {
            num1.append(node1.data);
            node1 = node1.next;
        }

        while (node2 != null) {
            num2.append(node2.data);
            node2 = node2.next;
        }

        removeLeadingZeroes(num1);
        removeLeadingZeroes(num2);

        if (compare(num1, num2) < 0) {
            StringBuilder temp = num1;
            num1 = num2;
            num2 = temp;
        }

        subtract(num1, num2);

        Node res = new Node(0);
        Node node = res;

        for (int i = 0; i < num1.length(); i++) {
            node.next = new Node(Character.getNumericValue(num1.charAt(i)));
            node = node.next;
        }

        return res.next;
    }

    public static int compare(StringBuilder sb1, StringBuilder sb2) {
        if (sb1.length() != sb2.length())
            return Integer.compare(sb1.length(), sb2.length());

        for (int i = 0; i < sb1.length(); i++) {
            if (sb1.charAt(i) != sb2.charAt(i))
                return Integer.compare(sb1.charAt(i), sb2.charAt(i));
        }

        return 1;
    }

    public static void removeLeadingZeroes(StringBuilder sb) {
        int index = 0;
        // Find the first non-zero digit or the last digit if all are zero
        while (index < sb.length() - 1 && sb.charAt(index) == '0') {
            index++;
        }
        // Delete leading zeroes
        sb.delete(0, index);
    }

    public static void subtract(StringBuilder num1, StringBuilder num2) {
        // Reverse both StringBuilder
        num1.reverse();
        num2.reverse();

        int borrow = 0;
        int index = 0;

        while (index < num1.length() || index < num2.length()) {
            int digit1 = (index < num1.length()) ? (num1.charAt(index) - '0') : 0;
            int digit2 = (index < num2.length()) ? (num2.charAt(index) - '0') : 0;

            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            // Update the current digit in num1
            if (index < num1.length()) {
                num1.setCharAt(index, (char) (diff + '0'));
            } else {
                // If num1 is shorter, append the new digit
                num1.append((char) (diff + '0'));
            }

            index++;
        }

        // Remove trailing zeroes
        while (num1.length() > 1 && num1.charAt(num1.length() - 1) == '0') {
            num1.deleteCharAt(num1.length() - 1);
        }

        // Reverse the result to get the correct order
        num1.reverse();
    }
}
