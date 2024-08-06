#include <stdio.h>
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
        }
    } while (lc < 7);
    return 0;
}