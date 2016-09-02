#include<vector>

class NumArray {
private:
	std::vector<int> bitree;
	std::vector<int> rnums;
public:
	NumArray(std::vector<int> &nums) {
		bitree = std::vector<int>(nums.size()+1, 0);
		rnums = std::vector<int>(nums.size(), 0);
		for(int i=0; i<nums.size(); i++){
			update(i, nums[i]);
		}
	}

	void update(int i, int val) {
		int diff = val - rnums[i];
		if(diff==0)
			return;
		int j=i+1;
		while(j<bitree.size()){
			bitree[j] += diff;
			j += j&(-j);
		}
		rnums[i] = val;
	}
    
	int getSum(int i){
		int sum = 0;
		int j = i+1;
		while(j>0){
			sum += bitree[j];
			j -= j&(-j);
		}
		return sum;
	}

	int sumRange(int i, int j) {
		return getSum(j) - getSum(i-1);
	}
};
