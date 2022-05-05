#include <stdio.h>
#include <windows.h>
#define cot 1000

void inMaTrix(int arr[][cot], int n, int m);                         void sumMaTrix(int arr[][cot], int n, int m);
void outMaTrix(int arr[][cot], int n, int m);                        void findElementMaTrix(int arr[][cot], int n, int m, int x);
void maxMaTrix(int arr[][cot], int n, int m);                        void coutElementNegativeMaTrix(int arr[][cot], int n, int m);
void findElementOfcolumn_max(int arr[][cot], int col, int row);      void findElementOfcolumn_min(int arr[][cot], int col, int row);
void findElementOfRow_max(int arr[][cot], int col, int row);         void findElementOfRow_min(int arr[][cot], int col, int row); 
int main() {
    system("cls");
    int col, row, m;
    printf("nhap so cot "); scanf("%d", &col);
    printf("nhap so dong "); scanf("%d", &row);
    int arr[col][1000];
    inMaTrix(arr, col, row);
    outMaTrix(arr, col, row);
    while(1) {
        printf("\n======================================================\n");
        printf("|| 0. thoat chuong trinh -> exit                    ||\n");
        printf("|| 1. tim phan tu lon nhat trong ma tran            ||\n");
        printf("|| 2. tim phan tu x trong ma tran                   ||\n");
        printf("|| 3. tim tong cac phan tu trong ma tran            ||\n");
        printf("|| 4. tim so phan tu am cua ma tran                 ||\n");
        printf("|| 5. tim phan tu lon nhat trong cot cua ma tran    ||\n");
        printf("|| 6. tim phan tu nho nhat trong cot cua ma tran    ||\n");
        printf("|| 7. tim phan tu lon nhat trong dong cua ma tran   ||\n");
        printf("|| 8. tim phan tu nho nhat trong dong cua ma tran   ||\n");
        printf("\n => Chon yeu cau: ");
        scanf("%d", &m);
        if (m == 0) {
            printf("Thoat chuong trinh!");
            break;  
        }
        switch (m)
        {
        case 1:
            maxMaTrix(arr, col, row);
            printf("\n");
            break;
        case 2:
            int x; printf("\nnhap phan tu can tim! "); scanf("%d", &x);
            findElementMaTrix(arr, col, row, x);
            printf("\n");
            break;
        case 3: 
            sumMaTrix(arr, col, row);
            printf("\n");
            break;
        case 4: 
            coutElementNegativeMaTrix(arr, col, row);
            printf("\n");
            break;
        case 5: 
            int b; printf("chon cot = "); scanf("%d", &b);
            findElementOfcolumn_max(arr, b, row);
            printf("\n");
            break;
        case 6: 
            int c; printf("chon cot = "); scanf("%d", &c);
            findElementOfcolumn_min(arr, c, row);
            printf("\n");
            break; 
        case 7: 
            int d; printf("chon dong = "); scanf("%d", &d);
            findElementOfRow_max(arr, col, d);
            printf("\n");
            break;
        case 8: 
            int e; printf("chon dong = "); scanf("%d", &e);
            findElementOfRow_min(arr, col, e);
            printf("\n");
            break;     
        default:
            printf("yeu cau khong co !");
            printf("\n");
            break;
        }
    }
    
    
}    
    
void inMaTrix(int arr[][cot], int n, int m) 
{
    int i, j;
    for (i = 0; i < m; i++) 
        for(j = 0; j < n; j++) {
            printf("Nhap phan tu arr[%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }    
}

void outMaTrix(int arr[][cot], int n, int m) 
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++) {

            printf("|%d| \t", arr[i][j]);
        }   
        printf("\n"); 
    }

}
void maxMaTrix(int arr[][cot], int n, int m)
{
    int i, j, max = arr[0][0];
    for (i = 1; i < m; i++) 
        for(j = 1; j < n; j++) {
            (max < arr[i][j]) ? max = arr[i][j] : max = max;
        }
    printf("max = %d", max);
}
void sumMaTrix(int arr[][cot], int n, int m) 
{
    int i, j, sum = 0;
    for (i = 0; i < m; i++) 
        for(j = 0; j < n; j++) {
           sum += arr[i][j]; 
        }
    printf("sum = %d", sum);
}
void findElementMaTrix(int arr[][cot], int n, int m, int x) {
    int i, j, ans = 0, c, r;
    for (i = 0; i < m; i++) 
        for(j = 0; j < n; j++) {
            (x == arr[i][j]) ? (ans += 1, c = j, r = i) : ans;
        }
    (ans == 0) ? printf("\nKhong tim thay x!"): printf("\ntim thay x tai vi tri [%d][%d]", c, r);
}
void coutElementNegativeMaTrix(int arr[][cot], int n, int m) 
{
    int i, j, dem=0;
    for (i = 0; i < m; i++) 
        for(j = 0; j < n; j++) {
            (arr[i][j] < 0) ? dem++ : dem;
        }
    printf("\nso phan tu am la: %d", dem);
}
void findElementOfcolumn_max(int arr[][cot], int col, int row)
{
    int i, max = arr[0][col];
    for(i = 1; i < row; i++) 
        if(max < arr[i][col])
            max = arr[i][col];
    printf("max of column = %d", max);
}
void findElementOfcolumn_min(int arr[][cot], int col, int row)
{
    int i, min = arr[0][col];
    for(i = 1; i < row; i++) 
        if(min > arr[i][col])
            min = arr[i][col];
    printf("min of column = %d", min);
}
void findElementOfRow_max(int arr[][cot], int col, int row)
{
    int i, max = arr[row][0];
    for(i = 1; i < col; i++) 
        if(max < arr[row][i])
            max = arr[row][i];
    printf("max of Row = %d", max);
}
void findElementOfRow_min(int arr[][cot], int col, int row)
{
    int i, min = arr[row][i];
    for(i = 1; i < col; i++) 
        if(min > arr[row][i])
            min = arr[row][i];
    printf("min of Row = %d", min);
}