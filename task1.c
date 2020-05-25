#include <stdlib.h>
#include <stdio.h>

size_t get_len(const char *s)
{
	size_t i = 0;

	while (s[i])
		++i;
	return i;
}

char *get_copy(const char *s)
{
	size_t len = get_len(s);
	if (!len)
		return NULL;
	char *new = (char*)malloc(len);
	if (!new)
		return NULL;
	size_t i = 0;
	while (i < len) {
		*(new + i) = *(s + i);
		++i;
	}
	new[i] = '\0';
	return new;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	char *copy = get_copy(argv[1]);
	if (!copy)
		printf("\n");
	else {
		printf("copy: %s\n", copy);
		free(copy);
	}
	return 0;
}
