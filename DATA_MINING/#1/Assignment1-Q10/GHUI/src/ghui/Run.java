package ghui;

import java.io.IOException;
import java.util.List;
import java.util.Set;

/**
 * Example of how to use the GHUI-Miner algorithm 
 * from the source code.
 * This example first applies CHUI-Miner to discover 
 * closed high utility itemsets.
 * Then, it applies GHUI-Miner to find GHUIs.
 * @author Philippe Fournier-Viger, 2014
 */
public class Run {

	public static void main(String [] arg) throws IOException{

		String input = "input";
		int min_utility =  30; 
		
		String output = "output";
		
		// (1) Applying the CHUI-Miner algorithm to find 
		// closed high utility itemsets (CHUIs)
		System.out.println("Step 1: Mining CHUIs...");
		AlgoCHUIMiner chuiMineClosed = new AlgoCHUIMiner(true);
		List<List<Itemset>> closedItemsets = chuiMineClosed.runAlgorithm(input, min_utility, null);
		chuiMineClosed.printStats();
		Set<Integer> itemsInClosedItemsets = chuiMineClosed.setOfItemsInClosedItemsets;

		System.out.println("Step 2: Mining GHUIs...");
		// (2) Apply the GHUI-Miner algorithm to find
		// the set of generators of high utility itemsets (GHUIs)
		AlgoGHUIMINER ghuiMiner = new AlgoGHUIMINER();
		ghuiMiner.runAlgorithm(input, output, min_utility, closedItemsets, itemsInClosedItemsets);
		ghuiMiner.printStats();
		

	}
}
