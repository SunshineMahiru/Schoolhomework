#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000000

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main(void) {
    int n;
    printf("请输入数字进行随机生成排序(max 1000000): ");
    scanf("%d", &n);
    if (n <= 0 || n > COUNT) {
        printf("非法输入，数值应该在1到1000000之间\n");
        return -1;
    }

    int *data = (int *)malloc(n * sizeof(int));
    if (data == NULL) {
        perror("内存不够啦");
        return -1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100000 + 1;
    }

    FILE *fp = fopen("C:\\Users\\admin\\Desktop\\test\\data.txt", "w");
    if (fp == NULL) {
        perror("文件打不开哦");
        free(data);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d", data[i]);
        if (i < n - 1) {
            fputc(',', fp);
        }
    }
    fputc('\n', fp);

    quickSort(data, 0, n - 1);

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d", data[i]);
        if (i < n - 1) {
            fputc(',', fp);
        }
    }
    fputc('\n', fp);

    fclose(fp);
    free(data);
    return 0;
}
