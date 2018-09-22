#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <memory.h>
#define MAX 100
using namespace std;
bool visited[MAX] = { false };
int map[MAX][2];
int ans = 0; //길이 존재하면 1, 아니면 0


void dfs(int start) {
	
	visited[start] = true;
	//cout << start << "방문" << endl;

	if (start == 99) {
		ans = 1;
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (!visited[map[start][i]] && map[start][i]) {
			dfs(map[start][i]);
		}

	}
}
int main() {
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);


	for (int t = 1; t <= 10; t++) {
		int n, num;
		cin >> n >> num;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		ans = 0;
		for (int i = 0; i < num; i++) {
			int n1, n2;
			cin >> n1 >> n2; // n1->n2

			if (!map[n1][0]) map[n1][0] = n2;
			else {
				map[n1][1] = n2;
			}
		}

		dfs(0);


		cout << "#" << n << " " << ans << endl;
	}

}