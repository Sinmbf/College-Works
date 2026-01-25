package Queue;

import javax.swing.JOptionPane;

public class LinearQueueDemo {

    public static void main(String[] args) {
        Queue q = new Queue();

        do {
            String str = JOptionPane.showInputDialog("Press 1 For Enquqe \n Press 2 for dequeue \n Press 3 for Display Queue\n ");
            switch (str) {
                case "1": {
                    String n = JOptionPane.showInputDialog("Enter Data to Queue");
                    int data = Integer.parseInt(n);
                    q.enqueue(data);
                    break;
                }
                case "2": {
                    q.dequeue();
                    break;
                }
                case "3": {
                    q.printQueue();
                    break;
                }
                default: {
                    JOptionPane.showMessageDialog(null, "Invalid operation !!");
                }
            }

            String str1 = JOptionPane.showInputDialog("Do you want to continue operation !!!! \n Press Y For Yes \n Press N for NO");
            if (str1.charAt(0) == 'N') {
                break;
            }
        } while (true);

    }
}

class Queue {

    final int MAXSIZE = 10;
    int A[] = new int[MAXSIZE];
    int front = 0;
    int rear = -1;

    public boolean isEmpty() {
        if (rear < front) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        if (rear == MAXSIZE - 1) {
            return true;
        }
        return false;
    }

    public void enqueue(int data) {
        if (isFull()) {
            JOptionPane.showMessageDialog(null, "Queue is already full !!!!");
        } else {
            rear++;
            A[rear] = data;
        }
    }

    public void dequeue() {
        if (isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nothing to delete !!!!");
        } else {
            int data = A[front];
            A[front] = 0;
            front++;
            JOptionPane.showMessageDialog(null, "Data Being delete : " + data);
        }
    }

    public void printQueue() {
        String str = "[";
        for (int i = 0; i < A.length; i++) {
            str += " " + A[i];
        }
        str += " ]";
        JOptionPane.showMessageDialog(null, str);
    }

}
