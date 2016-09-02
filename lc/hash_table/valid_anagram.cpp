#include<string>
#include<map>

bool isAnagram(std::string s, std::string t) {
	if(s.length()!=t.length())
		return false;
	std::map<char, int> flags;
	for(int i=0; i<s.length(); i++){
		flags[s[i]]++;
		flags[t[i]]--;
	}
	for(std::map<char, int>::iterator it=flags.begin(); it!=flags.end(); it++){
		if(it->second != 0){
			return false;
		}
	}
	return true;
}
