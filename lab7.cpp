#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

template <class Type>
class Matrix
{
private: 
	unsigned int rows;
	unsigned int columns;
	Type** element;

	Type** fill_matrix(string name_of_file, Type** &element);

public:	
	Matrix(unsigned int rows, unsigned int columns, Type** element)
	{
		this->rows = rows;
		this->columns = columns;
		this->element = element;
	}

	void printf(ostream& print)
	{
		print << endl << "Matrix: " << endl << endl; 

		for (unsigned int i = 0; i < rows; ++i)
		{
			for (unsigned int j = 0; j < columns; ++j)
			{
				print << element[i][j] << " ";
			}
			print << endl;
		}
	}

	friend ostream& operator <<(ostream& print,const Matrix<Type>& matrix); 

	Type** fill(Type** &element) 
	{ 
		fill_matrix("C:\\cpp\\baumanclasses\\labs-sem2\\lab7\\Matrix.txt", element); 
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

int main(void)
{
	unsigned int rows = 0;
	unsigned int columns = 0;

	cout << endl << "Print the size of the Matrix:" << endl;
	cout << "Rows: "; cin >> rows;
	cout << "Columns: "; cin >> columns; 

	double** element = new double*[rows];
	for (unsigned int i = 0; i < rows; ++i) element[i] = new double[columns];

	Matrix<double> matrix(rows, columns,element);
	matrix.fill(element);
	cout << matrix;

	for (unsigned int i = 0; i < rows; ++i) delete element[i]; 
		delete [] element;

	cout << endl << endl << "Press any button to exit the program " << endl;
	_getch();
	return 0;
}