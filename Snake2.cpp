#include <iostream>
using namespace std;
char a[100][100];
int main() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i == 1 || i == 100) {
				a[i][j] = "#";
			}

		}
	}
	for (int i = 0, i <= 100, i++) {
		for (int j = 0, j <= 100, j++) {
			cout << a[i][j] << " "
		}
		cout << endl;
	}
}