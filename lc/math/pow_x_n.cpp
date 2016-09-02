double myPow(double x, int n) {
	double res = 1;
	if(n<0)
		x = 1/x;
	while(n!=0){
		if(n%2 != 0)
			res *= x;
		x = x * x;
		n /= 2;
	}
	return res;
}

