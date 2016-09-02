#include<string>

int states[10][6] = {
	0,1,6,4,-1,-1,
	-1,-1,6,4,-1,-1,
	-1,-1,7,-1,-1,-1,
	-1,2,7,-1,-1,-1,
	-1,-1,8,-1,-1,-1,
	9,-1,8,-1,3,-1,
	9,-1,6,5,3,-1,
	9,-1,7,-1,-1,-1,
	9,-1,8,-1,3,-1,
	9,-1,-1,-1,-1,-1
};

bool isNumber(std::string s) {
	int state = 0;
	int input = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]==' ')
			input = 0;
		else if(s[i]=='+' || s[i]=='-')
			input = 1;
		else if(s[i]>='0' && s[i]<='9')
			input = 2;
		else if(s[i]=='.')
			input = 3;
		else if(s[i]=='e' || s[i]=='E')
			input = 4;
		else
			input = 5;
		state = states[state][input];
		if(state==-1)
			return false;
	}
	if(state>4)
		return true;
	else
		return false;
}

