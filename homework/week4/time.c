#include <stdio.h>

int main()
{
    int day, year, hour, minute, second;
    char month[10], week[10];

    scanf("%s %d %d %s %d %d %d", month, &day, &year, week, &hour, &minute, &second);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", week, month, day, hour, minute, second, year);

    return 0;
}