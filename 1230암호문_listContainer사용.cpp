#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
using namespace std;
int main()
{
	freopen("input.txt", "rt", stdin);
	std::ios::sync_with_stdio(false);
	for (int t = 1; t <= 10; t++) {
		int len;
		cin >> len;

		list<int> lt;
		list<int> ::iterator iter = lt.begin();

		for (int l = 0; l < len; l++) {
			int num;
			cin >> num;
			lt.push_back(num);
		}
		
		int len2;
		cin >> len2;

		for (int l = 0; l < len2; l++) {
			char c;
			cin >> c;
			if (c == 'I') {
				
				int index, cnt;
				cin >> index >> cnt;
				for (int cc = 0; cc < cnt; cc++) {
			
					int num2;
					cin >> num2;

					int i = 0;
					iter = lt.begin();
					while (i++ < index + cc)
						++iter;
					lt.insert(iter, num2);
				}
			}
			if (c == 'D') {

				int index, cnt;
				cin >> index >> cnt;
				for (int cc = 0; cc < cnt; cc++) {
					int i = 0;
					iter = lt.begin();
					while (i++ < index)
						++iter;
					lt.erase(iter);

				}
			}
			if (c == 'A') {
				int cnt;
				cin >> cnt;
				for (int cc = 0; cc < cnt; cc++) {
					int num2;
					cin >> num2;
					lt.push_back(num2);
				}
			}
		}

		cout << "#" << t << " ";
		int a = 0;
		for (iter = lt.begin(); iter != lt.end(); iter++)
		{
			if (a++ <= 9) {
				cout << *iter << " ";
			}
			else {
				break;
			}
		}
		cout << endl;
	}

}