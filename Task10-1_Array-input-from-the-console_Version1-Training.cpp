#include<iostream>

int* create_array(int size);     // прототип функции для создания массива
void array_elements_input(int* array_address, int size);    // прототип функции для ввода элементов массива
void array_output(int* array_address, int size);     // прототип функции для вывода полученного массива
void delete_array(int* array_address);     // очистка динамической памяти массива

// основная функция программы
int main()
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int* external_array = create_array(size);
    array_elements_input(external_array, size);
    array_output(external_array, size);
    delete_array(external_array);
    return 0;
}

int* create_array(int size)    // реализация функции создания массива
{
    return new int[size] {};
}

void array_elements_input(int* array_address, int size)    // реализация функции для ввода элементов массива
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "arr[ " << i << " ] = ";
        std::cin >> array_address[i];
    }
}

void array_output(int* array_address, int size)    // реализация функции для вывода полученного массива
{
    std::cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array_address[i] << " ";
    }
}

void delete_array(int* array_address)      // реализация функции для очистки динамической памяти массива
{
    delete[] array_address;
}