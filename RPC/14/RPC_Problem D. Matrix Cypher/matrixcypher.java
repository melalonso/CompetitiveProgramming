import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;


class matrixcypher
{
	
	static boolean identity(BigInteger [][]bi){
		return bi[0][0].equals(BigInteger.ONE) && bi[0][1].equals(BigInteger.ZERO) && 
			   bi[1][0].equals(BigInteger.ZERO) && bi[1][1].equals(BigInteger.ONE);
	}
	
	
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger [][]bi = new BigInteger[2][2];
		String line, value[];
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
		line = br.readLine();
		value = line.split(" ");
		bi[0][0] = new BigInteger(value[0]);
		bi[0][1] = new BigInteger(value[1]);
		line = br.readLine();
		value = line.split(" ");
		bi[1][0] = new BigInteger(value[0]);
		bi[1][1] = new BigInteger(value[1]);
		
		while(identity(bi)==false){
			if ( bi[0][0].add(bi[0][1]).compareTo(bi[1][0].add(bi[1][1])) == 1 ){
				bi[0][0] = bi[0][0].subtract(bi[1][0]);
				bi[0][1] = bi[0][1].subtract(bi[1][1]);
				System.out.print("1");
			}else{
				bi[1][0] = bi[1][0].subtract(bi[0][0]);
				bi[1][1] = bi[1][1].subtract(bi[0][1]);
				System.out.print("0");
			}
		}
		System.out.print("\n");
	}
}