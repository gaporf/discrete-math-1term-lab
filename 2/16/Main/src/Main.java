import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
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


    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("choose2num.in"));
        out = new FileWriter(new File("choose2num.out"));
        int n = in.nextInt(),
                k = in.nextInt();
        BigInteger ans = BigInteger.ZERO;
        int cur = 1;
        for (int i = 0; i < k; i++) {
            int y = in.nextInt();
            while (cur < y) {
                ans = ans.add(combination(n - cur, k - i - 1));
                cur++;
            }
            cur = y + 1;
        }
        out.write(ans.toString());
        out.close();
    }
}
