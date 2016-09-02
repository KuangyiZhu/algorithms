#include<string>
#include<string.h>

bool isMatch(std::string s, std::string p) {
	int n = p.length();
	bool dp[n+1];
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	bool prev;
	int k=1;
	while(k<n){
		if(p[k]=='*')
			dp[k+1]=true;
		else
			break;
		k+=2;
	}
	for(int i=0; i<s.length(); i++){
		dp[n]=false;
		for(int j=n-1; j>=0; j--){
			if(dp[j]){
				dp[j]=false;
				if(p[j]=='.' || s[i]==p[j]){
					int k=j+2;
					if(p[j+1]=='*'){
						k--;
						dp[j]=true;
					}
					while(k<n && p[k]=='*'){
						dp[k+1]=true;
						k+=2;
					}
					dp[j+1]=true;
				}
			}
		}
	}
	return dp[n];
}
