#include "../incs/ft_ls.h"

int main(int argc, char **argv)
{

    (void)argc;
    t_flags f;
    int start;

    init_flags(&f);

    start = parse_flag(&f, argv);
    if (start == -1)
    {
        printf("illegal option\n");
        return (1);
    }
    printf("Flags:\n");
    // printf("l=%d R=%d a=%d r=%d t=%d u=%d f=%d g=%d d=%d G=%d\n",
    //     f.l, f.R, f.a, f.r, f.t, f.u, f.f, f.g, f.d, f.G);

    printf("The flags that were used in the term are %d\n", start);

    printff("the flags that are used are, ");

    printf("First non-flag argument index: %d\n", start);

    return 0;
}