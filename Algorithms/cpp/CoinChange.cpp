/*You are given coins of different denominations and a total amount of money amount. 
 * Write a function to compute the fewest number of coins that you need to make up that 
 * amount. If that amount of money cannot be made up by any combination of the coins, 
 * return -1.
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 ***************************************************************************************/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int d[amount + 1];
    	memset(d, -1, sizeof(d));
    	d[0] = 0;
    	
    	for (int j = 1; j <= amount; j++) {
    	    for (int i = 0; i < coins.size(); i++) {
    	    	if (j >= coins[i] && d[j - coins[i]] != -1) {
    	    	    d[j] = d[j] == -1 ? d[j - coins[i]] + 1 : min(d[j], d[j - coins[i]] + 1);
    		    }
    	    }
    	}
    	return d[amount];
    }
};

