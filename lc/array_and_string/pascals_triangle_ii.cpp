#include<vector>

std::vector<int> getRow(int rowIndex) {
	std::vector<int> row;
	int prev;
	row.push_back(1);
	for(int i=1; i<=rowIndex; i++){
		prev=1;
		for(int j=1; j<i; j++){
			std::swap(row[j], prev);
			row[j]+=prev;
		}
		row.push_back(1);
	}
	return row;
}
