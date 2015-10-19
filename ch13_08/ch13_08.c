#include <stdio.h>

#define MAX_TEXT_LEN 20

typedef struct employee {
    int empNum;
    char name[MAX_TEXT_LEN];
    char phone[MAX_TEXT_LEN];
    int age;
} EMPLOYEE;

int main()
{
    int i;
    EMPLOYEE EmpList[10] = {
        { 0, "�ӻ���", "01011112222", 55 },
        { 1, "���̻�", "01099392373", 49 },
        { 2, "�̺���", "01048387738", 46 },
        { 3, "�ֺ���", "01084783764", 43 },
        { 4, "������", "01078473981", 40 },
        { 5, "������", "01048383737", 36 },
        { 6, "�̰���", "01021833473", 35 },
        { 7, "��븮", "01084884887", 30 },
        { 8, "������", "01028734784", 28 },
        { 9, "�̻��", "01088888888", 26 },
    };

    for (i = 0; i < 10; i++) {
        if (EmpList[i].age >= 20 && EmpList[i].age <= 30) {
            printf("�����ȣ: %d\n", EmpList[i].empNum);
            printf("�̸�: %s\n", EmpList[i].name);
            printf("��ȭ��ȣ: %s\n", EmpList[i].phone);
            printf("����: %d\n\n\n", EmpList[i].age);
        }
    }
    
    return 0;
}

