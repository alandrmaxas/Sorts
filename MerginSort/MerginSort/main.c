#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void merge(int* arr, int first, int last) {
    int left_it, right_it, middle;
    int* mas; // ��������� �� ���
    mas = (int*)malloc((last - first + 1) * sizeof(int)); // ������������� ��������� �� ���
    // �� ���� �� ������ �������� ������ ��� ��������, ������� �� ����� ������� �����, �������������� ������������
    middle = (first + last) / 2; // ������ ������� �������
    left_it = first; // ������ ��������� ������ ��� ����� �������� ��������� �������
    right_it = middle + 1; // ������ ��������� ������ ��� ������ �������� ��������� �������

    for (int j = first; j <= last; j++) { // �������� ������ ���� ������
        if ((left_it <= middle) && ((right_it > last) || (arr[left_it] < arr[right_it]))) { // left_it <= middle - ������� ����������� ��� ����� ��������, ����� �� ����� �� � �������
            *(mas + j - first) = arr[left_it]; // ���� ��� ������� � ��� �����������        // right_it > last - ������� ����������� ��� ������ ��������, ����� �� ����� �� � �������
            left_it++; // *(mas + j - first) ����������� mas(j - first)                     // ���� �� �� �� ������� �� ������� �� ����� �� �������, �� ������ �� �������� �������� �� ����� �������
        }              // �� ���� �������� ������ ��� ������� � �������� mas(j - first)     // � ���������� ����� ������
        else {
            *(mas + j - first) = arr[right_it]; // ���� �� � ��� ���������� ����� ����� �� ������� ��� �� ������� �� ������ �������� ������ �������� �� �����, �� ��������� ������� �� ������
            right_it++;
        }
    }

    for (int j = first; j <= last; j++) {
        arr[j] = *(mas + j - first); // �� � ��� ����� �������, � �������� ������ �� ���������� ����� �����������, ��������������� �����
    }
    free(mas); // ����������� ���������� ����� ������
}

void merge_sort(int* arr, int first, int last) {
    if (first < last) { // ���������, ��� ������ ������ ����
        merge_sort(arr, first, (first + last) / 2); // first, (first + last) / 2 - ��� ������ � ����� ����� �������� ������ �������
        merge_sort(arr, (first + last) / 2 + 1, last); // (first + last) / 2, last - ��� ������ � ����� ������ �������� ������ �������
        //���� ��� ��� ����������, � ����������� �������, �� ���� � ��� �������, ������������ ������, �� �������� ����������� ���
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
    merge_sort(a, 0, size - 1); // ��������: ������, ������ 1-�� ��������, ������ ���������� ��������
    printf_arr(a, size);

    return 0;

}