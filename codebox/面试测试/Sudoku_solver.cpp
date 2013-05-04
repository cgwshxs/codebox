bool checkValid(vector<string>& board, int x, int y){
	bool flags[9] = {0};
	//����Ч
	for(int i = 0; i < 9; ++i){
		if(board[x][i] >= '1' && board[x][i] <= '9'){
			if(!flags[board[x][i] - '1'])
				flags[board[x][i] - '1'] = true;
			else
				return false;
		}
	}
	//����Ч
	memset(flags, 0, 9);
	for(int i = 0; i < 9; ++i){
		if(board[i][y] >= '1' && board[i][y] <= '9'){
			if(!flags[board[i][y] - '1'])
				flags[board[i][y] - '1'] = true;
			else
				return false;
		}
	}
	//С�Ź�����Ч
	int xx = x/3*3;
	int yy = y/3*3;
	memset(flags, 0, 9);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(board[xx+i][yy+j] >= '1' && board[xx+i][yy+j] <= '9'){
				if(!flags[board[xx+i][yy+j]-'1'])
					flags[board[xx+i][yy+j]-'1'] = true;
				else
					return false;
			}
		}
	}
	return true;
}
bool solve(vector<string>&board){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] != '.')
				continue;
			for(char k = '1'; k <= '9'; k++){//����һ����
				board[i][j] = k;
				if(checkValid(board,i,j)){//��Ч�������
					if(solve(board))
						return true;
				}
				board[i][j] = '.';//��Ч��ԭ
			}
			return false;
		}
	}
	return true;
}