#include <stdlib.h>
#include <stdio.h>

void func(int level)
{
    if (level > 10)
        return;

    int val = 10;
    printf("[%02d] &val = %pб &level-&val=%ld\n", level, &val, &level - &val);
    func(level+1);
}

int main()
{
    func(0);
    return EXIT_SUCCESS;
}