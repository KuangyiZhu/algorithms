#include<vector>
#include<string.h>

int maxProfit(std::vector<int>& prices) {
	int n=prices.size();
	if(!n)
		return 0;
	int dp[n];
	memset(dp, 0, sizeof(dp));
	int max=0, min=prices[0], diff=0, earn=0;
	for(int i=1; i<n; i++){
		if(prices[i]<min)
			min=prices[i];
		diff=prices[i]-min;
		if(diff>earn)
			earn=diff;
		dp[i] = dp[i-1]+prices[i]-prices[i-1];
		if(dp[i]<earn)
			dp[i]=earn;
		if(dp[i]>max)
			max = dp[i];
	}
	return max;
}
