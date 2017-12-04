#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
	rcMatrix m1("matrix.txt");
	rcMatrix m2("matrix2.txt");
	rcMatrix m3;
	cout << m1 << endl << m2 << endl;
	m1 += m2;
	//cout << (m1+m2);
	cout << m1;
	m3 = m1 * m2;
	cout << m3;
	return 0;
}
