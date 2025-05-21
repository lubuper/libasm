# include <stdio.h>

extern int ft_strcmp(const char *s1, const char*s2);
extern int ft_strlen(const char *s1);

int main(void) {
	const char *s1 = "Hello";
	const char *s2 = "Hello";
	const char *s3 = "Hell";
	const char *s4 = "Hella";
	const char *s5 = "Hellos"; 
	int			ft_strlen(s1);
	int			result = ft_strcmp(s1, s2);
	int			result2 = ft_strcmp(s1, s3);
	int			result3 = ft_strcmp(s1, s4);
	int			result4 = ft_strcmp(s1, s5);

	printf("'Hello' length is: %d\n", length);
	printf("'Hello' vs 'Hello': %d\n", result);
	printf("'Hello' vs 'Hell': %d\n", result2);
	printf("'Hello' vs 'Hella': %d\n", result3);
	printf("'Hello' vs 'Hellos': %d\n", result4);
	return 0;
}