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
       
        }
    } while (lc < 7);
    return 0;
}