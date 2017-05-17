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

	void fill_matrix(string name_of_file, Type** &element);

public:	
	Matrix(unsigned int rows, unsigned int columns)
	{
		this->rows = rows;
		this->columns = columns;
		Type** element = new Type*[rows];
		for (unsigned int i = 0; i < rows; ++i) element[i] = new Type[columns];

	}
	
	unsigned int get_rows() { return rows; }
	unsigned int get_columns() { return columns; }
	Type get_element(unsigned int row, unsigned int column) { return element[row][column]; }

	void printf(ostream& print)
	{
		print << "Matrix: " << endl; 

		for (unsigned int i = 0; i < get_rows(); ++i)
		{
			for (unsigned int j = 0; j < get_columns(); ++j)
			{
				print << get_element(i,j) << " ";
			}
			print << endl;
		}
	}

	friend ostream& operator <<(ostream& print,const Matrix<Type>& matrix); 

	void fill(Type** &element) 
	{ 
		fill_matrix("C:\\cpp\\baumanclasses\\labs-sem2\\lab7\\Matrix.txt", element); 
	}

	~Matrix()
	{
		for (unsigned int i = 0; i < rows; ++i) delete element[i]; 
		delete [] element;
	}
};

template <class Type>
void Matrix<Type>::fill_matrix(string name_of_file, Type** &element)
{
	ifstream fin(name_of_file);

	if (!fin.is_open()) cout << "Error!" << endl;
    else
    {	
		for (unsigned int i = 0; i < get_rows(); ++i)
		{
			for (unsigned int j = 0; j < get_columns(); ++j)
			{
				fin >> element[i][j];
			}
		}

		fin.close();
    }	
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
	cout << endl << "Columns: "; cin >> columns; 

	double** element = new double*[rows];
	for (unsigned int i = 0; i < rows; ++i) element[i] = new double[columns];

	Matrix<double> matrix(rows, columns);
	matrix.fill(element);
	cout << matrix;

	cout << endl << endl << "Press any button to exit the program " << endl;
	_getch();
	return 0;
}