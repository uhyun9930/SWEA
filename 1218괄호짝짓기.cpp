#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;
int main()
{
	freopen("input.txt", "rt", stdin);
	for (int t = 1; t <= 10; t++) {
		stack <char> s;
		int n, ans = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '(' || c == '{' || c == '<' || c == '[') { 
				s.push(c);
			
			}
			
			else if (c == ')' && s.top() == '(') s.pop();
			else if (c == '}' && s.top() == '{') s.pop();
			else if (c == '>' && s.top() == '<') s.pop();
			else if (c == ']' && s.top() == '[') s.pop();
			else{
				s.push(c);
			}
		
		}
	
		if (s.empty()) ans = 1; 
		cout << "#" << t << " " << ans << endl;
		
	}

}