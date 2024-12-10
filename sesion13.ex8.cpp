#include <stdio.h>

int timUCLN(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;  
}

int main() {
    int so1, so2;
    printf("Nhap so thu nhat: ");
    scanf("%d", &so1);
    printf("Nhap so thu hai: ");
    scanf("%d", &so2);

    int ucln = timUCLN(so1, so2);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", so1, so2, ucln);
    return 0;
}

