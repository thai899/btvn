#include <stdio.h>


void menu()
{
    printf("\n1.Bai 9");
    printf("\n2.Bai 10");
    printf("\n3.Bai 11");
    printf("\n4.Bai 12");
    printf("\n5.Bai 13");
    printf("\n5.Bai 14");
    printf("\n5.Bai 15");
    printf("\n5.Bai 16");
    printf("\n5.Bai 17");
    printf("\n5.Bai 18");
    printf("\n5.Bai 19");
   
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
        }
    } while (lc < 7);
    return 0;
}