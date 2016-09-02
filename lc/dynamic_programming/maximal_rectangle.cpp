#include<vector>
#include<string.h>

int maximalRectangle(std::vector<std::vector<char>>& matrix) {
	int row_size=matrix.size();
	if(row_size==0)
		return 0;
	int col_size=matrix[0].size();
	int left[col_size];
	int right[col_size];
	int height[col_size];
	memset(left, 0, sizeof(left));
	memset(height, 0 ,sizeof(height));
	std::fill(right, right+col_size, col_size-1);
	int max=0;
	for(int i=0; i<row_size; i++){
		int curr_left=0, curr_right=col_size-1;
		for(int j=0; j<col_size; j++){
			if(matrix[i][j]=='0'){
				height[j]=0;
				left[j]=0;
				curr_left=j+1;
			}
			else{
				height[j]++;
				left[j]=std::max(left[j], curr_left);
			}
		}
		for(int j=col_size-1; j>=0; j--){
			if(matrix[i][j]=='0'){
				right[j]=col_size-1;
				curr_right=j-1;
			}
			else{
				right[j]=std::min(right[j], curr_right);
				if(max<(right[j]-left[j]+1)*height[j])
				max=(right[j]-left[j]+1)*height[j];
			}
		}
	}
	return max;
}
