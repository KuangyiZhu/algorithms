#include<string>
#include<vector>

bool isValid(std::string s) {
	std::vector<char> parentheses;
	for(int i=0; i<s.length(); i++){
		switch(s[i]){
			case '(':
			case '[':
			case '{':
				parentheses.push_back(s[i]);
				break;
			case ')':
				if(parentheses.empty() || parentheses.back()!='(')
					return false;
				parentheses.pop_back();
				break;
			case ']':
				if(parentheses.empty() || parentheses.back()!='[')
					return false;
				parentheses.pop_back();
				break;
			case '}':
				if(parentheses.empty() || parentheses.back()!='{')
					return false;
				parentheses.pop_back();
				break;
		}
	}
	return parentheses.empty();
}
