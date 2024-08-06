#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


void taoMaTran(int** a, int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}


void xuatMaTran(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


void xuatCotSoLe(int** a, int n) {
    for (int j = 0; j < n; j++) {
        int isOddOnly = 1;
        for (int i = 0; i < n; i++) {
            if (a[i][j] % 2 == 0) {
                isOddOnly = 0;
                break;
            }
        }
        if (isOddOnly) {
            printf("Cot %d chi chua so le:\n", j);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}


int timMaxBien(int** a, int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[0][i] > max) max = a[0][i];
        if (a[n - 1][i] > max) max = a[n - 1][i];
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    return max;
}


int demPhanTuChuaChuSo2(int** a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                if (num % 10 == 2) {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return count;
}


void xuatPhanTuCucTieu(int** a, int n) {
    int min;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            min = 1;
            if (i > 0 && a[i][j] >= a[i - 1][j]) min = 0;
            if (i < n - 1 && a[i][j] >= a[i + 1][j]) min = 0;
            if (j > 0 && a[i][j] >= a[i][j - 1]) min = 0;
            if (j < n - 1 && a[i][j] >= a[i][j + 1]) min = 0;
            if (min) printf("Phan tu cuc tieu %d tai (%d, %d)\n", a[i][j], i, j);
        }
    }
}


void sapXepDong(int** a, int n) {
    for (int i = 0; i < n; i++) {
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


void sapXepCot(int** a, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}


int kiemTraZiczac(int** a, int n) {
    int ziczac = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if ((i % 2 == 0 && a[i][j] < a[i][j + 1]) || (i % 2 != 0 && a[i][j] > a[i][j + 1])) {
                ziczac = 0;
                break;
            }
        }
        if (!ziczac) break;
    }
    if (ziczac) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - 1; i++) {
                if ((j % 2 == 0 && a[i][j] < a[i + 1][j]) || (j % 2 != 0 && a[i][j] > a[i + 1][j])) {
                    ziczac = 0;
                    break;
                }
            }
            if (!ziczac) break;
        }
    }
    return ziczac;
}


void lietKeDongChan(int** a, int n) {
    printf("Cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < n; i++) {
        int allEven = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = 0;
                break;
            }
        }
        if (allEven) {
            printf("Dong %d\n", i);
        }
    }
}


void lietKeDongGiamDan(int** a, int n) {
    printf("Cac dong chua gia tri giam dan\n");
    for (int i = 0; i < n; i++) {
        int decreasing = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] <= a[i][j + 1]) {
                decreasing = 0;
                break;
            }
        }
        if (decreasing) {
            printf("Dong %d\n", i);
        }
    }
}


int timGiaTriXuatHienNhieuNhat(int** a, int n) {
    int* count = (int*)calloc(n * n, sizeof(int));
    int maxCount = 0;
    int mostFrequent = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[a[i][j]]++;
            if (count[a[i][j]] > maxCount) {
                maxCount = count[a[i][j]];
                mostFrequent = a[i][j];
            }
        }
    }
    free(count);
    return mostFrequent;
}


void timChuSoXuatHienNhieuNhat(int** a, int n) {
    int* digitCount = (int*)calloc(10, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = abs(a[i][j]);
            while (num > 0) {
                digitCount[num % 10]++;
                num /= 10;
            }
        }
    }

    int maxDigit = 0;
    int maxCount = digitCount[0];
    for (int i = 1; i < 10; i++) {
        if (digitCount[i] > maxCount) {
            maxDigit = i;
            maxCount = digitCount[i];
        }
    }

    printf("Chu so xuat hien nhieu nhat %d xuat hien %d lan\n", maxDigit, maxCount);
    
}


void lietKeCotTongNhoNhat(int** a, int n) {
    int* colSum = (int*)malloc(n * sizeof(int));
    int minSum = INT_MAX;

    for (int j = 0; j < n; j++) {
        colSum[j] = 0;
        for (int i = 0; i < n; i++) {
            colSum[j] += a[i][j];
        }
        if (colSum[j] < minSum) minSum = colSum[j];
    }

    printf("Cac cot co tong nho nhat (%d):\n", minSum);
    for (int j = 0; j < n; j++) {
        if (colSum[j] == minSum) {
            printf("Cột %d\n", j);
        }
    }

    free(colSum);
}

void hoanViCot(int** a, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}


void hoanViDong(int** a, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        int temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
}

int main() {
    int n, min, max;

    srand(time(NULL));

    printf("Nhap cap cua ma tran (>=5): ");
    scanf_s("%d", &n);

    if (n < 5) {
        printf("Cap ma tran phai lon hon hoac bang 5.\n");
        return 1;
    }

 
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    
    printf("Nhap gia tri nho nhat va lon nhat cho cac phan tu cua ma tran: ");
    scanf_s("%d %d", &min, &max);
    taoMaTran(a, n, min, max);


    printf("Ma tran:\n");
    xuatMaTran(a, n);

   
    xuatCotSoLe(a, n);

   
    printf("Phan tu lon nhat tren bien: %d\n", timMaxBien(a, n));

   
    printf("So phan tu chua chu so 2: %d\n", demPhanTuChuaChuSo2(a, n));

    
    xuatPhanTuCucTieu(a, n);

   
    sapXepDong(a, n);
    printf("Ma tran sau khi sap xep cac dong:\n");
    xuatMaTran(a, n);

  
    sapXepCot(a, n);
    printf("Ma tran sau khi sap xep cac cot:\n");
    xuatMaTran(a, n);


    if (kiemTraZiczac(a, n)) {
        printf("Ma tran  giam dan theo ziczac.\n");
    }
    else {
        printf("Ma tran khong giam dan theo ziczac.\n");
    }

   
    lietKeDongChan(a, n);

   
    lietKeDongGiamDan(a, n);

    printf("Gia tri xuat hien nhieu nhat: %d\n", timGiaTriXuatHienNhieuNhat(a, n));

  
    timChuSoXuatHienNhieuNhat(a, n);

   
    lietKeCotTongNhoNhat(a, n);

  
    int c1, c2;
    printf("Nhap chi so hai cot de hoan vi: ");
    scanf_s("%d %d", &c1, &c2);
    hoanViCot(a, n, c1, c2);
    printf("Ma tran sau khi hoan vi hai cot %d va %d:\n", c1, c2);
    xuatMaTran(a, n);

    
    int d1, d2;
    printf("Nhap chi so hai dong de hoan vi: ");
    scanf_s("%d %d", &d1, &d2);
    hoanViDong(a, n, d1, d2);
    printf("Ma tran sau khi hoan vi hai dong %d va %d:\n", d1, d2);
    xuatMaTran(a, n);

    
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
   

    return 0;
}