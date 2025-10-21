#include<iostream>

double* create_array(int size);     
int array_size_input();
void array_output(double* array_elements, int size);    
void delete_array(double* array_elements);  

int main()
{
	setlocale(LC_ALL, "Russian");
	int size_of_array = array_size_input();
	double* zeros_array = create_array(size_of_array);
	array_output(zeros_array, size_of_array);
	delete_array(zeros_array);
	zeros_array = nullptr;
	return 0;
}

int array_size_input()
{
	int array_size = 0;
	while (array_size <= 0 || (std::cin.fail()))
	{
		std::cout << "Введите размер массива: ";
		std::cin >> array_size;
		if (array_size <= 0 || (std::cin.fail()))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Нужно ввести целое положительное число для размерности массива" << std::endl;
			std::cout << std::endl;
		}
	}
	return array_size;
}

double* create_array(int size)
{
	double* array_of_zeros = new double[size];
	for (int element = 0; element < size; element++)
	{
		array_of_zeros[element] = 0;
	}
	return array_of_zeros;
}

void array_output(double* array_elements, int size)
{
	std::cout << "Массив: ";
	for (int element = 0; element < size; element++)
	{
		std::cout << array_elements[element] << " ";
	}
}

void delete_array(double* array_elements)
{
	delete[] array_elements;
}