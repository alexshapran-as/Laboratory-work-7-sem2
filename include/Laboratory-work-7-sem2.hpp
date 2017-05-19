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
	
	Matrix<Type>& operator +(Matrix<Type>& matrix)
	{
		try 
		{
			if (matrix.rows != rows || matrix.columns != columns) throw 2;
		}
		catch(int test)
		{
			cout << endl << "[-] Exception " << test << ": The operation of adding matrices is defined only for matrices of the same order!" << endl;
			exit(1);
		}

		for (unsigned int i = 0; i < matrix.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix.columns; ++j)
			{
				matrix.element[i][j] = matrix.element[i][j] + element[i][j];
			}
		}
		return matrix;
	}

	Matrix<Type>& operator *(Matrix<Type>& matrix)
	{
		try 
		{
			if (matrix.rows != rows || matrix.columns != columns) throw 3;
		}
		catch(int test)
		{
			cout << endl << "[-] Exception " << test << ": The operation of multiplication matrices is defined only for matrices of the same order!" << endl;
			exit(1);
		}

		Matrix<Type> matrix_temp(matrix);

		for (unsigned int i = 0; i < matrix.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix.columns; ++j)
			{
				for (unsigned int k = 0; k < matrix.columns; ++k)
				{
					matrix_temp.element[i][j] += matrix.element[k][j]*element[i][k];
				}
				
			}
		}

		for (unsigned int i = 0; i < matrix.rows; ++i)
		{
			for (unsigned int j = 0; j < matrix.columns; ++j)
			{
				matrix_temp.element[i][j] = matrix_temp.element[i][j] - matrix.element[i][j];
			}	
		}

		matrix = matrix_temp;
		
		return matrix;
	}

	Matrix<Type>& operator =(Matrix<Type>& matrix)
	{
		if (this == &matrix) { return *this; }
		
		for (unsigned int i = 0; i < rows; ++i) { delete element[i]; }
		delete [] element;
		
		element = new Type*[matrix.rows];
		for (unsigned int i = 0; i < matrix.rows; ++i) 
		{
			element[i] = new Type[matrix.columns];
			for (unsigned int j = 0; j < matrix.columns; ++j)
			{
				element[i][j] = matrix.element[i][j];
			}
		}
		rows = matrix.rows;
		columns = matrix.rows;

		return *this;
	}

	bool operator ==(const Matrix<Type>& matrix) const
	{
		if ((rows == matrix.rows) && (columns == matrix.columns)) 
		{
			for (unsigned int i = 0; i < rows; ++i)
			{
				for (unsigned int j = 0; j < columns; ++j) 
				{
					if (element[i][j] != matrix.element[i][j]) return false; 
				}
			}
				
		}
		else return false;
	}


	Type** fill(Type** &element) 
	{ 
		string name_of_file;
		cout << endl << "Print the name of file" << endl; cin >> name_of_file;
		fill_matrix(name_of_file, element); 
	}

	~Matrix()
	{
		for (unsigned int i = 0; i < rows; ++i) delete element[i]; 
		delete [] element;
	}
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
