#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xA, yA, xB, yB, xC, yC, deltaxAB, deltayAB, step, minx, maxx, miny, maxy;
    scanf("%d %d %d %d %d %d", &xA, &yA, &xB, &yB, &xC, &yC);

    deltaxAB = xA - xB;
    deltayAB = yA - yB;

    if (xA < xB)
    {
        minx = xA;
        maxx = xB;
    }
    else
    {
        minx = xB;
        maxx = xA;
    }
    if (yA < yB)
    {
        miny = yA;
        maxy = yB;
    }
    else
    {
        miny = yB;
        maxy = yA;
    }
    // A、B的横纵坐标比大小。

    if (deltaxAB != 0 && deltayAB != 0)
    {
        step = abs(deltaxAB) + abs(deltayAB);
        printf("%d\n", step); //计算并输出步数
        if (yC != yA && xC != xB)
        { //这是先左右走再上下走
            if (deltaxAB < 0)
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("R");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("L");
                }
            }
            if (deltayAB < 0)
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("U");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("D");
                }
            }
        }
        else
        { //这是先上下走再左右走
            if (deltayAB < 0)
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("U");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("D");
                }
            }
            if (deltaxAB < 0)
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("R");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("L");
                }
            }
        }
    }
    //这一大块（34--100行）用来实现当A、B两点既不同行也不同列的情况

    else if (xA == xB)
    { // A、B同列的情况
        if (xC != xA || yC < miny || yC > maxy)
        { // C不在两者之间
            step = abs(deltayAB);
            printf("%d\n", step);
            if (deltayAB < 0)
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("U");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("D");
                }
            }
        }
        else
        { // C在两者之间
            step = abs(deltayAB) + 2;
            printf("%d\n", step);
            printf("R");
            if (deltayAB < 0)
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("U");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltayAB); i++)
                {
                    printf("D");
                }
            }
            printf("L");
        }
    }
    // 103--145行，实现A、B同列的情况

    else if (yA == yB)
    { // A、B同行的情况
        if (yC != yA || xC < minx || xC > maxx)
        { // C不在两者之间
            step = abs(deltaxAB);
            printf("%d\n", step);
            if (deltaxAB < 0)
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("R");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("L");
                }
            }
        }
        else
        { // C在两者之间
            step = abs(deltaxAB) + 2;
            printf("%d\n", step);
            printf("U");
            if (deltaxAB < 0)
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("R");
                }
            }
            else
            {
                for (int i = 0; i < abs(deltaxAB); i++)
                {
                    printf("L");
                }
            }
            printf("D");
        }
    }
    // 148--190行实现A、B同行的情况

    return 0;
}