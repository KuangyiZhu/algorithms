#include<vector>

std::vector<int> countBits(int num) {
	std::vector<int> res;
	res.push_back(0);
	int x=0, y=0;
	for(int i=1; i<=num; i++){
		x=i>>1;
		y=i&1;
		res.push_back(res[x]+y);
	}
	return res;
}
