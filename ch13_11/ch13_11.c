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
        printf("도형의 종류 입력(0:삼각형, 1:사각형, 2:원): ");
        scanf("%d", &(shapes[i].type));

        switch (shapes[i].type) {
        case TRIANGLE:
            printf("삼각형의 밑변과 높이 입력: ");
            scanf("%d %d", &(shapes[i].data.tri.base), &(shapes[i].data.tri.height));

            printf("삼각형의 넓이는 %d입니다.\n", shapes[i].data.tri.base * shapes[i].data.tri.height / 2);
            break;
        case RECTANGLE:
            printf("사각형의 가로와 세로 길이 입력: ");
            scanf("%d %d", &(shapes[i].data.rect.width), &(shapes[i].data.rect.height));

            printf("사각형의 넓이는 %d입니다.\n", shapes[i].data.rect.width * shapes[i].data.rect.height);
            break;
        case CIRCLE:
            printf("원의 반지름 입력: ");
            scanf("%d", &(shapes[i].data.circ.radius));

            printf("원의 넓이는 %lf입니다.\n", 2 * 3.14 * shapes[i].data.circ.radius);
            break;
        default:
            printf("잘못된 입력\n");
            return;
            break;
        }
    }

    return 0;
}
