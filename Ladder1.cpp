#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#define MAX 100

int map[MAX][MAX];
int dx[3] = { 1,-1,0 };
int dy[3] = { 0,0,1 };
int visited[MAX][MAX] = { 0 };
int ans=0;

void dfs(int y, int x, int start) {

	if (y == MAX - 1)
	{
		if (map[y][x] != 2) {
			return;
		}
		else {
			ans = start; 
			return;
		}
	}
	
	if (map[y][x] == 1) {

		visited[y][x] = 1;
		int nx, ny;

		for (int i = 0; i < 3; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (ny >= 0 && nx >= 0 && ny < MAX && nx < MAX && visited[ny][nx] == 0 && (map[ny][nx] == 1 || map[ny][nx] == 2)) break;
		}

		dfs(ny, nx, start);

	}
	visited[y][x] = 0;
			
}

int main()
{


	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);



	for (int t = 0; t < 10; t++) {
		int n;
		cin >> n;
		
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
			}
		}



		for (int i = 0; i < MAX; i++) {
			dfs(0, i, i);
			if (ans != 0) break;
		}

		cout << "#" << n << " " << ans << "\n";
		ans = 0;
	}

}