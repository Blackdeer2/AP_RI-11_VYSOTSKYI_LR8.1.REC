// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ... 
// 
// 1.   Вияснити, чи є серед цих символів пара сусідніх букв “no” або “on”.
// 
// 2.   Замінити кожну пару сусідніх букв “no” трійкою зірочок “***”.

#include <iostream>

using namespace std;

bool findOut(char* str, int i, bool t) {

	if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
		t = true;
	}
	if (str[i + 1] != 0)
		return findOut(str, i + 1, t);
	else
		return t;
}

char* Change(const char* str, char* dest, char* t, int i) {

	if (str[i] != 0) {
		if (str[i] == 'n' && str[i + 1] == 'o') {
			strcat_s(t, sizeof(t), "*** ");
			return  Change(str, dest, t + 3, i + 2);
		}
		else {
			*t++ = str[i++];
			*t = '\0';
			return  Change(str, dest, t, i);
		}
	}
	else {
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	//char str[101];
	//cout << "Enter string:" << endl;
	//cin.getline(str, 100);
	char str[]{ "I don't know what write" };
	cout << str << endl;
	bool t = false;
	if (findOut(str, 0, t) == true) {
		cout << " IS a pair of adjacent letters 'no' or 'on'" << endl;
	}
	else {
		cout << " NO a pair of adjacent letters 'no' or 'on'" << endl;
	}
	char* dest = new char[151];
	char* dest2;
	dest2 = Change(str, dest, dest, 0);
	cout << dest2 << endl;

	return 0;
}