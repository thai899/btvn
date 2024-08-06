#include <stdio.h>
#include <math.h> 

void menu()
{
    printf("\n1.Bai 9");
    printf("\n2.Bai 10");
    printf("\n3.Bai 11");
    printf("\n4.Bai 12");
    printf("\n5.Bai 13");
    printf("\n6.Bai 14");
    printf("\n7.Bai 15");
    printf("\n8.Bai 16");
    printf("\n9.Bai 17");
    printf("\n10.Bai 18");
    printf("\n11.Bai 19");

   
}
double S_deQuy(int n) {
    if (n == 1) {
        return 1.0 / (1 * 2 * 3);
    }
    return (1.0 / (n * (n + 1) * (n + 2))) + S_deQuy(n - 1);
}


double S_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}
unsigned long long fibonacci(int k) {
    if (k <= 2) {
        return 1;
    }
    unsigned long long a = 1, b = 1, c;
    for (int i = 3; i <= k; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

void xuatFibonacciTrongDoan(int m, int n) {
    int k = 1;
    unsigned long long fib = fibonacci(k);

    while (fib < m) {
        k++;
        fib = fibonacci(k);
    }

    while (fib <= n) {
        printf("%llu ", fib);
        k++;
        fib = fibonacci(k);
    }
    printf("\n");
}
unsigned long long fibonacciMaxLessThanNRec(unsigned long long n, int k) {
    unsigned long long fib = fibonacci(k);
    if (fib >= n) {
        return fibonacci(k - 1);
    }
    return fibonacciMaxLessThanNRec(n, k + 1);
}


unsigned long long fibonacciMaxLessThanNKhuDeQuy(unsigned long long n) {
    unsigned long long a = 1, b = 1, c;
    if (n <= 1) {
        return 0;
    }

    while (1) {
        c = a + b;
        if (c >= n) {
            break;
        }
        a = b;
        b = c;
    }
    return b;
}

int xnDeQuy(int n);
int ynDeQuy(int n);
void tinhDaiHinhKhuDeQuy(int n, int* x, int* y) {
    int xPrev = 1, yPrev = 0;
    int xCurrent, yCurrent;

    for (int i = 1; i <= n; i++) {
        xCurrent = xPrev + yPrev;
        yCurrent = 3 * xPrev + 2 * yPrev;

        xPrev = xCurrent;
        yPrev = yCurrent;
    }

    *x = xPrev;
    *y = yPrev;
}
double unDeQuy(double a, double q, int n) {
    if (n == 1) {
        return a;
    }
    return q * unDeQuy(a, q, n - 1);
}
int UDeQuy(int n) {
    if (n < 6) {
        return n;
    }
    return UDeQuy(n - 5) + UDeQuy(n - 4) + UDeQuy(n - 3) + UDeQuy(n - 2) + UDeQuy(n - 1);
}
int AnDeQuy(int n) {

    if (n == 1) {
        return 1;
    }


    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += AnDeQuy(i);
    }


    return n * sum;
}
int YDeQuyTrucTiep(int n) {

    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    return YDeQuyTrucTiep(n - 1) + 2 * YDeQuyTrucTiep(n - 2) + 3 * YDeQuyTrucTiep(n - 3);
}
int XDeQuy(int n) {
  
    if (n == 1 || n == 2) {
        return 1;
    }


    return XDeQuy(n - 1) + (n - 1) * XDeQuy(n - 2);
}
int RDeQuy(int n) {
   
    if (n == 0) return 1;
    if (n == 1) return 2;

   
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (n - i) * XDeQuy(i);
    }
    return sum;
}

