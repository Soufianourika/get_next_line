/*#include "get_next_line.h"


// Define color codes for printing
#define COLOR_RESET "\033[0m"
#define COLOR_ALLOC "\033[1;32m"  // Green color for allocation
#define COLOR_FREE "\033[1;31m"   // Red color for freeing

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;

    i = 0;
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL)
    {
        printf(COLOR_ALLOC "[DEBUG] Allocating memory for ft_substr failed\n" COLOR_RESET);
        free(str);
        return (NULL);
    }
    while (s[start] != '\0' && i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    printf(COLOR_ALLOC "[DEBUG] Allocated memory for ft_substr: %p\n" COLOR_RESET, (void *)str);
    return (str);
}

char *helper(char **st_buff, int j, char **rest)
{
    char *save;

    save = ft_strdup((*st_buff));
    (*rest) = ft_substr(*st_buff , 0, j + 1);
    free((*st_buff));
    (*st_buff) = ft_strdup(save + j + 1);
    free(save);
    printf(COLOR_FREE "[DEBUG] Freed memory in helper: %p\n" COLOR_RESET, (void *)(*st_buff));
    return ((*rest));
}

char *while_loop(char *st_buff, char *buff, int fd, char *join_str)
{
    int j;
    ssize_t bytread;

    bytread = read(fd, buff, BUFFER_SIZE);
    while (bytread > 0)
    {
        j = 0;
        buff[bytread] = '\0';
        st_buff = ft_strjoin(st_buff, buff);
        while (st_buff[j] != '\0')
        {
            if (st_buff[j] == '\n')
                return (helper(&st_buff, j, &join_str));
            j++;
        }
        bytread = read(fd, buff, BUFFER_SIZE);
    }
    if (bytread == 0 && st_buff && st_buff[0] != '\0')
        return (ft_strdup(st_buff));
    else
        return (NULL);
}

char *get_next_line(int fd)
{
    char *buff;
    char *join_str;
    static char *st_buff;
    char *result;

    join_str = NULL;
    if (fd < 0 || fd > 1024)
        return (NULL);
    if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buff == NULL)
    {
        printf(COLOR_ALLOC "[DEBUG] Allocating memory for buff failed\n" COLOR_RESET);
        return (NULL);
    }
    printf(COLOR_ALLOC "[DEBUG] Allocated memory for buff: %p\n" COLOR_RESET, (void *)buff);
    result = while_loop(st_buff, buff, fd, join_str);
    free(st_buff);
    free(buff);
    buff = NULL;
    free(join_str);
    printf(COLOR_FREE "[DEBUG] Freed memory in get_next_line: %p\n" COLOR_RESET, (void *)st_buff);
    printf(COLOR_FREE "[DEBUG] Freed memory in get_next_line: %p\n" COLOR_RESET, (void *)buff);
    printf(COLOR_FREE "[DEBUG] Freed memory in get_next_line: %p\n" COLOR_RESET, (void *)join_str);
    printf(COLOR_ALLOC "[DEBUG] Allocated memory in get_next_line: %p\n" COLOR_RESET, (void *)result);
    return (result);
}

int main(void)
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    system("leaks a.out");
    close(fd);
    return (0);
}*/