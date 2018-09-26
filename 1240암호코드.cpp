#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <cstdio>
//using namespace std;
int tc, N, M;
int map[51][101];
int checkStartLine;
int checkCode[8];
int code[10][7] = { {0,0,0,1,1,0,1},{ 0,0,1,1,0,0,1 },{ 0,0,1,0,0,1,1 },{ 0,1,1,1,1,0,1 },{ 0,1,0,0,0,1,1 },{ 0,1,1,0,0,0,1 },{ 0,1,0,1,1,1,1 },{ 0,1,1,1,0,1,1 },{ 0,1,1,0,1,1,1 },{ 0,0,0,1,0,1,1 } };
int search(int start) {

	for (int c = 0; c < 10; c++) {
		int j = 0;
		for (int i = start; i < start+7; i++) {
			
			if (code[c][j++] != map[checkStartLine][i]) {
				break;
			}
			if (j == 7) return c;
		}
	}
	return -1;
}

bool searchALL(int start) {

	int a = 1;
	bool state = true;
	for (int m = start + 7; m <= M - 7; m = m + 7) {
		checkCode[a] = search(m);
		if (checkCode[a] == -1) break;
		a++;
		if (a >= 8) { break; }
	}

	for (int i = 0; i < 8; i++) {
		if (checkCode[i] == -1) state = false;
	}

	return state;
}

int main()
{
	//std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &tc);
	
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &N, &M);

		checkStartLine = 0;
		for (int i = 0; i < 8; i++)
			checkCode[i] = -1;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%1d", &map[n][m]);

				if (map[n][m] && !checkStartLine) checkStartLine = n;
			}
		}

		///

		
		checkCode[0] = -1;
		int firstN=-1;
		for (int m = 0; m < M - 7; m++) {
			checkCode[0] = search(m);

			if (0 <= checkCode[0]) { 				
				firstN = m;
				if (searchALL(firstN))break;
				else {
					for (int i = 0; i < 8; i++) checkCode[i] = -1;
				}
			}
		}
		int res = 0;
		res = ((checkCode[0] + checkCode[2] + checkCode[4] + checkCode[6]) * 3) + (checkCode[1] + checkCode[3] + checkCode[5]) + checkCode[7];
		if (res % 10 == 0) {
			res = 0;
			for (int i = 0; i < 8; i++) {
				res += checkCode[i];
			}
		}
		else {
			res = 0;
			}
		
		
		printf("#%d %d\n", t, res);
	}

}