#include <stdio.h>
void addItem(int a[][100], int n, int m){
    printf("Nhap gia tri cac phan tu cua mang: \n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void showItem(int a[][100], int n, int m){
    printf("Gia tri cac phan tu cua mang: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void inGoc(int a[][100], int n, int m){
    printf("Cac phan tu o goc cua ma tran: \n");
    printf("%d\n",a[0][0]);
    printf("%d\n",a[0][m-1]);
    printf("%d\n",a[n-1][0]);
    printf("%d\n",a[n-1][m-1]);
}
void inBien(int a[][100], int n, int m){
    printf("Cac phan tu o duong bien cua ma tran: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}
void inDuongCheo(int a[][100], int n, int m){
    printf("Cac phan tu o duong cheo chinh va cheo phu cua ma tran:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == j || i + j == n - 1){
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}
int kiemTraSNT(int n){
    if(n < 2){
    	return 0;
	}
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
        	return 0;
		}
    }
    return 1;
}
void inSNT(int a[][100], int n, int m){
    printf("Cac phan tu la so nguyen to trong ma tran:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(kiemTraSNT(a[i][j])){
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}
int main(){
    int a[100][100], n, m, chose;
    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chose);
        switch(chose){
            case 1:
                addItem(a, n, m);
                break;
            case 2:
                showItem(a, n, m);
                break;
            case 3:
                inGoc(a, n, m);
                break;
            case 4:
                inBien(a, n, m);
                break;
            case 5:
                inDuongCheo(a, n, m);
                break;
            case 6:
                inSNT(a, n, m);
                break;
            case 7:
                break;
            default:
                printf("Chuc nang khong hop le\n");
        }
    }while(chose != 7);

    return 0;
}

