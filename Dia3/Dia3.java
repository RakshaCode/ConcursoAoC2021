import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Dia3 {
	final private static int nDigits = 12;

	public static void problem1 (BufferedReader buffReader) throws IOException {
		int[] gamma_rate = new int[nDigits];
		int nLines = 0, i = 0;
		double num;

		String line;

		nLines = 0;

		while((line = buffReader.readLine()) != null) {
			num = Double.parseDouble(line);
			i = 0;
			while(i < nDigits){
				gamma_rate[i++] += num % 2;
				num /= 10;
			}
			++nLines;
		}

		int gamma = 0, epsilon = 0;

		for(i = nDigits - 1; i >= 0; i--){
			if(nLines/2 <= gamma_rate[i]){
				gamma += Math.pow(2, i);
			}
			else {
				epsilon += Math.pow(2, i);
			}
		}
		System.out.println("Consumo de energía: " + gamma * epsilon);
	}

	public static void problem2 (BufferedReader buffReader) throws IOException {

	}

	public static void main (String []args) throws IOException {
		BufferedReader buffReader = new BufferedReader(new FileReader("./input"));
		problem1(buffReader);
		problem2(buffReader);
	}
}
