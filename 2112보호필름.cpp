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

} //�ʸ� ���� Ȯ��

void dfs(int idx, int cnt) {
	
	if (cnt ==k+1 || cnt >= ans) return; 
	//����ġ��
	
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

		//0-w-1, 0-d-1 ������ 1-w, 1-d���� ���� �ٸ��� ������ ������ ����? 
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
		// ������ �Է�
		cin >> DEPTH >> WIDTH >> CRITERIA;
		data_in();

		// �ּҰ��� ���� �ʱⰪ ����
		min_push = CRITERIA;

		if (!isSatisfied(0)) // �����Ͱ� ������ �����ϴ��� ���� Ȯ��(���� Ƚ�� 0)
			recursive(0, 0); // �������� �ʴ´ٸ� ����Լ� ����
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
	// �� ���� ��
	for (int col = 0; col < WIDTH; col++) {
		int current = medicines[0][col];
		int cnt = 1;
		bool FLAG = false;

		if (CRITERIA == 1) continue;
		for (int row = 1; row < DEPTH; row++) {
			if (current == medicines[row][col]) {
				cnt++;
				// ������ ��Ҷ�� cnt++, CRITERIA �̻��� ��� �ش� ���� ������ �����Ѵ�.
				if (cnt >= CRITERIA) {
					FLAG = true;
					break;
				}
			}
			else { // ������ ��Ұ� �ƴѰ�� (A..B..AB~)�� ���, ���� ���� ���ڸ� �ٲپ��ְ�, cnt = 1�� �ʱ�ȭ
				current = medicines[row][col];
				cnt = 1;
			}
		}

		if (!FLAG) return false;
	}

	// �Ʒ��� ������� ������ �� �ִٴ� ���� ��� ���� ������ �����Ѵ�.
	min_push = min_push > cnt ? cnt : min_push; // �ּҰ�
	return true;
}

void recursive(short int idx, short int cnt) {
	if (idx == DEPTH && cnt < min_push) isSatisfied(cnt); //���ǿ� �����ϴ��� Ȯ��
	if (idx == DEPTH || cnt >= min_push) return; // DEPTH�ʰ�, Ȥ�� ������ �ּ� ���� Ƚ������ ũ�ٸ� ����

	int raw[20]; // �ش� �࿡ ���Ͽ� ���� ����
	for (int i = 0; i < WIDTH; i++) raw[i] = medicines[idx][i];

	recursive(idx + 1, cnt); // �ش� �࿡ �������� �ʴ� ���

	fill_medicines_on_row(idx, 0); // �ش� �࿡ A�� �����ϴ� ��� 
	recursive(idx + 1, cnt + 1);

	fill_medicines_on_row(idx, 1); // �ش� �࿡ B�� �����ϴ� ���
	recursive(idx + 1, cnt + 1);

	for (int i = 0; i < WIDTH; i++) medicines[idx][i] = raw[i]; //���� ����
}