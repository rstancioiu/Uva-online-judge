import java.io.*;
import java.util.*;
import java.math.BigInteger;

import java.util.StringTokenizer;

public class Main{

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok = new StringTokenizer("");
    private static final int N = 64;
    private BigInteger[] c = new BigInteger[N];
    public static void main(String[] args) throws Exception{
        new Main().exec();
    }
    public void exec()  throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in)); out = new PrintWriter(System.out);
        in = new BufferedReader(new InputStreamReader(new FileInputStream("largestroot.in")));
        out = new PrintWriter(new FileOutputStream("largestroot.out"));
        solve();
        in.close();
        out.close();
    }
    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }
    long readLong() throws IOException {
        return Long.parseLong(readString());
    }
    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
    BigInteger readBigInteger() throws IOException {
        return new BigInteger(readString());
    }
    // solution
    void solve() throws IOException {
        int t = readInt();
        while (t != 0) {
            t--;
            int n = readInt();
            for (int i = 0; i < n; ++i)
                c[i] = readBigInteger();
            int ans = -1;
            for (int r = 1; r <= 100; ++r) {
                BigInteger sum = c[n-1];
                BigInteger bint = BigInteger.valueOf(r);
                for (int i = n-2; i>=0; --i) {
                    BigInteger p = bint;
                    p = p.multiply(c[i]);
                    sum = p.add(sum);
                    bint = bint.multiply(BigInteger.valueOf(r));
                }
                sum= bint.add(sum);
                if (sum.equals(BigInteger.ZERO))
                    ans = r;
            }
            out.println(ans);
        }
    }
    void regexExemple()
    {
        List<String> input = new ArrayList<String>();
        input.add("123-45-6789");
        input.add("9876-5-4321");
        input.add("987-65-4321 (attack)");
        input.add("987-65-4321 ");
        input.add("192-83-7465");
        for (String ssn : input) {
            if (ssn.matches("^(\\d{3}-?\\d{2}-?\\d{4})$")) {
                System.out.println("Found good SSN: " + ssn);
            }
        } // result : Found good SSN: 123-45-6789</br> Found good SSN: 192-83-7465
    }
}
