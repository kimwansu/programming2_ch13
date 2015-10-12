#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point a;
    struct point b;
};

void test_area();
void test_perimeter();
void test_is_square();

struct rectangle input_rectangle();

int area(struct rectangle r);
int perimeter(struct rectangle r);
int is_square(struct rectangle r);

int get_rect_width(struct rectangle r);
int get_rect_height(struct rectangle r);

int main()
{
    test_area();
    test_perimeter();
    test_is_square();

    return 0;
}

void test_area()
{
    struct rectangle r = input_rectangle();
    int a = area(r);
    printf("사각형의 면적은 %d이다.\n", a);
}

void test_perimeter()
{
    struct rectangle r = input_rectangle();
    int p = perimeter(r);
    printf("사각형의 둘레는 %d이다\n", p);
}

void test_is_square()
{
    struct rectangle r = input_rectangle();
    if (is_square(r)) {
        printf("정사각형이다.\n");
    }
    else {
        printf("정사각형이 아니다.\n");
    }
}

struct rectangle input_rectangle()
{
    struct rectangle r;
    printf("왼쪽 아래 좌표 입력(x, y): ");
    scanf("%d %d", &(r.a.x), &(r.a.y));

    printf("오른쪽 위 좌표 입력(x, y): ");
    scanf("%d %d", &(r.b.x), &(r.b.y));

    return r;
}

int area(struct rectangle r)
{
    int width = get_rect_width(r);
    int height = get_rect_height(r);

    return width * height;
}

int perimeter(struct rectangle r)
{
    int width = get_rect_width(r);
    int height = get_rect_height(r);

    return 2 * (width + height);
}

int is_square(struct rectangle r)
{
    int width = get_rect_width(r);
    int height = get_rect_height(r);

    if (width == height)
        return 1;
    else
        return 0;
}

int get_rect_width(struct rectangle r)
{
    return abs(r.a.x - r.b.x);
}

int get_rect_height(struct rectangle r)
{
    return abs(r.a.y - r.b.y);
}


