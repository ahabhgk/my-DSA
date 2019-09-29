#include <iostream>
using namespace std;

void loopPrinter(int n) {
	for (;n > 0; n--) cout << n << endl;
	return;
}

void recursivePrinter(int n) {
	if (n == 0) return;
	cout << n << endl;
	recursivePrinter(n - 1);
}

void(*const fn)(int) = recursivePrinter;
// const void(*fn)(int) 表示 fn 返回值是常量

int main() {
	fn(1000000);
}
