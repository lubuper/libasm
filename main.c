# include <stdio.h>
# include <stdlib.h>

extern int ft_strcmp(const char *s1, const char*s2);
extern int ft_strlen(const char *s1);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strcpy(char *dest, const char *src);
extern char *ft_strdup(const char *s);

int main(void) {
	const char *s1 = "Hello";
	const char *s2 = "Hello";
	const char *s3 = "Hell";
	const char *s4 = "Hella";
	const char *s5 = "Hellos";
	const char *s6 = "Hello from write";
	const char *s7 = "Hello from strcpy";
	const char *s8 = "Hello from strdup";
	int		length = ft_strlen(s1);
	int		result = ft_strcmp(s1, s2);
	int		result2 = ft_strcmp(s1, s3);
	int		result3 = ft_strcmp(s1, s4);
	int		result4 = ft_strcmp(s1, s5);
	char 	*result6 = malloc(sizeof(char) * 17 + 1);
	char	*result7;

	printf(" \033[33m### Testing ft_strlen ###\033[0m\n");
	printf("'Hello' length is: %d\n", length);
	printf(" ### ---- ###\n");

	printf(" ### \033[33mTesting ft_strcmp ###\033[0m\n");
	printf("'Hello' vs 'Hello': %d\n", result);
	printf("'Hello' vs 'Hell': %d\n", result2);
	printf("'Hello' vs 'Hella': %d\n", result3);
	printf("'Hello' vs 'Hellos': %d\n", result4);
	printf(" ### ---- ###\n");

	printf(" ### \033[33mTesting ft_read ###\033[0m\n");
	char buffer[100];
	printf("Enter something: ");
	ssize_t	sample_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (sample_read == -1)
	{
		perror("\033[31mft_read failed, exiting\033[0m");
		return -1;
	}
	buffer[sample_read] = '\0';
	printf("\033[32mft_read returned %zd bytes: '%s'\033[0m\n", sample_read, buffer);
	printf(" ### ---- ###\n");

	printf(" ### \033[33mTesting ft_write ###\033[0m\n");
	ssize_t 	result5 = ft_write(1, s6, 17);
	if (result5 == -1) {
		perror("\033[31mft_write failed, exiting\033[0m");
		return -1;
	}
	printf(" ### ---- ###\n");

	printf(" \033[33m### Testing ft_strcpy ###\033[0m\n");
	if (!result6)
	{
		perror("\033[31mError in malloc, exiting...\033[0m");
		return -1;
	}
	ft_strcpy(result6, s7);
	printf("%s", result6);
	printf(" ### ---- ###\n");

	printf(" ### \033[33mTesting ft_strdup ###\033[0m\n");
	result7 = ft_strdup(s8);
	printf(" ### ---- ###\n");

	printf(" ### \033[33mEnd of Testing ###\033[0m\n");
	free(result6);
	//free(result7);
	return 0;
}