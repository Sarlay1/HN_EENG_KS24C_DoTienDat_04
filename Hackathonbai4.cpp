#include <stdio.h>

#define MAX_SIZE 100

int isPerfectNumber(int n) {
    if (n <= 1) return 0;
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    int arr[MAX_SIZE], n, choice;

   
    do {
        printf("\nMenu\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong hoan hao co trong mang\n");
        printf("4. Tim gia tri lon thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Cho nguoi dung nhap vao mot phan tu\n");
        printf("9. Sap xep lai mang va hien thi toan bo phan tu co trong mang sao cho so chan dung truoc, so le dung sau\n");
        printf("10. Dao nguoc thu tu cac phan tu co trong mang\n");
        printf("11. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	 printf("Nhap so phan tu cua mang: ");
                 scanf("%d", &n);
                  for (int i = 0; i < n; i++) {
                  printf("Nhap gia tri cho phan tu arr[%d]: ", i);
                  scanf("%d", &arr[i]);
    }
                printf("Cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 2: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (isPerfectNumber(arr[i])) {
                        count++;
                    }
                }
                printf("So luong so hoan hao trong mang: %d\n", count);
                break;
            }

            
            case 4: {
                if (n >= MAX_SIZE) {
                    printf("Khong the them phan tu, mang da day.\n");
                    break;
                }
                int pos, value;
                printf("Nhap gia tri phan tu moi: ");
                scanf("%d", &value);
                printf("Nhap vi tri them vao (0-%d): ", n);
                scanf("%d", &pos);

                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                    printf("Them phan tu thanh cong.\n");
                }
                break;
            }

            case 5: {
                int pos;
                printf("Nhap vi tri muon xoa (0-%d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Xoa phan tu thanh cong.\n");
                }
                break;
            }

            case 6: {
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da duoc sap xep tang dan.\n");
                break;
            }

            case 7: {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep lai.\n");
                break;
            }

            case 8: {
                int val;
                printf("Nhap gia tri phan tu can tim: ");
                scanf("%d", &val);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == val) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("Phan tu ton tai trong mang.\n");
                } else {
                    printf("Phan tu khong ton tai.\n");
                }
                break;
            }

            

            case 10: {
                for (int i = 0; i < n / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - 1 - i];
                    arr[n - 1 - i] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 11:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 11);

    return 0;
}
