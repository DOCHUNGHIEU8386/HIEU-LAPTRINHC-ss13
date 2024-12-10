#include <stdio.h>
#include <stdlib.h> 

void taoMaTran(int soHang, int soCot, int **maTran) {
    printf("Nhap cac gia tri cho ma tran %d x %d:\n", soHang, soCot);  
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nhap phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);  
        }
    }
}

void inMaTran(int soHang, int soCot, int **maTran) {
    printf("Ma tran vua nhap la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);  
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &soHang);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &soCot);

    int **maTran = (int **)malloc(soHang * sizeof(int *));
    for (int i = 0; i < soHang; i++) {
        maTran[i] = (int *)malloc(soCot * sizeof(int));
    }
    
    taoMaTran(soHang, soCot, maTran);
    inMaTran(soHang, soCot, maTran);

    for (int i = 0; i < soHang; i++) {
        free(maTran[i]);
    }
    free(maTran);

    return 0;
}

