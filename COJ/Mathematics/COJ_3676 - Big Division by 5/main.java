import java.util.Scanner;
import java.math.BigDecimal;

class DivByFive {

	public static void main(String[] args) {
		int numCases;
		Scanner in = new Scanner(System.in);
		BigDecimal bi;
		String s;
		numCases = in.nextInt() ;
		for (int i=1; i<=numCases; i++){
			bi = in.nextBigDecimal();
			System.out.print("Case "+i+": ");
			s = bi.divide(new BigDecimal("5")).toString().replace(".", ",");
			System.out.println(s);
		}
	}

}