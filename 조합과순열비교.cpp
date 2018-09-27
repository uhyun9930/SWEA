/*
	���� : ������ ������ ����� ������ ���� ����
	���� : ������ ������ ����� ������ ��
	
	nPr = n�� �� r�� �̾Ƽ� �����ְ� ���� 
	
	


*/

// ���� - 2���� ��� ���� �� �ִ� �ִ� �� 

int solve(int cnt, int used, int val) {
	if (cnt == 2) {
		return val;
	} //BASE CASE
	
	int ret = 0;
	
	for (int i = 0; i < N; i++) {
		if (used & (1 << i)) continue;
		int temp = solve(cnt + 1, used | (1 << i), val * 10 + Num[i]);
		if (temp > ret) ret = temp;
	}
	return ret;
}


// ���� - 2���� ���� ���� �� �ִ� �ִ� ��
int N, tmp;
int Num[4];
int solve2(int pos, int cnt, int val) {
	if (cnt == 2) return val;
	if (pos == N) return -1;
	int ret = 0, temp;

	temp = solve(pos + 1, cnt + 1, val + Num[pos]);
	if (tmp > ret) ret = tmp;

	// ������ ��� 

	tmp = solve(pos + 1, cnt, val);
	if (tmp > ret) ret = tmp;
	// ���þ��� ���


	return ret;
}