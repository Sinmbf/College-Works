
public class GarbageCollectionDemo {
    // Creating gc method
    public void finalize(){
        System.out.println("Clean up demo");
    }    
    public static void main(String[]args){
        GarbageCollectionDemo g1=new GarbageCollectionDemo();
        GarbageCollectionDemo g2=new GarbageCollectionDemo();
        g1=null;
        g2=null;
        System.gc();
    }
}
