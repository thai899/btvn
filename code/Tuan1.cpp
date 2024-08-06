#include<stdio.h>
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
		}
	} while (lc < 6);
	return 0;
}
