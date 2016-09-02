#include<vector>

int maxProfit(std::vector<int>& prices) {
	int n=prices.size();
	if(!n)
		return 0;
	int min=prices[0], max=0, earn=0;
	for(int i=1; i<n; i++){
		earn=prices[i]-min;
		if(prices[i]<min)
			min=prices[i];
		if(earn>max)
			max = earn;
	}
	return max;
}
