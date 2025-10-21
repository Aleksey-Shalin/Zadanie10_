#include<iostream>
#include<cctype>

int array_size_input();    // прототип функции для ввода размера массива
int* create_array(int size);    // прототип функции для создания динамического массива
void array_elements_input(int* array_elements, int size);    // прототип функции для ввода элементов массива
void array_output(int* array_elements, int size);     // прототип функции для вывода полученного массива
void delete_array(int* array_elements);      // прототип функции для очистки динамической памяти массива

// основная функция программы
int main()
{
	setlocale(LC_ALL, "Russian");
	int size_of_array = array_size_input();
	int* one_dim_array = create_array(size_of_array);
	array_elements_input(one_dim_array, size_of_array);
	array_output(one_dim_array, size_of_array);
	delete_array(one_dim_array);
	return 0;
}

// реализация функции для ввода размера массива
int array_size_input()
{
	int array_size = 0;
	//const int letter = 1;
	//char not_number[letter];
	while (array_size <= 0 || (std::cin.fail()))
	{
		std::cout << "Введите размер массива: ";
		std::cin >> array_size;
		if (array_size <= 0 || (std::cin.fail()))    // проверка на ввод отрицательного числа (array_size<=0) или нецифрового символа (std::cin.fail())
		{
			std::cin.clear();    // снятие флага ошибки функцией clear() и удаление содержимого строки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Нужно ввести целое положительное число для размерности массива" << std::endl;
			//std::cin.getline(not_number, letter, '\n');
			std::cout << std::endl;
		}
	}
	return array_size;
}

// реализация функции создания динамического массива
int* create_array(int size)
{
	return new int[size] {};
}

// реализация функции для ввода элементов массива
void array_elements_input(int* array_elements, int size)
{
	for (int i = 0; i < size; i++)
	{
		int num = 0;
		do
		{
			std::cout << "arr[ " << i << " ] = ";
			std::cin >> array_elements[i];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Нужно ввести число" << std::endl;
			}
		} while (std::cin.fail());
	}
}

// реализация функции для вывода полученного массива
void array_output(int* array_elements, int size)
{
	std::cout << "Введённый массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << array_elements[i] << " ";
	}
}

// реализация функции для очистки динамической памяти массива
void delete_array(int* array_elements)
{
	delete[] array_elements;
}