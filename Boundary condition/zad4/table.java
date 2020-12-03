import java.io.*;
import java.util.Scanner;

public class table{
	public static void main(String [] args)  throws FileNotFoundException{
		//double N3 = 10E+3, N4 = 10E+4, N5 = 10E+5;
		//double tmax[] = {7.5, 10, 15, 20, 25, 30, 35};
		//for (int i = 0; i < 7; i++) tmax[i] *= 1.0E-9;
		
		double dif3_075 = 0, dif4_075 = 0, dif5_075 = 0;
		double maxdif3_075 = 0, maxdif4_075 = 0, maxdif5_075 = 0;
		double dif3_10 = 0, dif4_10 = 0, dif5_10 = 0;
		double maxdif3_10 = 0, maxdif4_10 = 0, maxdif5_10 = 0;
		double dif3_15 = 0, dif4_15 = 0, dif5_15 = 0;
		double maxdif3_15 = 0, maxdif4_15 = 0, maxdif5_15 = 0;
		double dif3_20 = 0, dif4_20 = 0, dif5_20 = 0;
		double maxdif3_20 = 0, maxdif4_20 = 0, maxdif5_20 = 0;
		double dif3_25 = 0, dif4_25 = 0, dif5_25 = 0;
		double maxdif3_25 = 0, maxdif4_25 = 0, maxdif5_25 = 0;
		double dif3_30 = 0, dif4_30 = 0, dif5_30 = 0;
		double maxdif3_30 = 0, maxdif4_30 = 0, maxdif5_30 = 0;
		double dif3_35 = 0, dif4_35 = 0, dif5_35 = 0;
		double maxdif3_35 = 0, maxdif4_35 = 0, maxdif5_35 = 0;
		
		//double f0_0 = 0.0, f0_1 = 1.0E+9, f0_3 = 3.0E+9, f0_9 = 9.0E+9, f0_27 = 27.0E+9;
		
		PrintWriter out = new PrintWriter("out_table.txt");
		out.println("f0(*10^9) tmax N(*10^-9) ||UA - Unum||inf");
		
		File in0 = new File("out0.txt");
		Scanner sc0 = new Scanner(in0);
		
		
		while(sc0.hasNextLine()){
			String line = sc0.nextLine();
			String [] lineStrings = line.split(" ");
			double lineDoubles[] = new double[50];
			for(int i = 0; i < 50; i++){
				lineDoubles[i] = Double.parseDouble(lineStrings[i]);
			}
			
			dif3_075 = Math.abs(lineDoubles[3]);
			if(dif3_075 > maxdif3_075) maxdif3_075 = dif3_075;
			dif4_075 = Math.abs(lineDoubles[5]);
			if(dif4_075 > maxdif4_075) maxdif4_075 = dif4_075;
			dif5_075 = Math.abs(lineDoubles[7]);
			if(dif5_075 > maxdif5_075) maxdif5_075 = dif5_075;
			
			dif3_10 = Math.abs(lineDoubles[10]);
			if(dif3_10 > maxdif3_10) maxdif3_10 = dif3_10;
			dif4_10 = Math.abs(lineDoubles[12]);
			if(dif4_10 > maxdif4_10) maxdif4_10 = dif4_10;
			dif5_10 = Math.abs(lineDoubles[14]);
			if(dif5_10 > maxdif5_10) maxdif5_10 = dif5_10;
			
			dif3_15 = Math.abs(lineDoubles[17]);
			if(dif3_15 > maxdif3_15) maxdif3_15 = dif3_15;
			dif4_15 = Math.abs(lineDoubles[19]);
			if(dif4_15 > maxdif4_15) maxdif4_15 = dif4_15;
			dif5_15 = Math.abs(lineDoubles[21]);
			if(dif5_15 > maxdif5_15) maxdif5_15 = dif5_15;

			dif3_20 = Math.abs(lineDoubles[24]);
			if(dif3_20 > maxdif3_20) maxdif3_20 = dif3_20;
			dif4_20 = Math.abs(lineDoubles[26]);
			if(dif4_20 > maxdif4_20) maxdif4_20 = dif4_20;
			dif5_20 = Math.abs(lineDoubles[28]);
			if(dif5_20 > maxdif5_20) maxdif5_20 = dif5_20;

			dif3_25 = Math.abs(lineDoubles[31]);
			if(dif3_25 > maxdif3_25) maxdif3_25 = dif3_25;
			dif4_25 = Math.abs(lineDoubles[33]);
			if(dif4_25 > maxdif4_25) maxdif4_25 = dif4_25;
			dif5_25 = Math.abs(lineDoubles[35]);
			if(dif5_25 > maxdif5_25) maxdif5_25 = dif5_25;

			dif3_30 = Math.abs(lineDoubles[38]);
			if(dif3_30 > maxdif3_30) maxdif3_30 = dif3_30;
			dif4_30 = Math.abs(lineDoubles[40]);
			if(dif4_30 > maxdif4_30) maxdif4_30 = dif4_30;
			dif5_30 = Math.abs(lineDoubles[42]);
			if(dif5_30 > maxdif5_30) maxdif5_30 = dif5_30;

			dif3_35 = Math.abs(lineDoubles[45]);
			if(dif3_35 > maxdif3_35) maxdif3_35 = dif3_35;
			dif4_35 = Math.abs(lineDoubles[47]);
			if(dif4_35 > maxdif4_35) maxdif4_35 = dif4_35;
			dif5_35 = Math.abs(lineDoubles[49]);
			if(dif5_35 > maxdif5_35) maxdif5_35 = dif5_35;			
		}
		

		out.println(0 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(0 + " " + 7.5 + " " + "10^4" + " " + maxdif4_075);
		out.println(0 + " " + 7.5 + " " + "10^5" + " " + maxdif5_075);
		out.println(0 + " " + 10 + " " + "10^3" + " " + maxdif3_10);
		out.println(0 + " " + 10 + " " + "10^4" + " " + maxdif4_10);
		out.println(0 + " " + 10 + " " + "10^5" + " " + maxdif5_10);
		out.println(0 + " " + 15 + " " + "10^3" + " " + maxdif3_15);
		out.println(0 + " " + 15 + " " + "10^4" + " " + maxdif4_15);
		out.println(0 + " " + 15 + " " + "10^5" + " " + maxdif5_15);
		out.println(0 + " " + 20 + " " + "10^3" + " " + maxdif3_20);
		out.println(0 + " " + 20 + " " + "10^4" + " " + maxdif4_20);
		out.println(0 + " " + 20 + " " + "10^5" + " " + maxdif5_20);
		out.println(0 + " " + 25 + " " + "10^3" + " " + maxdif3_25);
		out.println(0 + " " + 25 + " " + "10^4" + " " + maxdif4_25);
		out.println(0 + " " + 25 + " " + "10^5" + " " + maxdif5_25);	
		out.println(0 + " " + 30 + " " + "10^3" + " " + maxdif3_30);
		out.println(0 + " " + 30 + " " + "10^4" + " " + maxdif4_30);
		out.println(0 + " " + 30 + " " + "10^5" + " " + maxdif5_30);		
		out.println(0 + " " + 35 + " " + "10^3" + " " + maxdif3_35);
		out.println(0 + " " + 35 + " " + "10^4" + " " + maxdif4_35);
		out.println(0 + " " + 35 + " " + "10^5" + " " + maxdif5_35);

//////////////////////////////////////////////////////////////////////////////////////////

		File in1 = new File("out1.txt");
		Scanner sc1 = new Scanner(in1);
		
		
		while(sc1.hasNextLine()){
			String line = sc1.nextLine();
			String [] lineStrings = line.split(" ");
			double lineDoubles[] = new double[50];
			for(int i = 0; i < 50; i++){
				lineDoubles[i] = Double.parseDouble(lineStrings[i]);
			}
			
			dif3_075 = Math.abs(lineDoubles[3]);
			if(dif3_075 > maxdif3_075) maxdif3_075 = dif3_075;
			dif4_075 = Math.abs(lineDoubles[5]);
			if(dif4_075 > maxdif4_075) maxdif4_075 = dif4_075;
			dif5_075 = Math.abs(lineDoubles[7]);
			if(dif5_075 > maxdif5_075) maxdif5_075 = dif5_075;
			
			dif3_10 = Math.abs(lineDoubles[10]);
			if(dif3_10 > maxdif3_10) maxdif3_10 = dif3_10;
			dif4_10 = Math.abs(lineDoubles[12]);
			if(dif4_10 > maxdif4_10) maxdif4_10 = dif4_10;
			dif5_10 = Math.abs(lineDoubles[14]);
			if(dif5_10 > maxdif5_10) maxdif5_10 = dif5_10;
			
			dif3_15 = Math.abs(lineDoubles[17]);
			if(dif3_15 > maxdif3_15) maxdif3_15 = dif3_15;
			dif4_15 = Math.abs(lineDoubles[19]);
			if(dif4_15 > maxdif4_15) maxdif4_15 = dif4_15;
			dif5_15 = Math.abs(lineDoubles[21]);
			if(dif5_15 > maxdif5_15) maxdif5_15 = dif5_15;

			dif3_20 = Math.abs(lineDoubles[24]);
			if(dif3_20 > maxdif3_20) maxdif3_20 = dif3_20;
			dif4_20 = Math.abs(lineDoubles[26]);
			if(dif4_20 > maxdif4_20) maxdif4_20 = dif4_20;
			dif5_20 = Math.abs(lineDoubles[28]);
			if(dif5_20 > maxdif5_20) maxdif5_20 = dif5_20;

			dif3_25 = Math.abs(lineDoubles[31]);
			if(dif3_25 > maxdif3_25) maxdif3_25 = dif3_25;
			dif4_25 = Math.abs(lineDoubles[33]);
			if(dif4_25 > maxdif4_25) maxdif4_25 = dif4_25;
			dif5_25 = Math.abs(lineDoubles[35]);
			if(dif5_25 > maxdif5_25) maxdif5_25 = dif5_25;

			dif3_30 = Math.abs(lineDoubles[38]);
			if(dif3_30 > maxdif3_30) maxdif3_30 = dif3_30;
			dif4_30 = Math.abs(lineDoubles[40]);
			if(dif4_30 > maxdif4_30) maxdif4_30 = dif4_30;
			dif5_30 = Math.abs(lineDoubles[42]);
			if(dif5_30 > maxdif5_30) maxdif5_30 = dif5_30;

			dif3_35 = Math.abs(lineDoubles[45]);
			if(dif3_35 > maxdif3_35) maxdif3_35 = dif3_35;
			dif4_35 = Math.abs(lineDoubles[47]);
			if(dif4_35 > maxdif4_35) maxdif4_35 = dif4_35;
			dif5_35 = Math.abs(lineDoubles[49]);
			if(dif5_35 > maxdif5_35) maxdif5_35 = dif5_35;			
		}
		

		out.println(1 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(1 + " " + 7.5 + " " + "10^4" + " " + maxdif4_075);
		out.println(1 + " " + 7.5 + " " + "10^5" + " " + maxdif5_075);
		out.println(1 + " " + 10 + " " + "10^3" + " " + maxdif3_10);
		out.println(1 + " " + 10 + " " + "10^4" + " " + maxdif4_10);
		out.println(1 + " " + 10 + " " + "10^5" + " " + maxdif5_10);
		out.println(1 + " " + 15 + " " + "10^3" + " " + maxdif3_15);
		out.println(1 + " " + 15 + " " + "10^4" + " " + maxdif4_15);
		out.println(1 + " " + 15 + " " + "10^5" + " " + maxdif5_15);
		out.println(1 + " " + 20 + " " + "10^3" + " " + maxdif3_20);
		out.println(1 + " " + 20 + " " + "10^4" + " " + maxdif4_20);
		out.println(1 + " " + 20 + " " + "10^5" + " " + maxdif5_20);
		out.println(1 + " " + 25 + " " + "10^3" + " " + maxdif3_25);
		out.println(1 + " " + 25 + " " + "10^4" + " " + maxdif4_25);
		out.println(1 + " " + 25 + " " + "10^5" + " " + maxdif5_25);	
		out.println(1 + " " + 30 + " " + "10^3" + " " + maxdif3_30);
		out.println(1 + " " + 30 + " " + "10^4" + " " + maxdif4_30);
		out.println(1 + " " + 30 + " " + "10^5" + " " + maxdif5_30);		
		out.println(1 + " " + 35 + " " + "10^3" + " " + maxdif3_35);
		out.println(1 + " " + 35 + " " + "10^4" + " " + maxdif4_35);
		out.println(1 + " " + 35 + " " + "10^5" + " " + maxdif5_35);
		
//////////////////////////////////////////////////////////////////////////////////////////

		File in3 = new File("out3.txt");
		Scanner sc3 = new Scanner(in3);
		
		
		while(sc3.hasNextLine()){
			String line = sc3.nextLine();
			String [] lineStrings = line.split(" ");
			double lineDoubles[] = new double[50];
			for(int i = 0; i < 50; i++){
				lineDoubles[i] = Double.parseDouble(lineStrings[i]);
			}
			
			dif3_075 = Math.abs(lineDoubles[3]);
			if(dif3_075 > maxdif3_075) maxdif3_075 = dif3_075;
			dif4_075 = Math.abs(lineDoubles[5]);
			if(dif4_075 > maxdif4_075) maxdif4_075 = dif4_075;
			dif5_075 = Math.abs(lineDoubles[7]);
			if(dif5_075 > maxdif5_075) maxdif5_075 = dif5_075;
			
			dif3_10 = Math.abs(lineDoubles[10]);
			if(dif3_10 > maxdif3_10) maxdif3_10 = dif3_10;
			dif4_10 = Math.abs(lineDoubles[12]);
			if(dif4_10 > maxdif4_10) maxdif4_10 = dif4_10;
			dif5_10 = Math.abs(lineDoubles[14]);
			if(dif5_10 > maxdif5_10) maxdif5_10 = dif5_10;
			
			dif3_15 = Math.abs(lineDoubles[17]);
			if(dif3_15 > maxdif3_15) maxdif3_15 = dif3_15;
			dif4_15 = Math.abs(lineDoubles[19]);
			if(dif4_15 > maxdif4_15) maxdif4_15 = dif4_15;
			dif5_15 = Math.abs(lineDoubles[21]);
			if(dif5_15 > maxdif5_15) maxdif5_15 = dif5_15;

			dif3_20 = Math.abs(lineDoubles[24]);
			if(dif3_20 > maxdif3_20) maxdif3_20 = dif3_20;
			dif4_20 = Math.abs(lineDoubles[26]);
			if(dif4_20 > maxdif4_20) maxdif4_20 = dif4_20;
			dif5_20 = Math.abs(lineDoubles[28]);
			if(dif5_20 > maxdif5_20) maxdif5_20 = dif5_20;

			dif3_25 = Math.abs(lineDoubles[31]);
			if(dif3_25 > maxdif3_25) maxdif3_25 = dif3_25;
			dif4_25 = Math.abs(lineDoubles[33]);
			if(dif4_25 > maxdif4_25) maxdif4_25 = dif4_25;
			dif5_25 = Math.abs(lineDoubles[35]);
			if(dif5_25 > maxdif5_25) maxdif5_25 = dif5_25;

			dif3_30 = Math.abs(lineDoubles[38]);
			if(dif3_30 > maxdif3_30) maxdif3_30 = dif3_30;
			dif4_30 = Math.abs(lineDoubles[40]);
			if(dif4_30 > maxdif4_30) maxdif4_30 = dif4_30;
			dif5_30 = Math.abs(lineDoubles[42]);
			if(dif5_30 > maxdif5_30) maxdif5_30 = dif5_30;

			dif3_35 = Math.abs(lineDoubles[45]);
			if(dif3_35 > maxdif3_35) maxdif3_35 = dif3_35;
			dif4_35 = Math.abs(lineDoubles[47]);
			if(dif4_35 > maxdif4_35) maxdif4_35 = dif4_35;
			dif5_35 = Math.abs(lineDoubles[49]);
			if(dif5_35 > maxdif5_35) maxdif5_35 = dif5_35;			
		}
		

		out.println(3 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(3 + " " + 7.5 + " " + "10^4" + " " + maxdif4_075);
		out.println(3 + " " + 7.5 + " " + "10^5" + " " + maxdif5_075);
		out.println(3 + " " + 10 + " " + "10^3" + " " + maxdif3_10);
		out.println(3 + " " + 10 + " " + "10^4" + " " + maxdif4_10);
		out.println(3 + " " + 10 + " " + "10^5" + " " + maxdif5_10);
		out.println(3 + " " + 15 + " " + "10^3" + " " + maxdif3_15);
		out.println(3 + " " + 15 + " " + "10^4" + " " + maxdif4_15);
		out.println(3 + " " + 15 + " " + "10^5" + " " + maxdif5_15);
		out.println(3 + " " + 20 + " " + "10^3" + " " + maxdif3_20);
		out.println(3 + " " + 20 + " " + "10^4" + " " + maxdif4_20);
		out.println(3 + " " + 20 + " " + "10^5" + " " + maxdif5_20);
		out.println(3 + " " + 25 + " " + "10^3" + " " + maxdif3_25);
		out.println(3 + " " + 25 + " " + "10^4" + " " + maxdif4_25);
		out.println(3 + " " + 25 + " " + "10^5" + " " + maxdif5_25);	
		out.println(3 + " " + 30 + " " + "10^3" + " " + maxdif3_30);
		out.println(3 + " " + 30 + " " + "10^4" + " " + maxdif4_30);
		out.println(3 + " " + 30 + " " + "10^5" + " " + maxdif5_30);		
		out.println(3 + " " + 35 + " " + "10^3" + " " + maxdif3_35);
		out.println(3 + " " + 35 + " " + "10^4" + " " + maxdif4_35);
		out.println(3 + " " + 35 + " " + "10^5" + " " + maxdif5_35);

//////////////////////////////////////////////////////////////////////////////////////////

		File in9 = new File("out9.txt");
		Scanner sc9 = new Scanner(in9);
		
		
		while(sc9.hasNextLine()){
			String line = sc9.nextLine();
			String [] lineStrings = line.split(" ");
			double lineDoubles[] = new double[50];
			for(int i = 0; i < 50; i++){
				lineDoubles[i] = Double.parseDouble(lineStrings[i]);
			}
			
			dif3_075 = Math.abs(lineDoubles[3]);
			if(dif3_075 > maxdif3_075) maxdif3_075 = dif3_075;
			dif4_075 = Math.abs(lineDoubles[5]);
			if(dif4_075 > maxdif4_075) maxdif4_075 = dif4_075;
			dif5_075 = Math.abs(lineDoubles[7]);
			if(dif5_075 > maxdif5_075) maxdif5_075 = dif5_075;
			
			dif3_10 = Math.abs(lineDoubles[10]);
			if(dif3_10 > maxdif3_10) maxdif3_10 = dif3_10;
			dif4_10 = Math.abs(lineDoubles[12]);
			if(dif4_10 > maxdif4_10) maxdif4_10 = dif4_10;
			dif5_10 = Math.abs(lineDoubles[14]);
			if(dif5_10 > maxdif5_10) maxdif5_10 = dif5_10;
			
			dif3_15 = Math.abs(lineDoubles[17]);
			if(dif3_15 > maxdif3_15) maxdif3_15 = dif3_15;
			dif4_15 = Math.abs(lineDoubles[19]);
			if(dif4_15 > maxdif4_15) maxdif4_15 = dif4_15;
			dif5_15 = Math.abs(lineDoubles[21]);
			if(dif5_15 > maxdif5_15) maxdif5_15 = dif5_15;

			dif3_20 = Math.abs(lineDoubles[24]);
			if(dif3_20 > maxdif3_20) maxdif3_20 = dif3_20;
			dif4_20 = Math.abs(lineDoubles[26]);
			if(dif4_20 > maxdif4_20) maxdif4_20 = dif4_20;
			dif5_20 = Math.abs(lineDoubles[28]);
			if(dif5_20 > maxdif5_20) maxdif5_20 = dif5_20;

			dif3_25 = Math.abs(lineDoubles[31]);
			if(dif3_25 > maxdif3_25) maxdif3_25 = dif3_25;
			dif4_25 = Math.abs(lineDoubles[33]);
			if(dif4_25 > maxdif4_25) maxdif4_25 = dif4_25;
			dif5_25 = Math.abs(lineDoubles[35]);
			if(dif5_25 > maxdif5_25) maxdif5_25 = dif5_25;

			dif3_30 = Math.abs(lineDoubles[38]);
			if(dif3_30 > maxdif3_30) maxdif3_30 = dif3_30;
			dif4_30 = Math.abs(lineDoubles[40]);
			if(dif4_30 > maxdif4_30) maxdif4_30 = dif4_30;
			dif5_30 = Math.abs(lineDoubles[42]);
			if(dif5_30 > maxdif5_30) maxdif5_30 = dif5_30;

			dif3_35 = Math.abs(lineDoubles[45]);
			if(dif3_35 > maxdif3_35) maxdif3_35 = dif3_35;
			dif4_35 = Math.abs(lineDoubles[47]);
			if(dif4_35 > maxdif4_35) maxdif4_35 = dif4_35;
			dif5_35 = Math.abs(lineDoubles[49]);
			if(dif5_35 > maxdif5_35) maxdif5_35 = dif5_35;			
		}
		

		out.println(9 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(9 + " " + 7.5 + " " + "10^4" + " " + maxdif4_075);
		out.println(9 + " " + 7.5 + " " + "10^5" + " " + maxdif5_075);
		out.println(9 + " " + 10 + " " + "10^3" + " " + maxdif3_10);
		out.println(9 + " " + 10 + " " + "10^4" + " " + maxdif4_10);
		out.println(9 + " " + 10 + " " + "10^5" + " " + maxdif5_10);
		out.println(9 + " " + 15 + " " + "10^3" + " " + maxdif3_15);
		out.println(9 + " " + 15 + " " + "10^4" + " " + maxdif4_15);
		out.println(9 + " " + 15 + " " + "10^5" + " " + maxdif5_15);
		out.println(9 + " " + 20 + " " + "10^3" + " " + maxdif3_20);
		out.println(9 + " " + 20 + " " + "10^4" + " " + maxdif4_20);
		out.println(9 + " " + 20 + " " + "10^5" + " " + maxdif5_20);
		out.println(9 + " " + 25 + " " + "10^3" + " " + maxdif3_25);
		out.println(9 + " " + 25 + " " + "10^4" + " " + maxdif4_25);
		out.println(9 + " " + 25 + " " + "10^5" + " " + maxdif5_25);	
		out.println(9 + " " + 30 + " " + "10^3" + " " + maxdif3_30);
		out.println(9 + " " + 30 + " " + "10^4" + " " + maxdif4_30);
		out.println(9 + " " + 30 + " " + "10^5" + " " + maxdif5_30);		
		out.println(9 + " " + 35 + " " + "10^3" + " " + maxdif3_35);
		out.println(9 + " " + 35 + " " + "10^4" + " " + maxdif4_35);
		out.println(9 + " " + 35 + " " + "10^5" + " " + maxdif5_35);

//////////////////////////////////////////////////////////////////////////////////////////

		File in27 = new File("out27.txt");
		Scanner sc27 = new Scanner(in27);
		
		
		while(sc27.hasNextLine()){
			String line = sc27.nextLine();
			String [] lineStrings = line.split(" ");
			double lineDoubles[] = new double[50];
			for(int i = 0; i < 50; i++){
				lineDoubles[i] = Double.parseDouble(lineStrings[i]);
			}
			
			dif3_075 = Math.abs(lineDoubles[3]);
			if(dif3_075 > maxdif3_075) maxdif3_075 = dif3_075;
			dif4_075 = Math.abs(lineDoubles[5]);
			if(dif4_075 > maxdif4_075) maxdif4_075 = dif4_075;
			dif5_075 = Math.abs(lineDoubles[7]);
			if(dif5_075 > maxdif5_075) maxdif5_075 = dif5_075;
			
			dif3_10 = Math.abs(lineDoubles[10]);
			if(dif3_10 > maxdif3_10) maxdif3_10 = dif3_10;
			dif4_10 = Math.abs(lineDoubles[12]);
			if(dif4_10 > maxdif4_10) maxdif4_10 = dif4_10;
			dif5_10 = Math.abs(lineDoubles[14]);
			if(dif5_10 > maxdif5_10) maxdif5_10 = dif5_10;
			
			dif3_15 = Math.abs(lineDoubles[17]);
			if(dif3_15 > maxdif3_15) maxdif3_15 = dif3_15;
			dif4_15 = Math.abs(lineDoubles[19]);
			if(dif4_15 > maxdif4_15) maxdif4_15 = dif4_15;
			dif5_15 = Math.abs(lineDoubles[21]);
			if(dif5_15 > maxdif5_15) maxdif5_15 = dif5_15;

			dif3_20 = Math.abs(lineDoubles[24]);
			if(dif3_20 > maxdif3_20) maxdif3_20 = dif3_20;
			dif4_20 = Math.abs(lineDoubles[26]);
			if(dif4_20 > maxdif4_20) maxdif4_20 = dif4_20;
			dif5_20 = Math.abs(lineDoubles[28]);
			if(dif5_20 > maxdif5_20) maxdif5_20 = dif5_20;

			dif3_25 = Math.abs(lineDoubles[31]);
			if(dif3_25 > maxdif3_25) maxdif3_25 = dif3_25;
			dif4_25 = Math.abs(lineDoubles[33]);
			if(dif4_25 > maxdif4_25) maxdif4_25 = dif4_25;
			dif5_25 = Math.abs(lineDoubles[35]);
			if(dif5_25 > maxdif5_25) maxdif5_25 = dif5_25;

			dif3_30 = Math.abs(lineDoubles[38]);
			if(dif3_30 > maxdif3_30) maxdif3_30 = dif3_30;
			dif4_30 = Math.abs(lineDoubles[40]);
			if(dif4_30 > maxdif4_30) maxdif4_30 = dif4_30;
			dif5_30 = Math.abs(lineDoubles[42]);
			if(dif5_30 > maxdif5_30) maxdif5_30 = dif5_30;

			dif3_35 = Math.abs(lineDoubles[45]);
			if(dif3_35 > maxdif3_35) maxdif3_35 = dif3_35;
			dif4_35 = Math.abs(lineDoubles[47]);
			if(dif4_35 > maxdif4_35) maxdif4_35 = dif4_35;
			dif5_35 = Math.abs(lineDoubles[49]);
			if(dif5_35 > maxdif5_35) maxdif5_35 = dif5_35;			
		}
		

		System.out.println(27 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(27 + " " + 7.5 + " " + "10^3" + " " + maxdif3_075);
		out.println(27 + " " + 7.5 + " " + "10^4" + " " + maxdif4_075);
		out.println(27 + " " + 7.5 + " " + "10^5" + " " + maxdif5_075);
		out.println(27 + " " + 10 + " " + "10^3" + " " + maxdif3_10);
		out.println(27 + " " + 10 + " " + "10^4" + " " + maxdif4_10);
		out.println(27 + " " + 10 + " " + "10^5" + " " + maxdif5_10);
		out.println(27 + " " + 15 + " " + "10^3" + " " + maxdif3_15);
		out.println(27 + " " + 15 + " " + "10^4" + " " + maxdif4_15);
		out.println(27 + " " + 15 + " " + "10^5" + " " + maxdif5_15);
		out.println(27 + " " + 20 + " " + "10^3" + " " + maxdif3_20);
		out.println(27 + " " + 20 + " " + "10^4" + " " + maxdif4_20);
		out.println(27 + " " + 20 + " " + "10^5" + " " + maxdif5_20);
		out.println(27 + " " + 25 + " " + "10^3" + " " + maxdif3_25);
		out.println(27 + " " + 25 + " " + "10^4" + " " + maxdif4_25);
		out.println(27 + " " + 25 + " " + "10^5" + " " + maxdif5_25);	
		out.println(27 + " " + 30 + " " + "10^3" + " " + maxdif3_30);
		out.println(27 + " " + 30 + " " + "10^4" + " " + maxdif4_30);
		out.println(27 + " " + 30 + " " + "10^5" + " " + maxdif5_30);		
		out.println(27 + " " + 35 + " " + "10^3" + " " + maxdif3_35);
		out.println(27 + " " + 35 + " " + "10^4" + " " + maxdif4_35);
		out.println(27 + " " + 35 + " " + "10^5" + " " + maxdif5_35);

//////////////////////////////////////////////////////////////////////////////////////////
		
		out.close();
	}
}