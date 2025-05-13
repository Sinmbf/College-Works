
import javax.swing.JOptionPane;

public class CircularQueueDemo {

    public static void main(String[] args) {
        CircularQueue cq = new CircularQueue();
        cq.enqueue(500);
        cq.enqueue(400);
        cq.enqueue(300);
        cq.enqueue(200);
        cq.printQueue();
        cq.dequeue();
        cq.printQueue();
        cq.enqueue(500);
        cq.printQueue();
        cq.enqueue(600);
        cq.dequeue();
        cq.printQueue();
    }
}

class CircularQueue {

    final int MAXSIZE = 5;
    int front = MAXSIZE - 1;
    int rear = MAXSIZE - 1;
    int Item[] = new int[MAXSIZE];

    public boolean isEmpty() {
        if (rear == front) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        if (front == (rear + 1) % MAXSIZE) {
            return true;
        } else {
            return false;
        }
    }

    public void enqueue(int data) {
        if (isFull()) {
            JOptionPane.showMessageDialog(null, "Queue is already full !!!!");
        } else {
            rear = (rear + 1) % MAXSIZE;
            Item[rear] = data;
        }
    }

    public void dequeue() {
        if (isEmpty()) {
            JOptionPane.showMessageDialog(null, "Nothing to delete !!!!");
        } else {
            front = (front + 1) % MAXSIZE;
            int data = Item[front];
            Item[front] = -1;

            JOptionPane.showMessageDialog(null, "Data Being delete : " + data);
        }
    }

    public void printQueue() {
        String str = "[";
        for (int i = 0; i < Item.length; i++) {
            str += " " + Item[i];
        }
        str += " ]";
        JOptionPane.showMessageDialog(null, str);
    }

}
