import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static FileWriter out;
    private static BigInteger factorial(int a) {
        BigInteger ans = BigInteger.ONE;
        for (int i = 2; i <= a; i++) {
            ans = ans.multiply(BigInteger.valueOf(i));
        }
        return ans;
    }

    private static BigInteger combination(int n, int k) {
        return factorial(n).divide(factorial(k).multiply(factorial(n - k)));
    }

    private static void gen(int num, int last, int n, int k, BigInteger m) throws IOException {
        if (num < k) {
            for (int i = last; i <= n; i++) {
                int newN = n - i,
                        newK = k - num - 1;
                BigInteger u = combination(newN, newK);
                if (u.compareTo(m) <= 0) {
                    m = m.subtract(u);
                } else {
                    out.write(i + " ");
                    gen(num + 1, i + 1, n, k, m);
                    return;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("num2choose.in"));
        out = new FileWriter(new File("num2choose.out"));
        int n, k;
        BigInteger m;
        n = in.nextInt();
        k = in.nextInt();
        m = in.nextBigInteger();
        gen(0, 1, n, k, m);
        out.close();
    }
}
