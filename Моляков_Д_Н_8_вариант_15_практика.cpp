#include <stdio.h>
#include <iostream>

int main(void)
{
    setlocale(LC_ALL, "Russian");
    FILE* fIn = NULL;
    fIn = fopen("1234.txt", "r");
    int iCountStart = 0, iCountEnd = 0;
    char ch;
    if (fIn == NULL) return 1;
    while ((ch = fgetc(fIn)) != EOF)
    {
        if (ch == '{') iCountStart++;
        if (ch == '}') iCountEnd++;
    }
    if (iCountStart == iCountEnd)
        printf("Количество открывающихся и закрывающихся скобок равны\n");
    else
        printf("Числа открывающихся и закрывающихся скобок %s", iCountStart == iCountEnd ? "равны" : "не равны");
    return 0;
}