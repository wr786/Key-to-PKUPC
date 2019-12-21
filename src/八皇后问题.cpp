#include<cstdio>
int vis[9][9];
int dx[2] = {1, 1}, dy[2] = {1, -1};
int idx;

void visit_col(int row, int col, int color) {
	for(int i=row + 1; i < 9; i++)
		if(vis[i][col] == row - color)
			vis[i][col] = color;
	vis[row][col] = color?999:0;
}

void visit_inline(int posx, int posy, int color) {
	for(int dir=0; dir<2; dir++) {
		int tmpx = posx + dx[dir], tmpy = posy + dy[dir];
		while(tmpx >= 1 && tmpx <= 8 && tmpy >= 1 && tmpy <= 8) {
			if(vis[tmpx][tmpy] == posx - color)
				vis[tmpx][tmpy] = color;
			tmpx += dx[dir];
			tmpy += dy[dir];
		}
	}
	vis[posx][posy] = color?999:0;
}

void Eight_Queen(int row) {
	if(row == 9) {
		printf("%d\n", ++idx);
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				if(j > 1) printf(" ");
				if(vis[j][i] == 999) printf("*"); // 注意转置输出！
				else printf(".");
			}
			printf("\n");
		}
		return;
	}
	for(int col = 1; col <= 8; col++) {
		if(vis[row][col] == 0) {
			visit_col(row, col, row);
			visit_inline(row, col, row);
			Eight_Queen(row + 1);
			visit_col(row, col, 0);
			visit_inline(row, col, 0);
		}
	}
}

int main() {
	Eight_Queen(1);
	return 0;
}
