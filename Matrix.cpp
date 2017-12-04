#include "Matrix.h"
#include <fstream>

using namespace std;


rcMatrix::rcMatrix() {
	rows = 0;
	cols = 0;
	mem = NULL;
}

rcMatrix::rcMatrix(int m_rows,int m_cols) {
	rows = m_rows;
	cols = m_cols;
	mem = new double[rows*cols];
	for(int i=0;i<rows*cols;i++) mem[i] = 0;
}

rcMatrix::rcMatrix(rcMatrix& m_m) {
	
}

rcMatrix::rcMatrix(const char* path) {
	ifstream in(path);
	int r,c;
	if(!in.good()) {
		// TODO: file error exception?
		rows = 0;
		cols = 0;
		mem = NULL;
	}
	in >> r >> c;
	rows = r;
	cols = c;
	mem = new double[rows*cols];
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			in >> mem[i*cols+j];
		}
	}
	in.close();
}

rcMatrix::~rcMatrix() {
	delete[] mem;
}

rcMatrix& rcMatrix::operator-= (rcMatrix& m) {
	if((rows == m.rows) && (cols == m.cols)) {
			for(int i=0;i<rows;i++) {
					for(int j=0;j<cols;j++) {
						this->mem[i*cols+j] -= m.mem[i*cols+j];
					}
			}
	} else {
			//TODO: throw operation failed exception
	}	
	return *this;
}

rcMatrix rcMatrix::operator- (const rcMatrix& m) const {
 		rcMatrix new_matrix(rows,cols);
		if((rows == m.rows) && (cols == m.cols)) {
				for(int i=0;i<rows;i++) {
						for(int j=0;j<cols;j++) {
							this->mem[i*cols+j] -= m.mem[i*cols+j];
						}
				}
		} else {
				//TODO: throw operation failed exception
		}
		return new_matrix;
}

rcMatrix& rcMatrix::operator+= (rcMatrix& m) {
	if((rows == m.rows) && (cols == m.cols)) {
			for(int i=0;i<rows;i++) {
					for(int j=0;j<cols;j++) {
						this->mem[i*cols+j] += m.mem[i*cols+j];
					}
			}
	} else {
			//TODO: throw operation failed exception
	}	
	return *this;
}

rcMatrix rcMatrix::operator+ (const rcMatrix& m) const {
 		rcMatrix new_matrix(rows,cols);
		if((rows == m.rows) && (cols == m.cols)) {
				for(int i=0;i<rows;i++) {
						for(int j=0;j<cols;j++) {
							this->mem[i*cols+j] += m.mem[i*cols+j];
						}
				}
		} else {
				//TODO: throw operation failed exception
		}
		return new_matrix;
}

rcMatrix rcMatrix::operator* (const rcMatrix& m) const {
	rcMatrix new_matrix(this->rows,m.cols);
	double s;
	for(int i=0;i<this->rows;i++) {
		for(int j=0;j<m.cols;j++) {
			s = 0;	
			for(int k=0;k<this->cols;k++) s += this->mem[i*cols+k] + m.mem[k*m.cols+j];
			new_matrix.mem[i*cols+j] = s;
		}
	}
	return new_matrix;
}

rcMatrix& rcMatrix::operator*= (rcMatrix& m) {
	return *this;
}

double rcMatrix::operator() (int y,int x) {
	check(y,x);
	return mem[y*cols+x];
}

rcMatrix rcMatrix::operator= (const rcMatrix& m) const {
	rcMatrix new_matrix(m.rows,m.cols);
	for(int i=0;i<m.rows;i++) {
			for(int j=0;j<m.cols;j++) {
				new_matrix.mem[i*cols+j] = m.mem[i*cols+j];
			}
	}
	return new_matrix;
}

bool rcMatrix::loadMatrix(const char* path) {
	ifstream in(path);
	int r,c;
	if(!in.good()) {
		// TODO: file error exception
		return false;
	}
	in >> r >> c;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			in >> mem[i*cols+j];
		}
	}
	in.close();
	return true;
}

double rcMatrix::read(int y,int x) {
	try {
		
	} catch(exception& e) {
			cout << "rcMatrix::read(): nie mozna odczytac wartosci macierzy - " << e.what() << endl;
	}
}

bool rcMatrix::check(int y,int x) {
	//if(y < 0 || y > (rows-1) || x < 0 || x > (cols-1)) throw out_of_range();
	return true;
}
