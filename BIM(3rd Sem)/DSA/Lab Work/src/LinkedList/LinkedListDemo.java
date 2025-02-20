package LinkedList;


import java.util.Scanner;

// Creation of node
class Node {

    int data;
    Node next;

    // Constructor to set node
    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

}

public class LinkedListDemo {

    static Node head = null;

    public static void main(String[] args) {
        InsertAtFirst(100);
        InsertAtFirst(200);
        InsertAtFirst(300);
        InsertAtLast(400);
        System.out.println("After insertion at first: ");
        traverse();
        InsertAtSpeciPosition(500);
        traverse();
        deleteFromFirst();
        System.out.println("After deletion from first: ");
        traverse();
        deleteFromLast();
        System.out.println("After deletion from last: ");
        traverse();
        deleteFromSpecificPosition();
        System.out.println("After deletion from specific position: ");
        traverse();
    }

    // Method to insert node at the beginning
    public static void InsertAtFirst(int data) {
        Node node = new Node(data, null);
        if (head == null) {
            head = node;
        } else {
            node.next = head;
            head = node;
        }

    }

    // Method to insert the node at the last
    public static void InsertAtLast(int data) {
        Node node = new Node(data, null);
        Node temp = head;
        if (head == null) {
            head = node;
        } else {
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = node;
        }

    }

    // Method to insert node at specific position
    public static void InsertAtSpeciPosition(int data) {
        Node node = new Node(data, null);
        Scanner sc = new Scanner(System.in);
        System.out.println("Please Enter the position where you want to insert: ");
        int pos = sc.nextInt();
        int size = 0;
        Node temp = head;
        while (temp != null) {
            temp = temp.next;
            size++;
        }

        if (pos > size) {
            System.out.println("Position out of range!!!");
        } else if (pos == 0) {
            InsertAtFirst(node.data);
        } else {
            temp = head;
            int i = 1;
            while (i < pos) {
                temp = temp.next;
                i++;
            }

            node.next = temp.next;
            temp.next = node;
        }

    }

    // Method to traverse and display all element of list
    public static void traverse() {
        Node temp = head;
        System.out.println("Data in the linked list: ");
        System.out.print("{");
        while (temp != null) {
            System.out.print(temp.data + "\t");
            temp = temp.next;
        }
        System.out.print("\n");

    }

    // Method to delete node at the beginning
    public static void deleteFromFirst() {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete!!!");
        } else {
            System.out.println("The data being deleted is " + head.data);
            head = head.next;
        }
    }
    
    // Method to delete node at the last
    public static void deleteFromLast() {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete!!!");
        } else {
            Node temp1=head;
            Node temp2=head.next;
            while(temp2.next!=null){
                temp1=temp2;
                temp2=temp2.next;
            }
            System.out.println("Data being deleted is " + temp2.data);
            temp1.next=null;
        }
    }
    
    // Method to delete node at specific position
    public static void deleteFromSpecificPosition() {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete!!!");
        } else {
            Scanner sc=new Scanner(System.in);
            System.out.println("Please enter the position where you want to delete: ");
            int pos=sc.nextInt();
            int size=0;
            Node temp=head;
            while(temp!=null){
                temp=temp.next;
                size++;
            }
            if(pos>size){
                System.out.println("Position out of range!!!");
            }
            else if(pos==0){
                deleteFromFirst();
            }
            else{
                temp=head;
                int i=1;
                while(i<pos){
                    temp=temp.next;
                    i++;
                }
                System.out.println("Data being deleted is " + temp.next.data);
                temp.next=temp.next.next;
            }
        }
    }

}
