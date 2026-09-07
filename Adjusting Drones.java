import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            int k = fs.nextInt();
            int[] cnt = new int[2 * n + 5];
            for (int i = 0; i < n; i++) {
                int x = fs.nextInt();
                cnt[x]++;
            }
            int left = 0;
            int right = 0;
            int answer = 0;
            for (int i = 1; i <= 2 * n; i++) {
                if (cnt[i] == 0) continue;
                if (right < i) {
                    left = i;
                    right = i + Math.max(0, cnt[i] - k);
                } 
                else  right += cnt[i];
                answer = Math.max(answer, right - left);
            }
            out.append(answer).append('\n');
        }
        System.out.print(out);
    }
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) {
            in = is;
        }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ');
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int res = 0;
            while (c > ' ') {
                res = res * 10 + (c - '0');
                c = read();
            }
            return res * sign;
        }
    }
}
