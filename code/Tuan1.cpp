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
int main()
{
	int lc;
	do {
		menu();
		printf("\nMoi ban chon ");
		scanf_s("%d", &lc);
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
		}
	} while (lc < 6);
	return 0;
}
