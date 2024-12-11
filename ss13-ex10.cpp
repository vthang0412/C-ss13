#include <stdio.h>

void nhapMang(int arr[], int *n);
void inMang(int arr[], int n);
void themPhanTu(int arr[], int *n);
void suaPhanTu(int arr[], int n);
void xoaPhanTu(int arr[], int *n);
void sapXepMang(int arr[], int n, char chon);
void timKiem(int arr[], int n, int key, char chon);
int timKiemTuyenTinh(int arr[], int n, int key);
int timKiemNhiPhan(int arr[], int n, int key);
int isSorted(int arr[], int n);

int main() {
    int arr[100]; 
    int n = 0, choice, key;
    char chonSapXep, chonTimKiem;

    do {
 	printf("\n-----------------------MENU-------------------------\n");
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n");
    printf("   a. Sap xep giam dan\n");
    printf("   b. Sap xep tang dan\n");
    printf("7. Tim kiem phan tu\n");
    printf("   a. Tim kiem tuyen tinh\n");
    printf("   b. Tim kiem nhi phan\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                themPhanTu(arr, &n);
                break;
            case 4:
                suaPhanTu(arr, n);
                break;
            case 5:
                xoaPhanTu(arr, &n);
                break;
            case 6:
                if (n == 0) {
                    printf("Mang rong, khong the sap xep.\n");
                } else {
                    printf("Chon a. Sap xep giam dan, b. Sap xep tang dan: ");
                    scanf(" %c", &chonSapXep);
                    sapXepMang(arr, n, chonSapXep);
                }
                break;
            case 7:
                if (n == 0) {
                    printf("Mang rong, khong the tim kiem.\n");
                } else {
                    printf("Chon a. Tim kiem tuyen tinh, b. Tim kiem nhi phan: ");
                    scanf(" %c", &chonTimKiem);
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &key);
                    timKiem(arr, n, key, chonTimKiem);
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (choice != 8);
    return 0;
}

void nhapMang(int arr[], int *n) {
    printf("Nhap so phan tu can nhap (toi da 100): ");
    scanf("%d", n);
    if (*n > 100) {
        printf("So phan tu vuot qua gioi han (100). Dat lai n = 100.\n");
        *n = 100;
    }
    printf("Nhap gia tri cho cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int n) {
    if (n == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Gia tri cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int *n) {
    if (*n >= 100) {
        printf("Khong the them phan tu vi mang da day.\n");
        return;
    }
    int viTri, giaTri;
    printf("Nhap vi tri can them (0 den %d): ", *n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri phan tu can them: ");
    scanf("%d", &giaTri);
    for (int i = *n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    (*n)++;
    printf("Mang sau khi them:\n");
    inMang(arr, *n);
}

void suaPhanTu(int arr[], int n) {
    if (n == 0) {
        printf("Mang rong, khong co phan tu de sua.\n");
        return;
    }
    int viTri, giaTri;
    printf("Nhap vi tri phan tu can sua (0 den %d): ", n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi cho phan tu: ");
    scanf("%d", &giaTri);
    arr[viTri] = giaTri;
    printf("Mang sau khi sua:\n");
    inMang(arr, n);
}

void xoaPhanTu(int arr[], int *n) {
    if (*n == 0) {
        printf("Mang rong, khong co phan tu de xoa.\n");
        return;
    }
    int viTri;
    printf("Nhap vi tri phan tu can xoa (0 den %d): ", *n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Mang sau khi xoa:\n");
    inMang(arr, *n);
}

void sapXepMang(int arr[], int n, char chon) {
    int temp;
    if (chon == 'a') {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else if (chon == 'b') {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else {
        printf("Lua chon khong hop le.\n");
        return;
    }
    printf("Mang sau khi sap xep:\n");
    inMang(arr, n);
}

void timKiem(int arr[], int n, int key, char chon) {
    int index;
    if (chon == 'a') {
        index = timKiemTuyenTinh(arr, n, key);
    } else if (chon == 'b') {
        if (!isSorted(arr, n)) {
            printf("Mang chua sap xep, vui long sap xep truoc khi tim kiem nhi phan.\n");
            return;
        }
        index = timKiemNhiPhan(arr, n, key);
    } else {
        printf("Lua chon khong hop le.\n");
        return;
    }
    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", key, index);
    } else {
        printf("Khong tim thay phan tu %d.\n", key);
    }
}

int timKiemTuyenTinh(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int timKiemNhiPhan(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0; 
        }
    }
    return 1; 
}
