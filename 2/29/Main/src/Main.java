import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] lines = new BufferedReader(new FileReader(new File("nextpartition.in"))).lines().toArray(String[]::new);
        Writer out = new FileWriter(new File("nextpartition.out"));
        String[] stringNums = lines[0].split("[=/+]");
        ArrayList<Integer> nums = new ArrayList<>();
        int n = stringNums.length;
        for (int i = 0; i < n; i++) {
            nums.add(Integer.parseInt(stringNums[i]));
        }
        if (n == 2) {
            out.write("No solution");
        } else {

            int v = nums.get(n - 2),
                    u = nums.get(n - 1);
            if (v + 1 <= u - 1) {
                nums.set(n - 2, v + 1);
                nums.set(n - 1, u - 1);
                v++;
                u--;
                if (2 * v <= u) {
                    while (true) {
                        nums.remove(n - 1);
                        nums.add(v);
                        nums.add(u - v);
                        n++;
                        if (v * 2 > u - v) {
                            break;
                        } else {
                            v = nums.get(n - 2);
                            u = nums.get(n - 1);
                        }
                    }
                }
            } else {
                nums.set(n - 2, v + u);
                nums.remove(n - 1);
                n--;
            }

            out.write(nums.get(0).toString() + "=");
            for (int i = 1; i < n; i++) {
                if (i != 1) {
                    out.write("+");
                }
                out.write(nums.get(i).toString());
            }
        }
        out.close();
    }
}
