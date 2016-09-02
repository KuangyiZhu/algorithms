#include<vector>
#include<string.h>

int coinChange(std::vector<int>& coins, int amount) {
	unsigned int dp[amount+1];
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	for(int i=1; i<=amount; i++){
		for(int j=0; j<coins.size(); j++){
			if(i-coins[j]>=0){
				if(dp[i-coins[j]]!=-1 && dp[i-coins[j]]<dp[i])
					dp[i] = dp[i-coins[j]]+1;
			}
		}
	}
	return dp[amount];
}
