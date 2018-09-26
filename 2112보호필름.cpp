/*#include<iostream>
using namespace std;
#define MAX_W 21
#define MAX_D 14


int ans=987654321;
int d, w, k;
int arr[MAX_D][MAX_W];
bool checkArr[MAX_D] = { false };

bool film_check(int n) { 
	int a, b;
	bool state;

	if (n == 0) {
		for (int i = 1; i <= w; i++) {
			a = 0;
			b = 0;
			state = false;
			for (int j = 1; j <= d; j++) {
				if (arr[j][i]==0 || checkArr[j]) {
					a++;
					b = 0;	
				}
				else if(arr[j][i]==1 || checkArr[j]) {
					b++;
					a = 0;
				}
				if (a == k || b == k) {
					state = true;
					break;
				}
			}
			if (state == false) return false;
		}
	}
	else if (n == 1) {
		for (int i = 1; i <= w; i++) {
			a = 0;
			b = 0;
			state = false;
			for (int j = 1; j <= d; j++) {
				if (arr[j][i] == 1 || checkArr[j]) {
					b++;
					a = 0;
				}
				else if (arr[j][i] == 0 || checkArr[j]) {
					a++;
					b = 0;
				}
				if (a == k || b == k) {
					state = true;
					break;
				}
			}
			if (state == false) return false;
		}
	}
	return true;

} //필름 상태 확인

void dfs(int idx, int cnt) {
	
	if (cnt ==k+1 || cnt >= ans) return; 
	//가지치기
	
	checkArr[idx] = true;
	
	if (film_check(0)||film_check(1)) {
		if (cnt <= ans) ans = cnt;
	}
	for (int i = idx+1; i <= d; i++) {
		dfs(i, cnt + 1);
	}
	checkArr[idx] = false;
}

int main()
{

	std::ios::sync_with_stdio(false);
	
	freopen("input.txt", "rt", stdin);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> d >> w >> k;

		
		for (int i = 1; i <= d; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}

		
		//if (!film_check(0)) { 
			dfs(0, 0); 
		//}
		//else {
		//	ans = 0;
		//}
		cout << "#" << t << " " << ans << endl;

		ans = 987654321;
		for (int i = 0; i < MAX_D; i++) {
			checkArr[i] = false;
		}

		//0-w-1, 0-d-1 까지랑 1-w, 1-d까지 값이 다르게 나오는 이유가 뭐지? 
	}
}
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void data_in();
short int DEPTH, WIDTH, CRITERIA;
short int medicines[6][8];
short int min_push;

void fill_medicines_on_row(int _row, short int _type);
void recursive(short int idx, short int cnt);
bool isSatisfied(short int cnt);

int main() {
	
	freopen("input.txt", "rt", stdin);

	int test_case;
	cin >> test_case;

	for (int tt = 1; tt <= test_case; tt++) {
		// 데이터 입력
		cin >> DEPTH >> WIDTH >> CRITERIA;
		data_in();

		// 최소값에 대한 초기값 설정
		min_push = CRITERIA;

		if (!isSatisfied(0)) // 데이터가 조건을 만족하는지 먼저 확인(투입 횟수 0)
			recursive(0, 0); // 만족하지 않는다면 재귀함수 수행
		cout << "#" << tt << " " << min_push << endl;
	}

	system("pause");
	return 0;
}

void data_in() {
	for (int row = 0; row < DEPTH; row++) {
		for (int col = 0; col < WIDTH; col++)
			cin >> medicines[row][col];
	}
}

void fill_medicines_on_row(int _row, short int _type) {
	for (int col = 0; col < WIDTH; col++)
		medicines[_row][col] = _type;
}

bool isSatisfied(short int cnt) {
	// 한 열씩 비교
	for (int col = 0; col < WIDTH; col++) {
		int current = medicines[0][col];
		int cnt = 1;
		bool FLAG = false;

		if (CRITERIA == 1) continue;
		for (int row = 1; row < DEPTH; row++) {
			if (current == medicines[row][col]) {
				cnt++;
				// 동일한 요소라면 cnt++, CRITERIA 이상인 경우 해당 열은 조건을 만족한다.
				if (cnt >= CRITERIA) {
					FLAG = true;
					break;
				}
			}
			else { // 동일한 요소가 아닌경우 (A..B..AB~)인 경우, 현재 비교할 문자를 바꾸어주고, cnt = 1로 초기화
				current = medicines[row][col];
				cnt = 1;
			}
		}

		if (!FLAG) return false;
	}

	// 아래의 명령줄을 수행할 수 있다는 것은 모든 열이 조건을 만족한다.
	min_push = min_push > cnt ? cnt : min_push; // 최소값
	return true;
}

void recursive(short int idx, short int cnt) {
	if (idx == DEPTH && cnt < min_push) isSatisfied(cnt); //조건에 만족하는지 확인
	if (idx == DEPTH || cnt >= min_push) return; // DEPTH초과, 혹은 현재의 최소 투여 횟수보다 크다면 리턴

	int raw[20]; // 해당 행에 대하여 원본 저장
	for (int i = 0; i < WIDTH; i++) raw[i] = medicines[idx][i];

	recursive(idx + 1, cnt); // 해당 행에 주입하지 않는 경우

	fill_medicines_on_row(idx, 0); // 해당 행에 A를 주입하는 경우 
	recursive(idx + 1, cnt + 1);

	fill_medicines_on_row(idx, 1); // 해당 행에 B를 주입하는 경우
	recursive(idx + 1, cnt + 1);

	for (int i = 0; i < WIDTH; i++) medicines[idx][i] = raw[i]; //원본 복구
}