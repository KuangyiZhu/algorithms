#include<string>
#include<string.h>

int minDistance(std::string word1, std::string word2) {
	if(word1.length()==0)
		return word2.size();
	if(word2.length()==0)
		return word1.size();
	int n = word1.length() + 1;
	int dp[n];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++){
		dp[i] = i;
	}
	int prev;
	for(int i=0; i<word2.length(); i++){
		prev = dp[0];
		dp[0]++;
		for(int j=0; j<word1.length(); j++){
			if(word1[j] == word2[i]){
				std::swap(prev, dp[j+1]);
			}
			else{
				if(prev<dp[j+1])
					std::swap(prev, dp[j+1]);
				else
					prev=dp[j+1];
				dp[j+1] = (dp[j+1]<dp[j]?dp[j+1]:dp[j]) + 1;
			}
		}
	}
	return dp[n-1];
}
