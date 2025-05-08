# include <stdio.h>
# include "libasm.h"

int main(void) {
	char *str = "Testing a string.";
	char *buffer[50];

	printf("Length of str: %zu\n", ft_strlen(str));
	ft_strcpy(buffer, str);
	printf("copied str: %s\n", buffer);
	printf("String comparison: %d\n", ft_strcmp(str, buffer));
	// how to test ft_read and ft_write?

	return 0;
}