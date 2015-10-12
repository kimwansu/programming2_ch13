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

    printf("p1 좌표 입력(x, y): ");
    p1 = input_point();

    printf("p2 좌표 입력(x, y): ");
    p2 = input_point();

    if (equal(&p1, &p2)) {
        printf("두 좌표는 같다.\n");
    }
    else {
        printf("두 좌표는 다르다\n");
    }
}

void test_quadrant()
{
    struct point p;
    int q;

    printf("좌표 입력(x, y): ");
    p = input_point();
    q = quadrant(&p);

    if (q > 0) {
        printf("%d사분면에 있는 좌표\n", q);
    }
    else {
        printf("x축 또는 y축상에 있는 좌표\n");
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

