#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int checkIn(char c) {

	if (c == '+') return 1;
	if (c == '*') return 2;
	if (c == '(') return 0;

}
int checkOut(char c) {

	if (c == '+') return 1;
	if (c == '*') return 2;
	if (c == '(') return 3;
}

int main()

{
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	for (int t = 1; t <= 10; t++) {
		int len;
		cin >> len;
		string s;
		cin >> s;

		vector<char> posix;
		stack<char> st1;
		for (int i = 0; i < len; i++) {

			if (s[i] == '+'|| s[i] == '*' || s[i]=='(' || s[i] ==')') {
				
				if (st1.empty()) st1.push(s[i]);
				
				else if (s[i] == ')') {
					while (st1.top() != '(') {
						posix.push_back(st1.top());
						st1.pop();
					}
					st1.pop(); // '('까지 pop해주기
				}
				
				else {
					while (checkOut(s[i]) <= checkIn(st1.top())) {
						posix.push_back(st1.top());
						st1.pop();
						if (st1.empty())break;
					}
					st1.push(s[i]);
				}
			}

			else {
				posix.push_back(s[i]);
			}
		}


		while (!st1.empty()) {
			posix.push_back(st1.top());
			st1.pop();
		}//중위 표기법에서 후위 표기법 변경

		stack <int> st2;

		for (int i = 0; i < posix.size(); i++) {
			if (posix[i] == '+'|| posix[i] == '*') {
				int n1, n2, nn;
				n2 = st2.top();
				st2.pop();
				n1 = st2.top();
				st2.pop();
				if (posix[i] == '+')
					nn = n1 + n2;
				else if (posix[i] == '*')
					nn = n1 * n2;
				st2.push(nn);
			}
			else {
				st2.push(posix[i] - '0');
			}
		}
		cout << "#" << t << " " << st2.top() << endl;
	}



}