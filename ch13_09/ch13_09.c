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
        printf("1. 전화번호 입력\n");
        printf("2. 전화번호 검색\n");
        printf("3. 전화번호 목록 보기\n");
        printf("---------------------\n");
        printf("0. 종료\n");
        printf("메뉴 입력: ");
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
    printf("프로그램을 종료합니다.\n");
}

void add_phoneNum()
{
    int idx = 0;
    if (is_full_directory()) {
        printf("전화번호부가 가득찼습니다.\n");
        return;
    }

    idx = find_empty_phoneNum();
    printf("%d\n", idx);
    
    printf("이름을 입력하세요: ");
    gets(directory[idx].name);

    printf("집전화 번호를 입력하세요: ");
    gets(directory[idx].home);

    printf("휴대전화 번호를 입력하세요: ");
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
    
    printf("찾을 이름을 입력하세요: ");
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
        printf("존재하지 않는 이름입니다.\n");
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
    printf("이름: %s\n", directory[idx].name);
    printf("집전화 번호: %s\n", directory[idx].home);
    printf("휴대전화 번호: %s\n", directory[idx].cellular);
}
