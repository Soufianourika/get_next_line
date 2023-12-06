#include "get_next_line.h"

int main(void)
{
    int fd, i;
    char *res;

    fd = open("text.txt", O_RDONLY);
    i = 0;
    while (i < 15)
    {
        res = get_next_line(fd);
        printf("====================================( main )====================================\n");
        printf("%s", res);
        printf("\n================================================================================\n");
        free(res);
        i++;
    }

   //system("leaks a.out");
    return (0);
}