#include <stdio.h>

int mang[100];
int soPhanTu = 0;
void nhapGiaTri() {
    printf("Nhap so phan tu: ");
    scanf("%d", &soPhanTu);
    for (int chiSo = 0; chiSo < soPhanTu; chiSo++) {
        printf("Nhap gia tri phan tu thu %d: ", chiSo + 1);
        scanf("%d", &mang[chiSo]);
    }
}
void inGiaTri() {
    printf("Cac phan tu trong mang la: ");
    for (int chiSo = 0; chiSo < soPhanTu; chiSo++) {
        printf("%d ", mang[chiSo]);
    }
    printf("\n");
}
void themPhanTu() {
    int giaTri, viTri;
    printf("Nhap gia tri phan tu muon them: ");
    scanf("%d", &giaTri);
    printf("Nhap vi tri muon them (0 den %d): ", soPhanTu);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > soPhanTu) {
        printf("Vi tri khong hop le!\n");
    } else {
        for (int chiSo = soPhanTu; chiSo > viTri; chiSo--) {
            mang[chiSo] = mang[chiSo - 1];
        }
        mang[viTri] = giaTri;
        soPhanTu++;
    }
}
void suaPhanTu() {
    int giaTriMoi, viTri;
    printf("Nhap vi tri muon sua (0 den %d): ", soPhanTu - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= soPhanTu) {
        printf("Vi tri khong hop le!\n");
    } else {
        printf("Nhap gia tri moi: ");
        scanf("%d", &giaTriMoi);
        mang[viTri] = giaTriMoi;
    }
}
void xoaPhanTu() {
    int viTri;
    printf("Nhap vi tri muon xoa (0 den %d): ", soPhanTu - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= soPhanTu) {
        printf("Vi tri khong hop le!\n");
    } else {
        for (int chiSo = viTri; chiSo < soPhanTu - 1; chiSo++) {
            mang[chiSo] = mang[chiSo + 1];
        }
        soPhanTu--;
    }
}
void sapXepGiamDan() {
    for (int chiSo = 0; chiSo < soPhanTu - 1; chiSo++) {
        for (int j = chiSo + 1; j < soPhanTu; j++) {
            if (mang[chiSo] < mang[j]) {
                int temp = mang[chiSo];
                mang[chiSo] = mang[j];
                mang[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan:\n");
    inGiaTri();
}
void sapXepTangDan() {
    for (int chiSo = 0; chiSo < soPhanTu - 1; chiSo++) {
        for (int j = chiSo + 1; j < soPhanTu; j++) {
            if (mang[chiSo] > mang[j]) {
                int temp = mang[chiSo];
                mang[chiSo] = mang[j];
                mang[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep tang dan:\n");
    inGiaTri();
}
void timKiemTuyenTinh(int giaTriTimKiem) {
    for (int chiSo = 0; chiSo < soPhanTu; chiSo++) {
        if (mang[chiSo] == giaTriTimKiem) {
            printf("Phan tu %d duoc tim thay o vi tri %d\n", giaTriTimKiem, chiSo);
            return;
        }
    }
    printf("Khong tim thay phan tu %d\n", giaTriTimKiem);
}
void timKiemNhiPhan(int giaTriTimKiem) {
    int trai = 0, phai = soPhanTu - 1;
    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;
        if (mang[giua] == giaTriTimKiem) {
            printf("Phan tu %d duoc tim thay o vi tri %d\n", giaTriTimKiem, giua);
            return;
        }
        if (mang[giua] < giaTriTimKiem) {
            trai = giua + 1;
        } else {
            phai = giua - 1;
        }
    }
    printf("Khong tim thay phan tu %d\n", giaTriTimKiem);
}
int main() {
    int luaChon, giaTriTimKiem;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapGiaTri();
                break;
            case 2:
                inGiaTri();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6:
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Nhap lua chon: ");
                char sortChoice;
                scanf(" %c", &sortChoice);
                if (sortChoice == 'a') {
                    sapXepGiamDan();
                } else if (sortChoice == 'b') {
                    sapXepTangDan();
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 7:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &giaTriTimKiem);
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon: ");
                char searchChoice;
                scanf(" %c", &searchChoice);
                if (searchChoice == 'a') {
                    timKiemTuyenTinh(giaTriTimKiem);
                } else if (searchChoice == 'b') {
                    timKiemNhiPhan(giaTriTimKiem);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 8);

    return 0;
}

