#ifndef __MATRIX_H_
#define __MATRIX_H_
#include <iostream>
#include <exception>

using namespace std;
/*class ex_out_of_range: public exception {
	virtual const char* what() const throw() {
		return "indeks wykracza poza zakres tablicy";
	}
} out_of_range;*/

class rcMatrix {
	private:
		int rows;
		int cols;
		double* mem;
		double read(int y,int x);
		void write(double var,int y,int x);
		bool check(int y,int x);
		struct Matrix;
		Matrix mat;
	public:
		rcMatrix();
		rcMatrix(int,int);
		rcMatrix(rcMatrix&);
		rcMatrix(const char*);
		~rcMatrix();
		rcMatrix operator+ (const rcMatrix& m) const;
		rcMatrix operator- (const rcMatrix& m) const;
		rcMatrix operator* (const rcMatrix& m) const;
		rcMatrix& operator+= (rcMatrix& m);
		rcMatrix& operator-= (rcMatrix& m);
		rcMatrix& operator*= (rcMatrix& m);
		rcMatrix operator= (const rcMatrix& m) const;
		double operator()(int y,int x);
		friend ostream& operator<< (ostream& out,rcMatrix& m) {
			out << "Macierz " << m.getRows() << "x" << m.getCols() << endl;
			out << "----------" << endl;
			for(int i=0;i<m.getRows();i++) {
				for(int j=0;j<m.getCols();j++) {
					cout << m(i,j) << "\t";
				}
				cout << endl;
			}
			out << endl << endl;
			return out;
		}
		bool loadMatrix(const char*);
		inline int getRows() { return rows; }
		inline int getCols() { return cols; }
		inline double getElem(int i,int j) { return mem[i*cols+j]; } 
};

struct rcMatrix::Matrix {
	int a;
};

#endif // __MATRIX_H_

