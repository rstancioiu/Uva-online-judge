import java.io.*;
import java.util.*;
import java.math.*;


public class Main{

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer tok = new StringTokenizer("");
	private static final int N = 128;

	private BigInteger[] numbers = new BigInteger[N];

	public static void main(String[] args) throws Exception{
		new Main().exec();
	}

	public void exec() throws Exception{
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		in.close();
		out.close();
	}

	void solve() throws IOException,NoSuchElementException{
		String line;
		BigInteger end = BigInteger.valueOf(-999999);
		while((line = in.readLine())!=null) {
			tok = new StringTokenizer(line);
			int p = 0;
			while(tok.hasMoreElements()){
				String s = tok.nextElement().toString();
				numbers[p] = new BigInteger(s);
				if(numbers[p].equals(end))
					break;
				p++;
			}
			BigInteger maximum = numbers[0];
			for(int i=0;i<p;++i){
				BigInteger product = BigInteger.valueOf(1);
				for(int j=i;j<p;++j){
					product = product.multiply(numbers[j]);
					if(product.compareTo(maximum)>0)
					{
						maximum = product;
					}
				}
			}
			out.println(maximum);
		}
	}
}