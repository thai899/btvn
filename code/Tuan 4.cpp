#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include<string.h>

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
void timHoacNoiChuoi(char* s1, const char* s2) {
    char* pos = strstr(s1, s2);
    if (pos) {
        printf("Vi tri xuat hien cua chuoi '%s' trong chuoi '%s': %ld\n", s2, s1, pos - s1);
    }
    else {
        strcat(s1, s2);
        printf("Chuoi '%s' khong co trong chuoi '%s'. Chuoi moi sau khi noi: '%s'\n", s2, s1, s1);
    }
}
void chenChuoi(char* str, const char* strInsert, int vt) {
    int lenStr = strlen(str);
    int lenInsert = strlen(strInsert);

    if (vt < 0 || vt > lenStr) {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    memmove(str + vt + lenInsert, str + vt, lenStr - vt + 1);
    memcpy(str + vt, strInsert, lenInsert);

    printf("Chuoi sau khi chen: '%s'\n", str);
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
        case 2:
        {
            printf("Nhap chuoi s1: ");
            nhapChuoi(s1, sizeof(s1));
            printf("Nhap chuoi s2: ");
            nhapChuoi(s2, sizeof(s2));
            timHoacNoiChuoi(s1, s2);
        }break;
        case 3:
        {
            printf("Nhap chuoi goc: ");
            nhapChuoi(str, sizeof(str));
            printf("Nhap chuoi can chen: ");
            nhapChuoi(strInsert, sizeof(strInsert));
            printf("Nhap vi tri can chen: ");
            scanf_s("%d", &vt);
            getchar();
            chenChuoi(str, strInsert, vt);
        }break;
        }
    } while (lc < 7);
    return 0;
}