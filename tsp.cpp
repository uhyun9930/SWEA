
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define INF 987654321

int N=4;
int ret;
int graph[4][4];
int solve(int pos, int visited) {
	
	//BASE CASE 
	if (visited == (1 << N) - 1) return 0;

	// 모든 도시를 방문 했으면 끝 
	// 1을 4만큼 shift 하면 1000
	// 1000 - 1하면 1111 이 됨. 4개의 정점을 모두 방문(bit가 1)한 것

	for (int next = 0; next < N; ++next) {
		if (!(visited & (1 << next)) && graph[pos][next]) {
		// 처음엔 pos가 0, visited가 1
		// next=0일때 1<<next는 1 visited한 부분임. (현재 사이클에서 visited는 1)
		// next=1일때 1<<next는 10, 10과 1이 &하면 0, visited한 부분이 아니기때문에 방문 아래로 이동
			int tmp = graph[pos][next] + solve(next, visited | (1 << next));
			// 해당 정점 방문할 때의 비용 더함                    
			// visited | (1 << next) ==> 1<<next (10)을 방문했다고 체크 1 | 10 하면 11이되고, 1번과 2번 정점 방문했다고 표시한 bit가 다음 재귀로 넘어감
			if (tmp < ret) ret = tmp;
		 }
	}
	return ret;
}
int main()
{
	int ans = INF;
	for (int i = 0; i < N; ++i) { //각 지점을 시작으로 탐색
		int tmp = solve(i, 1 << i);
		if (ans > tmp) ans = tmp;
	}
	
	return 0;
}
