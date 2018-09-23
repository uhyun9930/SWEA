#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <memory.h>
#include <utility>
#define MAX 100

int map[MAX][MAX];
int visited[MAX][MAX];
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int sx, sy, fx, fy,ans=0;
queue <pair<int, int>> q;

void bfs() {


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		if (map[y][x] == 3) {
			ans= 1;
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (map[ny][nx] != 1 && visited[ny][nx] == false) {
				q.push(make_pair(nx, ny));
				visited[ny][nx] = true;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin);


	for (int t = 0; t < 10; t++) {


		memset(visited, 0, sizeof(visited));

		int n;
		scanf("%d", &n);
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					sx = j;
					sy = i;
				}
				if (map[i][j] == 3) {
					fx = j;
					fy = i;
				}
			}
		}

		q.push(make_pair(sx, sy));
		visited[sy][sx] = true;

		bfs();
		printf("#%d %d\n", n, ans);
		ans = 0;
	}
}