#include<vector>

int maxProfit(std::vector<int>& prices) {
	int n=prices.size();
	if(!n)
		return 0;
	int max=0;
	int buy=prices[0];
	for(int i=1; i<n; i++){
		if(prices[i]<prices[i-1]){
			max += prices[i-1] - buy;
			buy = prices[i];
		}
	}
	max += prices[n-1] - buy;
	return max;
}
