#include<string>
#include<string.h>

int lengthOfLongestSubstring(std::string s) {
	int res=0, count=0;
	int mp[256];
	memset(mp, 0, sizeof(mp));
	int i=0, j=-1;
	for(i=0; i<s.length(); i++){
		mp[s[i]]++;
		while(mp[s[i]]>1){
			j++;
			mp[s[j]]--;
		}
		if(i-j>res)
			res=i-j;
	}
	return res;
}
