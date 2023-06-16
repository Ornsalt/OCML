#include "osl.h"

size_t getfileSize(char *path)
{
    struct stat buffer = NULL;

    stat(path, &buffer);
    return (buffer ? buffer.st_size : -1);
}


char *readFile(char *path)
{
    size_t size = getfileSize(path);
    char *buffer = (size > 0) ? malloc(size * sizeof(char)) : NULL;
    int fd = open(path, O_RDONLY);
    
    if (fd != -1) {
        if (buffer)
            if (read(fd, buffer, size) == -1)
                free(buffer);
        close(fd); 
    }
    return (buffer);
}

char *getNextLine(int fd, size_t size)
{
    static char *buffer = "";
    static size_t len = 0;
    char tmp[size] = "";
    bool find = false;
    
    while (!find && read(fd, tmp, size) > 0) {
        buffer = os_strcat(buffer, true, tmp, false);
        for (size_t i = 0; !find && i < size; i++)
            if (buffer[i] == '\n')
                find = true;
    }
    // cut str at the '\n'
    //
    return (NULL); 
}