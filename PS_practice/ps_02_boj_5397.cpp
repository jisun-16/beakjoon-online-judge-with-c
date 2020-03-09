#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string password;
		stack<char> left, right;

		cin >> password;

		for (int i = 0; i < password.length(); i++) {
			if (password[i] == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (password[i] == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (password[i] == '-') {
				if(!left.empty())
					left.pop();
			}
			else {
				left.push(password[i]);
			}
		}

		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}

		string ans;
		while (!right.empty()) {
			ans += right.top();
			right.pop();
		}
		cout <<ans<< '\n';
	}
}//의외로 헤맸음.. 커서를 기준으로 왼쪽과 오른쪽을 스텍으로 쌓는다