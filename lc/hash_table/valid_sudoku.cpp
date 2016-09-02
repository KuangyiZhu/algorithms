#include<vector>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
	bool row[9][9]={false};
	bool col[9][9]={false};
	bool cel[9][9]={false};
	int value, celIndex;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j]!='.'){
				value=board[i][j]-49;
				celIndex=(i/3)*3+j/3;
				if(row[i][value]||col[j][value]||cel[celIndex][value])
					return false;
				row[i][value]=true;
				col[j][value]=true;
				cel[celIndex][value]=true;
			}
		}
	}
	return true;
}
