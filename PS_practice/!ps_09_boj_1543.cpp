#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string text, word;

int main() {
	getline(cin, text);
	getline(cin, word);

	if (text.size() < word.size()) {
		cout << 0 << endl;
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < text.size() - word.size() + 1; i++) {
		bool check = true;
		for (int j = 0; j < word.size(); j++) {
			if (word[j] != text[i + j]) {
				check = false;
				break;
			}
		}

		if (check) {
			cnt++;
			i += word.size() - 1;
		}
	}

	cout << cnt << endl;
}