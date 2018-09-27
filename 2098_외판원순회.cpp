#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 987654321.0
#define MAX 17
int W[MAX][MAX];

int N;
//경로저장 dp
int memo[17][65536], dist[17][17];

int TSP(int cur, int visited) {

	if (visited == (1 << N) - 1) { 
		return dist[cur][0] ? dist[cur][0] : INF;	
	}
	// 전체를 방문 했을 경우
	
	int& ret = memo[cur][visited];//메모리제이션
	if (ret != 0)return ret; //이미 계산한 값이 있을 경우
	ret = INF;
	for (int next = 0; next <= N; next++) {
		if (visited & (1 << next))continue; //next가 방문했던 곳일 경우 
		if (dist[cur][next] == 0)continue; //next로의 길이 x, or 자기자신일 경우
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
	}

	return ret;
}
int main() {
	freopen("input.txt", "rt", stdin);
	std::ios::sync_with_stdio(false);
	cin >> N;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}

	cout << TSP(0, 1);
}