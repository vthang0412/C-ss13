#include <stdio.h>
// Khai bao nguyen mau ham 
void display(int a[100][100], int n) ;
void ketqua(int a[100][100], int n);

int main() {
    int a[100][100];
    int n;
    printf("Nhap so hang/cot cua ma tran (toi da 100): ");
    scanf("%d", &n);
    display(a, n);
    ketqua(a, n);

    return 0;
}

// Khai bao logic ham 
void display(int a[100][100], int n) {
    printf("Nhap cac phan tu trong ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void ketqua(int a[100][100], int n) {
    printf("Ma tran vua nhap la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
