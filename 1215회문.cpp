#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
char map[8][8];
int main()
{

	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);


	for (int t = 1; t <= 10; t++) {
		int num, cnt = 0;
		cin >> num;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				cin >> map[i][j];
		}


		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - num; j++) {
				int ck = j + (num - 1);
				int jj = j;
				int check = 1;
				while (ck >= jj) {
					if (map[i][jj++] != map[i][ck--]) {
						check = 0;
						break;
					}
				}

				if (check == 1) cnt++;
			}

			for (int j = 0; j <= 8 - num; j++) {
				int ck = j + (num - 1);
				int jj = j;
				int check = 1;
				while (ck >= jj) {
					if (map[jj++][i] != map[ck--][i]) {
						check = 0;
						break;
					}
				}

				if (check == 1) cnt++;
			}
		}
		cout << "#"<< t<< " "<<cnt << endl;
	}
}