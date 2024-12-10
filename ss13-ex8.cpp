#include <stdio.h>

int ucln(int a, int b);
int main() {
    int a, b;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    int result = ucln(a, b);
    printf("UCLN cua %d va %d la: %d\n", a, b, result);

    return 0;
}
int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
