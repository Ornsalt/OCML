size_t os_strlen(char *str)
{
    size_t len = 0;
    
    if (str)
        while (str[len] != '\0')
            len++;
    return (len)
}

char *os_strcat(char *head, bool freeHead, char *tail, bool freeTail)
{
    char *str = malloc(sizeof(char) * (os_strlen(head) + os_strlen(tail)));
    size_t len = 0;

    if (str) {
        for (len = 0; head[len] != '\0'; len++)
            str[len] = head[len];
        for (size_t i = 0; tail[i] != '\0'; i++)
            str[len+i] = tail[i];
    }
    if (freeHead)
        free(head);
    if (freeTail)
        free(tail);
    return (str);
}

char *os_strcut(char *str, int cut)
{
    char *tail = malloc(sizeof(char) * (os_strlen(str) - cut));
    char *head = malloc(sizeof(char) * cut);

    for (size_t i = 0; str[i+cut] != '\0'; i++)
        tail[i] = str[i+cut];
    for (size_t i = 0; i < cut; i++)
        head[i] = str[i];
    free(str);

}