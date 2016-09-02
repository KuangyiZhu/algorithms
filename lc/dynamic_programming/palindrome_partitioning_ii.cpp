#include<string>
#include<algorithm>
#include<climits>
#include<string.h>

int minCut(std::string s){
  int len = s.length();
        int dp[len+1];
        int pos[len+1];
        std::fill(dp, dp+len+1, INT_MAX);
        memset(pos, 0, sizeof(pos));
        dp[0] = -1;
        int max_start=0, max_len=1;
        int j=0, k=0;
        for(int i=0; i<len; i++){
                if(dp[i]<dp[i+1]-1){
                        dp[i+1] = dp[i]+1;
                        pos[i+1] = i;
                }
                j=i;
                while(i<len-1 && s[i]==s[i+1]){
                        if(dp[pos[j+1]] < dp[i+2]-1){
                                dp[i+2] = dp[pos[j+1]]+1;
                                pos[i+2] = pos[j+1];
                        }
                        i++;
                }
                k=i;
                while(j>0 && k<len-1  && s[j-1] == s[k+1]){
                        if(dp[j-1] < dp[k+2]){
                                dp[k+2] = dp[j-1]+1;
                                pos[k+2] = j;
                        }
                        j--;
                        k++;
                }
        }
        return dp[len];
}
