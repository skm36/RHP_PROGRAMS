import java.util.*;
class Main{
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    List<Integer> a = new ArrayList<>();
    List<Integer> b = new ArrayList<>();
    int n = s.nextInt();
    int m = s.nextInt();
    for(int i=0;i<n;i++)
    a.add(s.nextInt());
    for(int i=0;i<m;i++)
    b.add(s.nextInt());
    Collections.sort(a);
    Collections.sort(b);
    int c=0;
    n--;
    m--;
    while(n>=0 && m>=0){
      if(2*a.get(n)>=b.get(m)){
        c++;
        n--;
        m--;
      }else {
        while(m>=0){
          if(2*a.get(n)>=b.get(m))
            break;
            m--;
        }
      }
    }
    System.out.print(c);
  }
}
