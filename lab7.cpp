#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

template <class Type>
class Matrix
{
private: 
	unsigned int rows;
	unsigned int columns;
	//Matrix<Type> matrix1;

	Type** fill_matrix(string name_of_file, Type** &element);

public:	
	Type** element;

	Matrix() { rows = 0; columns = 0; element = 0; }

	Matrix(const Matrix &matrix) 
	{  
		rows = matrix.rows;
		columns = matrix.columns;
		element = new Type*[rows];
		for (unsigned int i = 0; i < rows; ++i) element[i] = new Type[columns];
		for (unsigned int i = 0; i < rows; ++i)
		{
			for (unsigned int j = 0; j < columns; ++j)
			{
				element[i][j] = matrix.element[i][j];
			}
		}
	}

	Matrix(unsigned int rows, unsigned int columns, Type** element)
	{
		this->rows = rows;
		this->columns = columns;
		this->element = new double*[this->rows];
		for (unsigned int i = 0; i < this->rows; ++i) this->element[i] = new double[this->columns];
		this->element = element;
	}

	void printf(ostream& print)
	{
		for (unsigned int i = 0; i < rows; ++i)
		{
			for (unsigned int j = 0; j < columns; ++j)
			{
				print << element[i][j] << " ";
			}
			print << endl;
		}
	}

	void writef(istream& write)
	{
		for (unsigned int i = 0; i < rows; ++i)
		{
			for (unsigned int j = 0; j < columns; ++j)
			{
				write >> element[i][j];
			}
		}
	}

	friend ostream& operator <<(ostream& print,const Matrix<Type>& matrix);
	friend istream& operator >>(istream& write,const Matrix<Type>& matrix);
	
	Matrix<Type>& operator +(Matrix<Type>& matrix1)
	{
		try 
		{
			if (matrix1.rows != rows || matrix1.columns != columns) throw 2;
		}
		catch(int test)
		{
			cout << endl << "[-] Exception " << test << ": The operation of adding matrices is defined only for matrices of the same order!" << endl;
			exit(1);
		}

		for (unsigned int i = 0; i < matrix1.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix1.columns; ++j)
			{
				matrix1.element[i][j] = matrix1.element[i][j] + element[i][j];
			}
		}
		return matrix1;
	}

	Matrix<Type>& operator *(Matrix<Type>& matrix1)
	{
		try 
		{
			if (matrix1.rows != rows || matrix1.columns != columns) throw 2;
		}
		catch(int test)
		{
			cout << endl << "[-] Exception " << test << ": The operation of adding matrices is defined only for matrices of the same order!" << endl;
			exit(1);
		}

		Matrix<Type> matrix_temp(matrix1);

		for (unsigned int i = 0; i < matrix1.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix1.columns; ++j)
			{
				for (unsigned int k = 0; k < matrix1.columns; ++k)
				{
					matrix_temp.element[i][j] += matrix1.element[k][j]*element[i][k];
				}
				
			}
		}

		for (unsigned int i = 0; i < matrix1.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix1.columns; ++j)
			{
				matrix_temp.element[i][j] = matrix_temp.element[i][j] - matrix1.element[i][j];
			}	
		}

		matrix1 = matrix_temp;
		
		return matrix1;
	}

	Type** fill(Type** &element) 
	{ 
		string name_of_file;
		cout << endl << "Print the name of file" << endl; cin >> name_of_file;
		fill_matrix(name_of_file, element); 
	}

	/*~Matrix()
	{
		for (unsigned int i = 0; i < rows; ++i) delete element[i]; 
		delete [] element;
	}*/
};

template <class Type>
Type** Matrix<Type>::fill_matrix(string name_of_file, Type** &element)
{
	ifstream fin(name_of_file, ios::in);

	try
	{
		if (!fin.is_open()) throw 1;
	}
	catch(int test)
	{
		cout << endl << "[-] Exception " << test << ": The file wasn't found!" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int j = 0; j < columns; ++j)
		{
			fin >> element[i][j];
		}
	}

		fin.close();	
} 

template <class Type>
ostream& operator <<(ostream& print, Matrix<Type>& matrix)
	{	
		matrix.printf(print);
		return print;
	}

template <class Type>
istream& operator >>(istream& write, Matrix<Type>& matrix)
	{	
		matrix.writef(write);
		return write;
	}

int main(void)
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


	for (unsigned int i = 0; i < rows; ++i) delete element[i]; 
		delete [] element;

	cout << endl << endl << "Press any button to exit the program " << endl;
	_getch();
	return 0;
}