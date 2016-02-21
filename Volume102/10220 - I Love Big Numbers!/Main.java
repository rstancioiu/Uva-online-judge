import java.io.*;
import java.util.*;
import java.math.*;


public class Main{
	private BufferedReader in;
	private PrintWriter out;
	private static final int N = 64;
	private BigInteger[] c = new BigInteger[N];

	public static void main(String[] args) throws Exception{
		new Main().exec();
	}

	public void exec() throws Exception{
		//in = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		in.close();
		out.close();
	}

	void solve() throws IOException {
		int n;
		String s;
		while ((s=in.readLine())!=null) {
			n = Integer.parseInt(s);
			BigInteger number = BigInteger.valueOf(1);
			for (int i = 1; i <= n; ++i)
				number = number.multiply(BigInteger.valueOf(i));
			String str = number.toString();
			int cnt=0;
			for(int i=0;i<str.length();++i)
			{
				int p = str.charAt(i)-'0';
				cnt = cnt+p;
			}
			out.println(cnt);
		}
	}
}