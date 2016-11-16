package fhmplus;

import java.io.IOException;

/**
 * Example of how to use the FHM+ algorithm 
 * from the source code.
 * @author Philippe Fournier-Viger, 2016
 */
public class Run {

	public static void main(String [] arg) throws IOException{
		
		String input = "input";
		String output = "output";

		// minimum utility threshold
		int min_utility = 30;  
		
		// minimum and maximum length
		int minimumLength = 2; 
		int maximumLength = 3; 
		
		// Applying the algorithm
		AlgoFHMPlus algo = new AlgoFHMPlus();
		algo.runAlgorithm(input, output, min_utility, minimumLength, maximumLength);
		algo.printStats();
	}
}