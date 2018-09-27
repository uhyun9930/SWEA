#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 987654321.0
#define MAX 17
int W[MAX][MAX];

int N;
//������� dp
int memo[17][65536], dist[17][17];

int TSP(int cur, int visited) {

	if (visited == (1 << N) - 1) { 
		return dist[cur][0] ? dist[cur][0] : INF;	
	}
	// ��ü�� �湮 ���� ���
	
	int& ret = memo[cur][visited];//�޸����̼�
	if (ret != 0)return ret; //�̹� ����� ���� ���� ���
	ret = INF;
	for (int next = 0; next <= N; next++) {
		if (visited & (1 << next))continue; //next�� �湮�ߴ� ���� ��� 
		if (dist[cur][next] == 0)continue; //next���� ���� x, or �ڱ��ڽ��� ���
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