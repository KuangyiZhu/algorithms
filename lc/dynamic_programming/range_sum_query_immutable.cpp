#include<vector>

class NumArray {
private:
	std::vector<int> sums;
public:
	NumArray(std::vector<int> &nums) {
		sums.push_back(0);
		for(int i=1; i<=nums.size(); i++){
			sums.push_back(sums[i-1]+nums[i-1]);
		}
	}

	int sumRange(int i, int j) {
		return sums[j+1] - sums[i];
	}
};
