﻿#include<stdio.h>
void menu()
{
	printf("\n1.Bai 9");
	printf("\n2.Bai 10");
	printf("\n3.Bai 11");
	printf("\n4.Bai 12");
	printf("\n5.Bai 13");
}
void calculate(int* pa, int* pb, int* sum, int* diff, int* product, float* quotient) {
    *sum = *pa + *pb;
    *diff = *pa - *pb;
    *product = *pa * *pb;
    *quotient = (float)*pa / *pb;
}
void to_uppercase(char* str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        }
        str++;
    }
}


void capitalize_words(char* str) {
    int capitalize = 1;
    while (*str) {
        if (isspace(*str)) {
            capitalize = 1;
        }
        else if (capitalize && islower(*str)) {
            *str = toupper(*str);
            capitalize = 0;
        }
        else {
            capitalize = 0;
        }
        str++;
    }
}
void printLocalMinima(int arr[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size; i++) {
        if ((i == 0 && arr[i] < arr[i + 1]) ||
            (i == size - 1 && arr[i] < arr[i - 1]) ||
            (i > 0 && i < size - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
            printf("So cuc tieu tai vi tri %d: %d\n", i, arr[i]);
        }
    }
}


void deleteAtIndex(int arr[], int* size, int k) {
    if (k < 0 || k >= *size) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}


void insertAtIndex(int arr[], int* size, int x, int k, int maxSize) {
    if (k < 0 || k > *size) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    if (*size >= maxSize) {
        printf("Mang da day, khong the them \n");
        return;
    }
    for (int i = *size; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*size)++;
}

void rearrangeEvenOdd(int arr[], int size) {
    int temp[10];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}


bool isAlternatingEvenOdd(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) ||
            (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}
typedef struct {
    int tu;
    int mau;
} PhanSo;


void nhapMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        printf("Tu so: ");
        scanf_s("%d", &arr[i].tu);
        do {
            printf("Mau so (khac 0): ");
            scanf_s("%d", &arr[i].mau);
            if (arr[i].mau == 0) {
                printf("Mau so phai khac 0. \n");
            }
        } while (arr[i].mau == 0);
    }
}


void xuatMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Phan so thu %d: %d/%d\n", i + 1, arr[i].tu, arr[i].mau);
    }
}
double giaTriThuc(PhanSo ps) {
    return (double)ps.tu / ps.mau;
}


PhanSo timPhanSoLonNhat(PhanSo arr[], int size) {
    PhanSo max = arr[0];
    for (int i = 1; i < size; i++) {
        if (giaTriThuc(arr[i]) > giaTriThuc(max)) {
            max = arr[i];
        }
    }
    return max;
}
void xoaPhanSoTaiViTri(PhanSo arr[], int* size, int k) {
    if (k < 0 || k >= *size) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void themPhanSoTaiViTri(PhanSo arr[], int* size, PhanSo x, int k, int maxSize) {
    if (k < 0 || k > *size) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    if (*size >= maxSize) {
        printf("Mang đa đay\n");
        return;
    }
    for (int i = *size; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*size)++;
}
void nhapMangNgauNhien(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}


void xuatMang(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void chiaMang(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (b[i] == 0) {
            printf("Phep chia %d/%d khong hop le .\n", a[i], b[i]);
        }
        else {
            double ketQua = (double)a[i] / b[i];
            printf("%d/%d = %.2f\n", a[i], b[i], ketQua);
        }
    }
}


int main()
{
	int lc;
	do {
		menu();
		printf("\nMoi ban chon ");
		scanf_s("%d", &lc);
        getchar();
		switch (lc)
		{
		case 1 :
		{
            int a, b;
            int sum, diff, product;
            float quotient;
            printf("Nhap vao so a: ");
            scanf_s("%d", &a);
            printf("Nhap vao so b: ");
            scanf_s("%d", &b);

            int* pa = &a;
            int* pb = &b;

            calculate(pa, pb, &sum, &diff, &product, &quotient);

            printf("Tong: %d, dia chi: %p\n", sum, (void*)&sum);
            printf("Hieu: %d,  dia chi: %p\n", diff, (void*)&diff);
            printf("Tich: %d,  dia chi: %p\n", product, (void*)&product);
            printf("Thuong: %.2f,  dia chi: %p\n", quotient, (void*)&quotient);

		}break;
        case 2:
        {
            char st[100];
            printf("Nhap vao chuoi: ");
            fgets(st, sizeof(st), stdin);
            st[strcspn(st, "\n")] = 0;
            char* p = st;
            printf("Cac ky tu cua chuoi:\n");
            while (*p) {
                printf("%c ", *p);
                p++;
            }
            printf("\n");
            capitalize_words(st);
            printf("Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: %s\n", st);
            to_uppercase(st);
            printf("Chuoi sau khi chuyen thanh chu hoa: %s\n", st);
        }break;
        case 3:
        {
            int arr[100];
            int size;
            int choice, k, x;
            printf("Nhap kich thuoc cua mang: ");
            scanf_s("%d", &size);

            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            printLocalMinima(arr, size);
            printf("Nhap vi tri k de xoa: ");
            scanf_s("%d", &k);
            deleteAtIndex(arr, &size, k);
            printf("Nhập phan tu x de them: ");
            scanf_s("%d", &x);
            printf("Nhap vi tri k de them: ");
            scanf_s("%d", &k);
            insertAtIndex(arr, &size, x, k, 100);
            rearrangeEvenOdd(arr, size);
            printf("Mang sau khi chuyen chan len đau, le xuong cuoi:\n");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            if (isAlternatingEvenOdd(arr, size)) {
                printf("Mang chua cac so chan le xen ke.\n");
            }
            else {
                printf("Mang khong chua cac so chan le xen ke.\n");
            }
        }break;
        case 4:
        {
            PhanSo arr[100];
            int size;
            int choice, k;
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            nhapMangPhanSo(arr, size);
            xuatMangPhanSo(arr, size);
            PhanSo max = timPhanSoLonNhat(arr, size);
            printf("Phan so lon nhat la %d/%d\n", max.tu, max.mau);
            printf("Nhap vi tri k de xoa: ");
            scanf_s("%d", &k);
            xoaPhanSoTaiViTri(arr, &size, k);
            printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
            xuatMangPhanSo(arr, size);
        }break;
        case 5:
        {
            int size;
            srand(time(NULL));
            printf("Nhap kich thuoc mang a và b: ");
            scanf_s("%d", &size);
            int* a = (int*)malloc(size * sizeof(int));
            int* b = (int*)malloc(size * sizeof(int));
            printf("Nhap cac phan tu cua mang a:\n");
            nhapMangNgauNhien(a, size);
            printf("Nhap cac phan tu cua mang b:\n");
            nhapMangNgauNhien(b, size);
            printf("Mang a: ");
            xuatMang(a, size);
            printf("Mang b: ");
            xuatMang(b, size);
            printf("Ket qua phep chia :\n");
            chiaMang(a, b, size);
        }break;
		}
	} while (lc < 6);
	return 0;
}
