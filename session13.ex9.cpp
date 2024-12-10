#include <stdio.h>
#include <math.h>

void nhapMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Nhap gia tri cho cac phan tu cua ma tran %d x %d:\n", soHang, soCot);
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nhap phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);
        }
    }
}
void inMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Ma tran la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}
void inGoc(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Cac phan tu o goc la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            if ((i == 0 && (j == 0 || j == soCot - 1)) || (i == soHang - 1 && (j == 0 || j == soCot - 1))) {
                printf("%d ", maTran[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void inBien(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Cac phan tu tren duong bien la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            if (i == 0 || i == soHang - 1 || j == 0 || j == soCot - 1) {
                printf("%d ", maTran[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void inCheo(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            if (i == j || i + j == soHang - 1) {
                printf("%d ", maTran[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int laSoNguyenTo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void inNguyenTo(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Cac phan tu la so nguyen to la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            if (laSoNguyenTo(maTran[i][j])) {
                printf("%d ", maTran[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot, luaChon;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &soHang);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &soCot);

    int maTran[soHang][soCot];

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua ma tran\n");
        printf("2. In gia tri cac phan tu cua ma tran theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMaTran(soHang, soCot, maTran);
                break;
            case 2:
                inMaTran(soHang, soCot, maTran);
                break;
            case 3:
                inGoc(soHang, soCot, maTran);
                break;
            case 4:
                inBien(soHang, soCot, maTran);
                break;
            case 5:
                inCheo(soHang, soCot, maTran);
                break;
            case 6:
                inNguyenTo(soHang, soCot, maTran);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

