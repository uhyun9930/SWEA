
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

	// ��� ���ø� �湮 ������ �� 
	// 1�� 4��ŭ shift �ϸ� 1000
	// 1000 - 1�ϸ� 1111 �� ��. 4���� ������ ��� �湮(bit�� 1)�� ��

	for (int next = 0; next < N; ++next) {
		if (!(visited & (1 << next)) && graph[pos][next]) {
		// ó���� pos�� 0, visited�� 1
		// next=0�϶� 1<<next�� 1 visited�� �κ���. (���� ����Ŭ���� visited�� 1)
		// next=1�϶� 1<<next�� 10, 10�� 1�� &�ϸ� 0, visited�� �κ��� �ƴϱ⶧���� �湮 �Ʒ��� �̵�
			int tmp = graph[pos][next] + solve(next, visited | (1 << next));
			// �ش� ���� �湮�� ���� ��� ����                    
			// visited | (1 << next) ==> 1<<next (10)�� �湮�ߴٰ� üũ 1 | 10 �ϸ� 11�̵ǰ�, 1���� 2�� ���� �湮�ߴٰ� ǥ���� bit�� ���� ��ͷ� �Ѿ
			if (tmp < ret) ret = tmp;
		 }
	}
	return ret;
}
int main()
{
	int ans = INF;
	for (int i = 0; i < N; ++i) { //�� ������ �������� Ž��
		int tmp = solve(i, 1 << i);
		if (ans > tmp) ans = tmp;
	}
	
	return 0;
}
