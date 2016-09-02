#include<vector>
#include<algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
	int n=matrix.size()-1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++){
			std::swap(matrix[i][j], matrix[n-j][n-i]);
		}
	}
	for(int i=0; i<matrix.size()/2; i++){
		std::swap(matrix[i], matrix[n-i]);
	}
}

