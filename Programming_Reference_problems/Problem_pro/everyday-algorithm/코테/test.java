import java.util.*;

class test {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int[] stores = new int[N];
        for(int i=0;i<N;i++){
            stores[i] = sc.nextInt();
        }

        System.out.println(N);
        System.out.println(Arrays.toString(stores));

        
    }
}