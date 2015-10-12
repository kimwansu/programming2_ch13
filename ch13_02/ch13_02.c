#include <stdio.h>

struct point {
    int x;
    int y;
};

void test_equal();
void test_quadrant();

struct point input_point();

int equal(struct point *p1, struct point *p2);
int quadrant(struct point *p);

int main()
{
    test_equal();
    test_quadrant();

    return 0;
}

void test_equal()
{
    struct point p1;
    struct point p2;

    printf("p1 ��ǥ �Է�(x, y): ");
    p1 = input_point();

    printf("p2 ��ǥ �Է�(x, y): ");
    p2 = input_point();

    if (equal(&p1, &p2)) {
        printf("�� ��ǥ�� ����.\n");
    }
    else {
        printf("�� ��ǥ�� �ٸ���\n");
    }
}

void test_quadrant()
{
    struct point p;
    int q;

    printf("��ǥ �Է�(x, y): ");
    p = input_point();
    q = quadrant(&p);

    if (q > 0) {
        printf("%d��и鿡 �ִ� ��ǥ\n", q);
    }
    else {
        printf("x�� �Ǵ� y��� �ִ� ��ǥ\n");
    }
}

struct point input_point()
{
    struct point p;
    scanf("%d %d", &(p.x), &(p.y));

    return p;
}

int equal(struct point *p1, struct point *p2)
{
    if (p1->x == p2->x && p1->y == p2->y)
        return 1;
    else
        return 0;
}

int quadrant(struct point *p)
{
    if (p->x > 0) {
        if (p->y > 0)
            return 1;
        else if (p->y < 0)
            return 4;
        else
            return 0;
    }
    else if (p->x < 0) {
        if (p->y > 0)
            return 2;
        else if (p->y < 0)
            return 3;
        else
            return 0;
    }
    else {
        return 0;
    }
}

