import java.util.*;

public class CoffeeShopCoverage {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int MAX = 200000;

        int n = sc.nextInt();
        int k = sc.nextInt();
        int q = sc.nextInt();

        int[] diff = new int[MAX + 2];

        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();

            diff[l]++;
            diff[r + 1]--;
        }

        int[] prefix = new int[MAX + 1];

        int count = 0;
        for (int i = 1; i <= MAX; i++) {
            count += diff[i];

            if (count >= k) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            int ans = prefix[b] - prefix[a - 1];
            sb.append(ans).append("\n");
        }

        System.out.print(sb);

        sc.close();
    }
}
