#include <stdio.h>

struct Student {
    char name[50];
    int id;
    int age;
    float grade;
};

int main() {
	int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap ten: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Nhap ma so: ");
        scanf("%d", &students[i].id);
        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
        printf("Nhap diem: ");
        scanf("%f", &students[i].grade);
    }
    printf("\nThong tin sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ten: %s\n", students[i].name);
        printf("Ma so: %d\n", students[i].id);
        printf("Tuoi: %d\n", students[i].age);
        printf("Diem: %.2f\n", students[i].grade);
    }
    return 0;
}