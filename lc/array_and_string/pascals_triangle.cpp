#include<vector>

std::vector<std::vector<int>> generate(int numRows) {
	std::vector<std::vector<int>> triangle;
	if(!numRows)
		return triangle;
	triangle.push_back(std::vector<int>());
	triangle[0].push_back(1);
	for(int i=1; i<numRows; i++){
		triangle.push_back(std::vector<int>());
		triangle[i].push_back(1);
		for(int j=1; j<i; j++){
			triangle[i].push_back(triangle[i-1][j-1]+triangle[i-1][j]);
		}
		triangle[i].push_back(1);
	}
	return triangle;
}
