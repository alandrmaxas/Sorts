#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void merge(int* arr, int first, int last) {
    int left_it, right_it, middle;
    int* mas; // указатель на инт
    mas = (int*)malloc((last - first + 1) * sizeof(int)); // иницилизируем указатель на инт
    // по сути мы просто выделяем память под элементы, которые мы будем хранить здесь, предварительно отсортировав
    middle = (first + last) / 2; // узнаем средний элемент
    left_it = first; // бахаем начальный индекс для левой половины исходного массива
    right_it = middle + 1; // бахаем начальный индекс для правой половины исходного массива

    for (int j = first; j <= last; j++) { // проходим сквозь весь массив
        if ((left_it <= middle) && ((right_it > last) || (arr[left_it] < arr[right_it]))) { // left_it <= middle - условие необходимое для левой половины, чтобы не выйти за её границы
            *(mas + j - first) = arr[left_it]; // если все условия в ифе выполняются        // right_it > last - условие необходимое для правой половины, чтобы не выйти за её границы
            left_it++; // *(mas + j - first) равносильно mas(j - first)                     // если же мы не выходим за границы ни одной из половин, то чекаем по индексам элементы из обоих половин
        }              // то есть выделяем память под элемент с индексом mas(j - first)     // и сравниваем какое меньше
        else {
            *(mas + j - first) = arr[right_it]; // если же у нас ддостигнут конец одной из половин или же элемент из правой половины меньше элемента из левой, то сохраняем элемент из правой
            right_it++;
        }
    }

    for (int j = first; j <= last; j++) {
        arr[j] = *(mas + j - first); // ну и тут самое классно, в исходный массив мы закидываем ранее сохраненные, отсортированные числа
    }
    free(mas); // освобождаем выделенную ранее память
}

void merge_sort(int* arr, int first, int last) {
    if (first < last) { // проверяем, что размер больше нуля
        merge_sort(arr, first, (first + last) / 2); // first, (first + last) / 2 - это начало и конец левой половины нашего массива
        merge_sort(arr, (first + last) / 2 + 1, last); // (first + last) / 2, last - это начало и конец правой половины нашего массива
        //если нас все устраивает, и выполняется условие, то есть у нас обычный массив, то начинаем сортировать его
        merge(arr, first, last);
    }
}

void printf_arr(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[MAX];
    int size = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < MAX; i++) {
        a[i] = rand();
    }

    printf("Array: ");
    printf_arr(a, size);
    printf("\n");

    printf("Sorted array: ");
    merge_sort(a, 0, size - 1); // передаем: массив, индекс 1-го элемента, индекс последнего элемента
    printf_arr(a, size);

    return 0;

}
