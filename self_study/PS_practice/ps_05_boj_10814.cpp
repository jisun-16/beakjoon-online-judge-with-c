#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef struct P {
	int num;
	int age;
	string name;
}person;
person Person[100001];
bool cmp(person a, person b) {
	if (a.age < b.age) return true;
	else if (a.age > b.age) return false;
	else {
		if (a.num < b.num) return true;
		else return false;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> Person[i].age >> Person[i].name;
		Person[i].num=i;
	}
	sort(Person, Person + n, cmp);
	for (int i = 0; i < n; i++) cout << Person[i].age << ' ' << Person[i].name << '\n';
}