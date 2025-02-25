﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void menu()
{
    printf("\n1.Bai 4.1");
    printf("\n2.Bai 4.2");
    printf("\n3.Bai 4.3");
    printf("\n4.Bai 4.4");
    printf("\n5.Bai 4.5");
    printf("\n6.Bai 4.6");
}

void taoMaTran(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = + rand() % 100;
        }
    }
}


void xuatMaTran(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void sapXepDuongCheoPhu(int** a, int m, int n, int tangDan) {
    int len = m < n ? m : n;
    int diagonal[5];
    int index = 0;

    
    for (int i = 0; i < len; i++) {
        diagonal[index++] = a[i][n - 1 - i];
    }

    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((tangDan && diagonal[i] > diagonal[j]) || (!tangDan && diagonal[i] < diagonal[j])) {
                int temp = diagonal[i];
                diagonal[i] = diagonal[j];
                diagonal[j] = temp;
            }
        }
    }

    
    index = 0;
    for (int i = 0; i < len; i++) {
        a[i][n - 1 - i] = diagonal[index++];
    }
}
void sapXepDong(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}
void sapXepCot(int** a, int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}
void sapXepDuongCheo(int** a, int m, int n) {
    for (int k = -(m - 1); k < n; k++) {
        int len = 0;
        int diagonal[5];
        for (int i = 0; i < m; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                diagonal[len++] = a[i][j];
            }
        }

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (diagonal[i] > diagonal[j]) {
                    int temp = diagonal[i];
                    diagonal[i] = diagonal[j];
                    diagonal[j] = temp;
                }
            }
        }


        len = 0;
        for (int i = 0; i < m; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                a[i][j] = diagonal[len++];
            }
        }
    }
}
void diChuyenChanLenTren(int** a, int m, int n) {
    int* even = (int*)malloc(m * n * sizeof(int));
    int* odd = (int*)malloc(m * n * sizeof(int));
    int eIndex = 0, oIndex = 0;

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                even[eIndex++] = a[i][j];
            }
            else {
                odd[oIndex++] = a[i][j];
            }
        }
    }

   
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (index < eIndex) {
                a[i][j] = even[index++];
            }
            else {
                a[i][j] = odd[index++ - eIndex];
            }
        }
    }

    free(even);
    free(odd);
}
int kiemTraDoiXung(int** a, int m, int n) {
    if (m != n) return 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) return 0;
        }
    }
    return 1;
}

int main()
{
    int lc;
    int m, n;
    srand(time(NULL));
  
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        switch (lc)
        {
        case 1 :
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            printf("Chon 1 de sap xep duong cheo phu tang dan hoac 0 de giam dan: ");
            int tangDan;
            scanf_s("%d", &tangDan);
            sapXepDuongCheoPhu(a, m, n, tangDan);
            xuatMaTran(a, m, n);
        }break;
        case 2:
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            printf(" ma tran ");
            printf("\n");
            sapXepDong(a, m, n);
            xuatMaTran(a, m, n);
        }break;
        case 3:
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            printf(" ma tran ");
            printf("\n");
            sapXepCot(a, m, n);
            xuatMaTran(a, m, n);
        }break;
        case 4:
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            printf(" ma tran ");
            printf("\n");
            sapXepDuongCheo(a, m, n);
            xuatMaTran(a, m, n);
        }break;
        case 5 :
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            printf(" ma tran ");
            printf("\n");
            diChuyenChanLenTren(a, m, n);
            xuatMaTran(a, m, n);
        }break;
        case 6:
        {
            printf("Nhap so dong va so cot cua ma tran: ");
            scanf_s("%d %d", &m, &n);
            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++) {
                a[i] = (int*)malloc(n * sizeof(int));
            }
            taoMaTran(a, m, n);
            xuatMaTran(a, m, n);
            if (kiemTraDoiXung(a, m, n)) {
                printf("Ma tran doi xung qua duong cheo chinh.\n");
            }
            else {
                printf("Ma tran khong doi xung qua duong cheo chinh.\n");
            }
        } break;
        }
    } while (lc < 7);
    return 0;
}