
public class MultiDimArray2 {
    public static void main(String[]args){
        //Declare array
        int multiArr[][]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        // Display
        for(int element[]:multiArr){
            for(int value:element){
                System.out.println(value);
            }
        }
    }   
}
