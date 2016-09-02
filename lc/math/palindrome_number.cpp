

bool isPalindrome(int x) {
	if(x<0)
		return false;
	if(x<10)
		return true;
	int y=0, t=x%10;
	if(!t)
		return false;
	while(y<=x){
	x /= 10;
		if(x == y)
			return true;
		y = y*10 + t;
		if(x == y)
			return true;
		t = x%10;
	}
	return false;
}

