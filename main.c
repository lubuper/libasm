# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	const char *s6 = "Hello from write\n";
	const char *s7 = "Hello from strcpy\n";
	const char *s8 = "Hello from strdup\n";
	int		length = ft_strlen(s1);
	int		result = ft_strcmp(s1, s2);
	int		result2 = ft_strcmp(s1, s3);
	int		result3 = ft_strcmp(s1, s4);
	int		result4 = ft_strcmp(s1, s5);
	char 	*result6 = malloc(sizeof(char) * 18 + 1);
	char	*result7;
	printf(" \033[32m### Testing ###\033[0m\n");
	usleep(1000000);
	// ----------------- ft_strlen ------------------
	printf(" \033[33m		### ft_strlen ###\033[0m\n");
	usleep(100000);
	printf("'Hello' length is: %d\n", length);
	printf("  \033[32m 				ok ✔\033[0m \n");
	// ----------------- ft_strcmp ------------------
	printf(" \033[33m		### ft_strcmp ###\033[0m\n");
	usleep(100000);
	printf("'Hello' vs 'Hello': %d ASCII value difference \033[90msame character\033[0m\n", result);
	printf("'Hello' vs 'Hell': %d ASCII value difference \033[90mo(111) - \\0(0) = 111\033[0m\n", result2);
	printf("'Hello' vs 'Hella': %d ASCII value difference \033[90mo(111) - a(97) = 14\033[0m\n", result3);
	printf("'Hello' vs 'Hellos': %d ASCII value difference \033[90m\\0(0) - s(115) = -115\033[0m\n", result4);
	printf("  \033[32m 				ok ✔\033[0m \n");
	// ----------------- ft_read ------------------
	printf(" \033[33m		### ft_read ###\033[0m\n");
	usleep(100000);
	printf("Enter something: \n");
	char buffer[100];
	ssize_t	sample_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (sample_read == -1)
	{
		perror("\033[31mft_read failed, exiting\033[0m");
		return -1;
	}
	buffer[sample_read] = '\0';
	printf("\033[32mft_read returned %zd bytes: %s\033[0m", sample_read, buffer);
	printf("  \033[32m 				ok ✔\033[0m \n");
	// ----------------- ft_write ------------------
	printf(" \033[33m		### ft_write ###\033[0m\n");
	usleep(100000);
	ssize_t 	result5 = ft_write(1, s6, 18);
	if (result5 == -1) {
		perror("\033[31mft_write failed, exiting\033[0m\n");
		return -1;
	}
	printf("  \033[32m 				ok ✔\033[0m \n");
	// ----------------- ft_strcpy ------------------
	printf(" \033[33m		### ft_strcpy ###\033[0m\n");
	usleep(100000);
	if (!result6)
	{
		perror("\033[31mError in malloc, exiting...\033[0m");
		return -1;
	}
	ft_strcpy(result6, s7);
	printf("%s", result6);
	printf("  \033[32m 				ok ✔\033[0m \n");
	// ----------------- ft_strdup ------------------
	printf(" \033[33m		### ft_strdup ###\033[0m\n");
	usleep(100000);
	result7 = ft_strdup(s8);
	printf("%s", result7);
	printf("  \033[32m 				ok ✔\033[0m \n");

	printf(" \033[32m		### End of Testing ###\033[0m\n");
	free(result6);
	free(result7);
	return 0;
}