int main()
{
    int lc;
    int n;
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
     
        switch (lc)
        {
        case 1 :
        {
            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            
            if (n <= 0) {
                printf("So nguyen duong n phai lon hon 0.\n");
                return 1;
            }

            
            double result_deQuy = S_deQuy(n);
            printf("S(n) tinh theo cach de quy: %lf\n", result_deQuy);

           
            double result_khuDeQuy = S_khuDeQuy(n);
            printf("S(n) tinh theo cach khu de quy: %lf\n", result_khuDeQuy);

        }break;
        case 2:
        {
            int m, n;

            printf("Nhap m: ");
            scanf_s("%d", &m);
            printf("Nhap n: ");
            scanf_s("%d", &n);

            if (m <= 0 || n <= 0 || m > n) {
                printf("Vui long nhap m va n sao cho m n va m n phai lon hon 0.\n");
                return 1;
            }

            printf("Day so Fibonacci thuoc doan [%d, %d]:\n", m, n);
            xuatFibonacciTrongDoan(m, n);
        }break;
        case 3:
        {
            unsigned long long n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%llu", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong lon hon 0.\n");
                return 1;
            }

            int k = 1;
            while (fibonacci(k) < n) {
                k++;
            }
            unsigned long long resultRec = fibonacciMaxLessThanNRec(n, 1);
            printf("So Fibonacci lon nhat nho hon %llu theo cach de quy la: %llu\n", n, resultRec);


            unsigned long long resultKhuDeQuy = fibonacciMaxLessThanNKhuDeQuy(n);
            printf("So Fibonacci lon nhat nho hon %llu theo cach khu de quy la: %llu\n", n, resultKhuDeQuy);
        }break;
        case 4:
        {
            int n;

            printf("Nhap chi so n: ");
            scanf_s("%d", &n);

            if (n < 0) {
                printf("Chi so n phai la so nguyen khong am\n");
                return 1;
            }


            int xnRec = xnDeQuy(n);
            int ynRec = ynDeQuy(n);
            printf("So hang thu %d cua day xn theo cach de quy la: %d\n", n, xnRec);
            printf("So hang thu %d cua day yn theo cach de quy la: %d\n", n, ynRec);


            int xnKhuDeQuy, ynKhuDeQuy;
            tinhDaiHinhKhuDeQuy(n, &xnKhuDeQuy, &ynKhuDeQuy);
            printf("So hang thu %d cua day xn theo cach khu de quy la: %d\n", n, xnKhuDeQuy);
            printf("So hang thu %d cua day yn theo cach khu de quy la: %d\n", n, ynKhuDeQuy);
        }break;
        case 5:
        {
            double a, q;
            int n;

            printf("Nhap hang dau a: ");
            scanf_s("%lf", &a);
            printf("Nhap cong boi q: ");
            scanf_s("%lf", &q);
            printf("Nhap chi so phan tu n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Chi so n phai la so nguyen duong.\n");
                return 1;
            }


            double resultDeQuy = unDeQuy(a, q, n);
            printf("So hang thu %d cua day xn theo cach khu de quy la: %.2lf\n", n, resultDeQuy);
        }break;
        case 6:
        {
            int n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong.\n");
                return 1;
            }
            int resultDeQuy = UDeQuy(n);
            printf("Gia tri cua U(%d) theo cach de quy là: %d\n", n, resultDeQuy);
        }break;
        case 7:
        {

            int n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong.\n");
                return 1;
            }
            int result = AnDeQuy(n);
            printf("Gia tri cua A(%d) theo cach de quy là: %d\n", n, result);
        }break;
        case 8:
        {
            int n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong.\n");
                return 1;
            }
            int resultTrucTiep = YDeQuyTrucTiep(n);
            printf("Gia tri cua Y (%d) theo cach de quy truc tiep la: %d\n", n, resultTrucTiep);
        }break;
        case 9:
        {

            int n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong.\n");
                return 1;
            }
            int result = XDeQuy(n);
            printf("Gia tri cua Y (%d) theo cach de quy là: %d\n", n, result);
        }break;
        case 10:
        {
            int n;

            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap so nguyen duong.\n");
                return 1;
            }
            int result = RDeQuy(n);
            printf("Gia tri cua x(%d) theo cach de quy la: %d\n", n, result);
        }break;
        }
    } while (lc < 12);
    return 0;
}
int xnDeQuy(int n) {
    if (n == 0) {
        return 1;
    }
    return xnDeQuy(n - 1) + ynDeQuy(n - 1);
}


int ynDeQuy(int n) {
    if (n == 0) {
        return 0;
    }
    return 3 * xnDeQuy(n - 1) + 2 * ynDeQuy(n - 1);
}
