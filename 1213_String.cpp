

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
string compare, str;

int check(int i, int j, int n) {

	if (n == 1) {
		int c = 0;

		while (j >= 0) {
			if (str[i--] != compare[j--]) {
				c = compare.length();
				break;
			}
		}

		return c;
	}

	else if(n==0) {
		int c = 0;

		while (j >= 0) {
			if (str[i] == compare[j--] ) {
				return c;
			}
			c++;
		}

		return c;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	


	for (int t = 0; t < 10; t++) {
		int c, cnt = 0;
		cin >> c;

		cin >> compare;
		cin >> str;

		for (int i = compare.length() - 1; i < str.length(); i++) {
			int j = compare.length() - 1;
			if (str[i] == compare[j]) {
				int ck = check(i, j, 1);

				if (!ck) {
					cnt++;
					i = i + compare.length() - 1;
				}
				else {
					i = i + ck - 1;
				}
			}


			else {
				int ck = check(i, j, 0);
				i = i + ck - 1;
			}



			/*

			for (int i = 0; i <= s1.length() - s2.length(); i++) {
				int j = 0;
				if (s1[i] == s2[j]) {
					int ii = i;
					int jj = j;
					int check = 0;
					while (s1[++ii] == s2[++jj] && jj<s2.length()) {
						check++;

					}
					if (check==s2.length()-1) { cnt++; }
					i = ii-1;
				}
			}
			*/

		}
		cout << "#" << c << " " << cnt << endl;
	}
}