#include <ctype.h>

int is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    for (; *str != '\0'; str++)
    {
        if (!isdigit(*str))
            return 0;
    }

    return 1;
}
