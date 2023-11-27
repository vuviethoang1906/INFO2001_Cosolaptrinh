#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
};

void displayStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("\n");
}

void sortStudentsByName(struct Student students[], int numStudents) {
    int i, j;
    struct Student temp;
    for (i = 0; i < numStudents - 1; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sortStudentsByGPA(struct Student students[], int numStudents) {
    int i, j;
    struct Student temp;
    for (i = 0; i < numStudents - 1; i++) {
        for (j = i + 1; j < numStudents; j++) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

void searchStudentByName(struct Student students[], int numStudents, char searchName[]) {
    int i, found = 0;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Thong tin sinh vien co ten %s:\n", searchName);
            displayStudent(students[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten %s.\n", searchName);
    }
}

void searchStudentByID(struct Student students[], int numStudents, int searchID) {
    int i, found = 0;
    for (i = 0; i < numStudents; i++) {
        if (students[i].id == searchID) {
            printf("Thong tin sinh vien co ID %d:\n", searchID);
            displayStudent(students[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n", searchID);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;


    do {
        printf("Menu:\n");
        printf("1. danh sach sinh vien theo ten\n");
        printf("2. danh sach sinh vien theo diem\n");
        printf("3. Tim kiem sinh vien theo ten\n");
        printf("4. Tim kiem sinh vien theo ID\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortStudentsByName(students, numStudents);
                printf("Danh sach sinh vien da duoc sap xep theo ten.\n");
                break;
            case 2:
                sortStudentsByGPA(students, numStudents);
                printf("Danh sach sinh vien da duoc sap xep theo GPA.\n");
                break;
            case 3:
                if (numStudents > 0) {
                    char searchName[MAX_NAME_LENGTH];
                    printf("Nhap ten sinh vien can tim: ");
                    scanf("%s", searchName);
                    searchStudentByName(students, numStudents, searchName);
                } else {
                    printf("Khong co sinh vien nao trong danh sach!\n");
                }
                break;
            case 4:
                if (numStudents > 0) {
                    int searchID;
                    printf("Nhap ID sinh vien can tim: ");
                    scanf("%d", &searchID);
                    searchStudentByID(students, numStudents, searchID);
                } else {
                    printf("Khong co sinh vien nao trong danh sach!\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Chuc nang khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
