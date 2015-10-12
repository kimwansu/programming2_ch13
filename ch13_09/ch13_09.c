#include <stdio.h>

#define MAX_NAME_LEN 40
#define MAX_PHONE_LEN 15
#define MAX_DIRECTORY_LEN 5

struct TelephoneDirectory {
    char name[MAX_NAME_LEN];
    char home[MAX_PHONE_LEN];
    char cellular[MAX_PHONE_LEN];
};

struct TelephoneDirectory directory[MAX_DIRECTORY_LEN];

void menu();
void add_phoneNum();
int find_empty_phoneNum();
int is_full_directory();
void find_phoneNum();
void print_directory();
void print_contract(int idx);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int m = 1;
    while (m > 0) {
        printf("1. ��ȭ��ȣ �Է�\n");
        printf("2. ��ȭ��ȣ �˻�\n");
        printf("3. ��ȭ��ȣ ��� ����\n");
        printf("---------------------\n");
        printf("0. ����\n");
        printf("�޴� �Է�: ");
        scanf("%d", &m);
        fflush(stdin);

        switch (m) {
        case 1:
            add_phoneNum();
            break;
        case 2:
            find_phoneNum();
            break;
        case 3:
            print_directory();
            break;
        default:
            m = 0;
            continue;
        }
    }
    printf("���α׷��� �����մϴ�.\n");
}

void add_phoneNum()
{
    int idx = 0;
    if (is_full_directory()) {
        printf("��ȭ��ȣ�ΰ� ����á���ϴ�.\n");
        return;
    }

    idx = find_empty_phoneNum();
    printf("%d\n", idx);
    
    printf("�̸��� �Է��ϼ���: ");
    gets(directory[idx].name);

    printf("����ȭ ��ȣ�� �Է��ϼ���: ");
    gets(directory[idx].home);

    printf("�޴���ȭ ��ȣ�� �Է��ϼ���: ");
    gets(directory[idx].cellular);
}

int find_empty_phoneNum()
{
    int i = 0;
    int found = -1;
    for (i = 0; i < MAX_DIRECTORY_LEN; i++) {
        if (directory[i].name[0] == NULL) {
            found = i;
            break;
        }
    }

    return found;
}

int is_full_directory()
{
    if (find_empty_phoneNum == -1)
        return 1;
    else
        return 0;
}

void find_phoneNum()
{
    int i = 0;
    char name[MAX_NAME_LEN];
    
    printf("ã�� �̸��� �Է��ϼ���: ");
    gets(name);

    for (i = 0; i < MAX_DIRECTORY_LEN; i++) {
        if (directory[i].name[0] == NULL)
            continue;

        if (strcmp(name, directory[i].name) == 0) {
            printf("----------------------------------------\n");
            print_contract(i);
            printf("----------------------------------------\n");
            break;
        }
    }
    
    if (i == MAX_DIRECTORY_LEN) {
        printf("�������� �ʴ� �̸��Դϴ�.\n");
    }
}

void print_directory()
{
    int i = 0;
    printf("----------------------------------------\n");
    for (i = 0; i < MAX_DIRECTORY_LEN; i++) {
        if (directory[i].name[0] == NULL)
            continue;

        print_contract(i);
        printf("----------------------------------------\n");
    }
}

void print_contract(int idx)
{
    printf("�̸�: %s\n", directory[idx].name);
    printf("����ȭ ��ȣ: %s\n", directory[idx].home);
    printf("�޴���ȭ ��ȣ: %s\n", directory[idx].cellular);
}
