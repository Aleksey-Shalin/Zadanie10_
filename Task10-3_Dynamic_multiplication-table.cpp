#include<iostream>

int** create_two_dim_array(int rows, int columns);
void fill_two_dim_array(int** array_elements, int rows, int columns);
void print_two_dim_array(int** array_elements, int rows, int columns);
void delete_two_dim_array(int** array_elements, int two_dim_array);

int main()
{
	setlocale(LC_ALL, "Russian");
	int rows = 0;
	int columns = 0;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;
	std::cout << "Введите количество столбцов: ";
	std::cin >> columns;
	int** multiplication_table = create_two_dim_array(rows, columns);
	fill_two_dim_array(multiplication_table, rows, columns);
	print_two_dim_array(multiplication_table, rows, columns);
	delete_two_dim_array(multiplication_table, rows);
	return 0;
}

int** create_two_dim_array(int rows, int columns)
{
	int** integer_numbers = new int* [rows] {};
	for (int row = 0; row < rows; row++)
	{
		integer_numbers[row] = new int[columns];
	}
	return integer_numbers;
}

void fill_two_dim_array(int** array_elements, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			array_elements[row][column] = (row + 1) * (column + 1);
		}
	}
}

void print_two_dim_array(int** array_elements, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			std::cout << array_elements[row][column] << "\t";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(int** array_elements, int two_dim_array)
{
	for (int this_array = 0; this_array < two_dim_array; this_array++)
	{
		delete[] array_elements[this_array];
	}
	delete[] array_elements;
}



