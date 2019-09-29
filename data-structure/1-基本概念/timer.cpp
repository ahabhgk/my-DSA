#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

clock_t start, stop;
double duration;
const int MAXN = 10;

double f1(int n, double a[], double x) {
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
		p += (a[i] * pow(x, i));
	return p;
}

double f2(int n, double a[], double x) {
	int i;
	double p = a[n];
	for (i = n; i > 0; i--)
		p = a[i - 1] + x * p;
	return p;
}


int main() {
	double a[MAXN];
	for (int i = 0; i < MAXN; i++) a[i] = (double)i;

	start = clock();
	f1(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start) / CLK_TCK);
	cout << "f1's duration: " << duration << endl;

	start = clock();
	f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start) / CLK_TCK);
	cout << "f2's duration: " << duration << endl;
}
