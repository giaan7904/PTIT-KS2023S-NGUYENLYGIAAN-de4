#include <stdio.h>

void nhapMang(int arr[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMang(int arr[][100], int n, int m) {
    printf("Gia tri cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int demSoLeChiaHetCho5(int arr[][100], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0 && arr[i][j] % 5 == 0) {
                count++;
            }
        }
    }
    return count;
}

void inPhanTuBien(int arr[][100], int n, int m) {
    printf("Cac phan tu lon nhat, nho nhat nam tren bien:\n");
    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void inPhanTuCheoChinh(int arr[][100], int n, int m) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

void inPhanTuCheoPhu(int arr[][100], int n, int m) {
    printf("Cac phan tu tren duong cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == n - 1) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

void sapXepGiamDanTheoDong(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                if (arr[i][j] < arr[i][k]) {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            }
        }
    }
    printf("Mang sau khi sap xep giam dan theo dong:\n");
    inMang(arr, n, m);
}

int kiemTraSoNguyenTo(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int tinhTongSoNguyenTo(int arr[][100], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kiemTraSoNguyenTo(arr[i][j])) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

void sapXepTangDanCheoPhu(int arr[][100], int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (i + j == n - 1) {
                for (int k = j + 1; k < m; k++) {
                    if (arr[i][j] > arr[i + 1][k]) {
                        int temp = arr[i][j];
                        arr[i][j] = arr[i + 1][k];
                        arr[i + 1][k] = temp;
                    }
                }
            }
        }
    }
    printf("Mang sau khi sap xep tang dan tren duong cheo phu:\n");
    inMang(arr, n, m);
}

void chenMang1ChieuVaoMang2Chieu(int arr1[], int n, int arr2[][100], int m, int col) {
    printf("Nhap gia tri cua mang 1 chieu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Nhap chi so cot muon chen vao mang 2 chieu: ");
    scanf("%d", &col);
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= col; j--) {
            arr2[i][j + 1] = arr2[i][j];
        }
        arr2[i][col] = arr1[i];
    }
    printf("Mang 2 chieu sau khi chen mang 1 chieu:\n");
    inMang(arr2, n, m + 1);
}

int main() {
    int arr[100][100];
    int n, m;
    int choice;

    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    do {
        printf("************************MENU**************************\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu le chia het cho 5 trong mang\n");
        printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren bien, duong cheo chinh, duong cheo phu\n");
        printf("5. Sap xep giam dan theo dong cua mang\n");
        printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep tang dan cac phan tu tren duong cheo phu cua mang\n");
        printf("8. Nhap gia tri mot mang 1 chieu va chi so cot muon chen vao mang 2 chieu\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, n, m);
                break;
            case 2:
                inMang(arr, n, m);
                break;
            case 3:
                printf("So luong cac phan tu le chia het cho 5 trong mang: %d\n", demSoLeChiaHetCho5(arr, n, m));
                break;
            case 4:
                inPhanTuBien(arr, n, m);
                inPhanTuCheoChinh(arr, n, m);
                inPhanTuCheoPhu(arr, n, m);
                break;
            case 5:
                sapXepGiamDanTheoDong(arr, n, m);
                break;
            case 6:
                printf("Tong cac phan tu la so nguyen to trong mang: %d\n", tinhTongSoNguyenTo(arr, n, m));
                break;
            case 7:
                sapXepTangDanCheoPhu(arr, n, m);
                break;
            case 8:
                int arr1[100];
                int col;
                chenMang1ChieuVaoMang2Chieu(arr1, n, arr, m, col);
                break;
            case 9:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Chuc nang khong hop le!\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

