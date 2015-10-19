#include <stdio.h>

struct shape {
    int type;
    union {
        struct { int base, height; } tri;
        struct { int width, height; } rect;
        struct { int radius; } circ;
    } data;
};

enum shapeType {
    TRIANGLE = 0,
    RECTANGLE = 1,
    CIRCLE = 2
};

int main()
{
    struct shape shapes[3];
    int i;
    for (i = 0; i < 3; i++) {
        printf("������ ���� �Է�(0:�ﰢ��, 1:�簢��, 2:��): ");
        scanf("%d", &(shapes[i].type));

        switch (shapes[i].type) {
        case TRIANGLE:
            printf("�ﰢ���� �غ��� ���� �Է�: ");
            scanf("%d %d", &(shapes[i].data.tri.base), &(shapes[i].data.tri.height));

            printf("�ﰢ���� ���̴� %d�Դϴ�.\n", shapes[i].data.tri.base * shapes[i].data.tri.height / 2);
            break;
        case RECTANGLE:
            printf("�簢���� ���ο� ���� ���� �Է�: ");
            scanf("%d %d", &(shapes[i].data.rect.width), &(shapes[i].data.rect.height));

            printf("�簢���� ���̴� %d�Դϴ�.\n", shapes[i].data.rect.width * shapes[i].data.rect.height);
            break;
        case CIRCLE:
            printf("���� ������ �Է�: ");
            scanf("%d", &(shapes[i].data.circ.radius));

            printf("���� ���̴� %lf�Դϴ�.\n", 2 * 3.14 * shapes[i].data.circ.radius);
            break;
        default:
            printf("�߸��� �Է�\n");
            return;
            break;
        }
    }

    return 0;
}
