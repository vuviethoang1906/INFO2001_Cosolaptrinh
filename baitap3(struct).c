#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define MAX_NAME_LENGTH 50

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
    float salary;
};

void displayEmployee(struct Employee emp) {
    printf("ID: %d\n", emp.employeeID);
    printf("Name: %s\n", emp.name);
    printf("Position: %s\n", emp.position);
    printf("Salary: %.2f\n", emp.salary);
    printf("\n");
}

int addEmployee(struct Employee employees[], int numEmployees) {
    if (numEmployees < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        printf("Nhap ID nhan vien: ");
        scanf("%d", &newEmployee.employeeID);
        printf("Nhap ten: ");
        scanf("%s", newEmployee.name);
        printf("Nhap chuc vu: ");
        scanf("%s", newEmployee.position);
        printf("Nhap luong: ");
        scanf("%f", &newEmployee.salary);

        employees[numEmployees] = newEmployee;
        numEmployees++;
        printf("Nhan vien da duoc them!\n\n");
        return numEmployees;
    } else {
        printf("Danh sach nhan vien da day!\n\n");
        return numEmployees;
    }
}

int removeEmployee(struct Employee employees[], int numEmployees, int removeID) {
    int i, j, found = 0;
    for (i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == removeID) {
            found = 1;
            for (j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("Nhan vien co ID %d da duoc xoa!\n\n", removeID);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien co ID %d.\n\n", removeID);
    }
    return numEmployees;
}

void sortEmployeesByName(struct Employee employees[], int numEmployees) {
    int i, j;
    struct Employee temp;
    for (i = 0; i < numEmployees - 1; i++) {
        for (j = i + 1; j < numEmployees; j++) {
            if (strcmp(employees[i].name, employees[j].name) > 0) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void displayEmployees(struct Employee employees[], int numEmployees, int i) {
    if (numEmployees > 0) {
        printf("Danh sach nhan vien:\n");
        for (i = 0; i < numEmployees; i++) {
            printf("Nhan vien %d:\n", i + 1);
            displayEmployee(employees[i]);
        }
    } else {
        printf("Khong co nhan vien nao trong danh sach!\n\n");
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep danh sach nhan vien theo ten\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numEmployees = addEmployee(employees, numEmployees);
                break;
            case 2:
                if (numEmployees > 0) {
                    int removeID;
                    printf("Nhap ID nhan vien can xoa: ");
                    scanf("%d", &removeID);
                    numEmployees = removeEmployee(employees, numEmployees, removeID);
                } else {
                    printf("Khong co nhan vien nao trong danh sach!\n\n");
                }
                break;
            case 3:
                if (numEmployees > 0) {
                	int i; 
                     printf("Danh sach nhan vien:\n");
                for (i = 0; i < numEmployees; i++) {
                    printf("Nhan vien %d:\n", i + 1);
                    displayEmployee(employees[i]);
            }
                } else {
        printf("Khong co nhan vien nao trong danh sach!\n\n");
    }
    break;
			case 4:
                if (numEmployees > 0) {
                    sortEmployeesByName(employees, numEmployees);
                    printf("Danh sach nhan vien da duoc sap xep theo ten.\n");
                } else {
                    printf("Khong co nhan vien nao trong danh sach!\n\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Chuc nang khong hop le! Vui long chon lai.\n\n");
        }
    } while (choice != 0);

    return 0;
}
