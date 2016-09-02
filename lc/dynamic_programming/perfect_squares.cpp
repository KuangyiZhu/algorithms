#include<vector>
#include<cmath>
#include<string.h>

int numSquares(int n) {
	std::vector<int> perfect;
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	int i=1, s=1;
	while(s<=n){
		perfect.push_back(s);
		s=std::pow(i++, 2);
	}
	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1]+1;
		for(int j=1; j<perfect.size(); j++){
			if(i-perfect[j]>=0 && dp[i-perfect[j]]<dp[i]){
				dp[i] = dp[i-perfect[j]] + 1;
			}
		}
	}
	return dp[n];
}
