#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
void menu()
{
    printf("\n1.Nhap mang");
    printf("\n2.Tong phan tu so dau la le");
    printf("\n3.Dem so lan xuat hien");
    printf("\n4.Sap xep chan tang le giam");
    printf("\n5.Tim day con dai nhat");
    printf("\n6.So nho thu hai trong mang");
    printf("\n7.Tim x ");

}
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 28;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void listPrimes(int n) {
    bool found = false;
    printf("So nguyen to nho hon %d: ", n);
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nho hon %d.", n);
    }
    printf("\n");
}
int sumOddFirstDigit(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int firstDigit = arr[i];
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}
void countOccurrences(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            count++;
    }
    printf("%d xuat hien %d lan", x, count);

}
int compare(const void* a, const void* b)
{
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a % 2 == 0 && int_b % 2 == 0) {
        return int_a - int_b;
    }
    if (int_a % 2 != 0 && int_b % 2 != 0) {
        return int_b - int_a;
    }
    if (int_a % 2 == 0) return -1;
    return 1;
}
void longestDecreasingSubsequence(int arr[], int n) {
    int* lds = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) lds[i] == 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    int max = 0;
    for (int i = 0; i < n; i++)
        if (lds[i] > max)
            max = lds[i];

    printf("Do dai day con dai nhat: %d\n", max);
    free(lds);
}
int secondSmallest(int arr[], int n) {
    if (n < 2) return -1;

    int first = arr[0], second = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MAX) return -1;
    return second;
}
bool containsDigits(int num, int x) {
    char numStr[12], xStr[3];
    printf(numStr, "%d", num);
    printf(xStr, "%d", x);
    return strstr(numStr, xStr) != NULL || (strchr(numStr, xStr[0]) && strchr(numStr, xStr[1]));
}
void findElementsContainingDigits(int arr[], int n, int x) {
    printf("Tim thay  %d: ", x);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (containsDigits(arr[i], x)) {
            printf("%d ", arr[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay.");
    }
    printf("\n");
}

int main()
{
    int lc;
    int  arr[50];
    int n = 10;
    generateRandomArray(arr, n);
    do
    {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        printArray(arr, n);
        switch (lc)
        {
        case 1:
        {
            int a;
            printf("\nNhap so bat ki ");
            scanf_s("%d", &a);
            listPrimes(a);
        }break;
        case 2:
        {
            int sum = sumOddFirstDigit(arr, n);
            printf("Tong phan tu so dau la chan : %d\n", sum);
        }break;
        case 3:
        {
            int a;
            printf("\nNhap so bat ki ");
            scanf_s("%d", &a);
            countOccurrences(arr, n, a);
        }break;
        case 4:
        {
            qsort(arr, n, sizeof(int), compare);
            printf("Mang co so chan tang dan so le giam dan: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }break;
        case 5:
        {
            longestDecreasingSubsequence(arr, n);
        }break;
        case 6:
        {
            int secondSmall = secondSmallest(arr, n);
            if (secondSmall == -1) {
                printf("Khong co so nho thu hai trong mang.\n");
            }
            else {
                printf("So nho thu hai trong mang: %d\n", secondSmall);
            }

        }break;
        case 7:
        {

            int a;
            printf("\nNhap so bat ki ");
            scanf_s("%d", &a);

            findElementsContainingDigits(arr, n, a);
        }break;
        }

    } while (lc);
    return 0;

}