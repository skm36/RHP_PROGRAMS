import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class disjoint {
    static void main() {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[] ldr=new int[n+1];
        for (int i = 1; i <= n; i++) {
            ldr[i]=i;
        }
        for(int i=1;i<=m;i++){
            int lt,rt;
            lt=sc.nextInt();
            rt=sc.nextInt();
            Join(ldr,lt,rt);
        }
        Set<Integer> st=new HashSet<>();
        for (int j = 1; j <=n; j++) {
            st.add(find(ldr,j));
        }
        System.out.println(st.size());
    }
    public static int find(int[] ldr,int node){
        if(ldr[node]!=node){
            ldr[node]=find(ldr,ldr[node]);

        }
        return ldr[node];
    }
    private static void Join(int[] ldr, int lt, int rt) {
        int ldrlt=find(ldr,lt);
        int ldrrt=find(ldr,rt);
        ldr[ldrlt]=ldrrt;
    }
}
