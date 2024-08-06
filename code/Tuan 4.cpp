#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void menu()
{
    printf("\n1.Bai 7");
    printf("\n2.Bai 8");
    printf("\n3.Bai 9");
    printf("\n4.Bai 10");
    printf("\n5.Bai 11");
   
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void nhapChuoi(char* str, int size) {
    printf("Nhap chuoi: ");
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';  
}


void xuatChuoi(const char* str) {
    printf("%s\n", str);
}


int kiemTraDoiXung(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;  
        }
    }
    return 1;  
}


int main()
{
    int lc;
    int chon;
    char str[256], s1[256], s2[256], strInsert[256];
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        getchar();
        switch (lc)
        {
        case 1 :
        {
            nhapChuoi(str, sizeof(str));
            if (kiemTraDoiXung(str)) {
                printf("Chuoi doi xung.\n");
            }
            else {
                printf("Chuoi khong doi xung.\n");
            }

        }break;
        
        }
    } while (lc < 7);
    return 0;
}