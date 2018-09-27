/*
	조합 : 선택의 순서가 결과에 영향을 주지 않음
	순열 : 선택의 순서가 결과에 영향을 줌
	
	nPr = n개 중 r개 뽑아서 순서있게 나열 
	
	


*/

// 순열 - 2개를 골라 만들 수 있는 최대 수 

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


// 조합 - 2개를 더해 만들 수 있는 최대 값
int N, tmp;
int Num[4];
int solve2(int pos, int cnt, int val) {
	if (cnt == 2) return val;
	if (pos == N) return -1;
	int ret = 0, temp;

	temp = solve(pos + 1, cnt + 1, val + Num[pos]);
	if (tmp > ret) ret = tmp;

	// 선택할 경우 

	tmp = solve(pos + 1, cnt, val);
	if (tmp > ret) ret = tmp;
	// 선택안할 경우


	return ret;
}