#include <iostream>
#include <vector>
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Размер первого подмассива
    int n2 = right - mid;    // Размер второго подмассива

    // Временные массивы для хранения данных
    std::vector<int> L(n1), R(n2);

    // Копируем данные во временные массивы L[] и R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Инициализируем индексы для подмассивов и основного массива
    int i = 0, j = 0, k = left;

    // Сливаем подмассивы обратно в arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}


// Функция для разделения массива и вызова слияния
//                                          0         5
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Находим середину
        // Рекурсивно сортируем обе половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

int main(){
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 3};
    int arr_size = arr.size();

    std::cout << "Исходный массив: \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Отсортированный массив: \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}