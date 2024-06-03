class prime{
    public static void main(String[]args){
        int n=5,flag=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=0;
                break;
            }
        }
        if(flag==0){
            System.out.println(n+" is not a prime number");
        }
        else{
            System.out.println(n+" is a prime number");
        }
    }
}