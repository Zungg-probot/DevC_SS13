#include <stdio.h>

void addItem(int arr[], int *n){
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for(int i = 0; i < *n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void showItem(int arr[], int n){
    printf("Mang hien tai:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void themPhanTu(int arr[], int *n, int viTri, int giaTri){
    for(int i = *n; i > viTri; i--){
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    (*n)++;
}
void suaPhanTu(int arr[], int viTri, int giaTri){
    arr[viTri] = giaTri;
}
void xoaPhanTu(int arr[], int *n, int viTri){
    for (int i = viTri; i < *n - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void timKiemTuyenTinh(int arr[], int n, int x) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d\n", x);
    }
}
void timKiemNhiPhan(int arr[], int n, int x){
    sapXepTangDan(arr, n);
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x){
            printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, mid);
            return;
        } else if (arr[mid] < x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("Khong tim thay phan tu %d\n", x);
}
int main(){
    int arr[100];
    int n = 0, choice;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In gia tri cac phan tu dang quan li\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf(" a. Giam dan\n");
        printf(" b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf(" a. Tim kiem tuyen tinh\n");
        printf(" b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addItem(arr, &n);
                break;
            case 2:
                showItem(arr, n);
                break;
            case 3:
                int viTri, giaTri;
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri can them: ");
                scanf("%d", &giaTri);
                themPhanTu(arr, &n, viTri, giaTri);
                break;
            case 4:
                int viTri, giaTri;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri moi: ");
                scanf("%d", &giaTri);
                suaPhanTu(arr, viTri, giaTri);
                break;
            case 5:
                int viTri;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                xoaPhanTu(arr, &n, viTri);
                break;
            case 6:
                char subChoice;
                printf("  a. Giam dan\n  b. Tang dan\nLua chon cua ban: ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sapXepGiamDan(arr, n);
                } else if (subChoice == 'b') {
                    sapXepTangDan(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7: 
                char subChoice;
                int x;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                printf("  a. Tim kiem tuyen tinh\n  b. Tim kiem nhi phan\nLua chon cua ban: ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    timKiemTuyenTinh(arr, n, x);
                } else if (subChoice == 'b') {
                    timKiemNhiPhan(arr, n, x);
                } else {
                    printf("Lua chon khong hop le\n");
                }
                break;
            case 8:
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 8);
    return 0;
}
