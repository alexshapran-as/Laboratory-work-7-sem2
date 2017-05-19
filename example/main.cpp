#include "Laboratory-work-7-sem2.hpp"
int main() 
{
	unsigned int rows = 0;
	unsigned int columns = 0;

	cout << endl << "Print the dimensions of Matrices:" << endl;
	cout << "Rows: "; cin >> rows;
	cout << "Columns: "; cin >> columns; 
	cout << endl << "***The first way to work with matrices through text files***" << endl;

	double** element = new double*[rows];
	for (unsigned int i = 0; i < rows; ++i) element[i] = new double[columns];
	
	cout << endl << "Basic Matrix:";
	Matrix<double> matrix(rows, columns,element);
	matrix.fill(element);
	cout << matrix;
	Matrix<double> matrix1(matrix);

	cout << endl << "Matrix for summation: ";
	matrix.fill(element);
	cout << matrix;
	Matrix<double> matrix2(matrix);

	cout << endl << "The result of summation: " << endl;
	cout << matrix1 + matrix2;

	cout << endl << "Matrix for multiplication: ";
	matrix.fill(element);
	cout << matrix;
	Matrix<double> matrix3(matrix);

	cout << endl << "The result of multiplication: " << endl;
	cout << matrix1 * matrix3;

	cout << endl << "***The second way to work with matrices through streaming [>>]***" << endl;
	cout << endl << "Basic Matrix:" << endl;
	Matrix<double> matrix4(rows, columns,element);
	cin >> matrix4;
	cout << matrix4;
	Matrix<double> matrix4_copy(matrix4);

	cout << endl << "Matrix for summation: " << endl;
	Matrix<double> matrix5(rows, columns,element);
	cin >> matrix5;
	cout << matrix5;

	cout << endl << "The result of summation: " << endl;
	cout << matrix4_copy + matrix5;

	Matrix<double> matrix6_copy(matrix4_copy);

	cout << endl << "Matrix for multiplication: " << endl;
	Matrix<double> matrix7(rows, columns,element);
	cin >> matrix7;
	cout << matrix7;

	cout << endl << "The result of multiplication: " << endl;
	cout << matrix6_copy * matrix7;

	cout << endl << "***Comparison of two matrices***" << endl;
	cout << endl << "The first Matrix for comparison:" << endl;
	cout << matrix6_copy;

	cout << endl << "The second Matrix for comparison:" << endl;
	cout << matrix7;

	if ( matrix6_copy == matrix7 ) cout << endl << "[+] These matrices are equal!:)" << endl;
	else cout << endl << "[-] These matrices are not equal!:(" << endl;

	return 0;
}