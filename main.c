#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbytes);
ssize_t	ft_read(int fildes, void *buf, size_t nbytes);
char	*ft_strdup(const char *s1);

int		main(void)
{
	printf("-----------------------------\n");
	printf("        ft_strlen check\n");
	printf("-----------------------------\n\n");

	char	*test1 = "catdogooo and dogocat\n";
	char	*test2 = "";

	printf("libasm - reference\n");
	printf("%6d   %9d\n", ft_strlen(test1), (int)strlen(test1));
	printf("%6d   %9d\n\n", ft_strlen(test2), (int)strlen(test2));

	// printf("-----------------------------\n");
	// printf("             end\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("        ft_stcpy check\n");
	printf("-----------------------------\n\n");

	char	*test = "catdogo";
	char	*res;
	char	*test_ref = "catdogo";
	char	*res_ref;

	if (!(res = malloc(sizeof(char) * (strlen(test) + 1))))
		return (0);
	if (!(res_ref = malloc(sizeof(char) * (strlen(test_ref) + 1))))
		return (0);
	res = ft_strcpy(res, test);
	res_ref = strcpy(res_ref, test_ref);
	printf("%s|\n", res);
	printf("%s| - reference\n\n", res_ref);
	res = ft_strcpy(res, "");
	res_ref = strcpy(res_ref, "");
	printf("%s|\n", res);
	printf("%s| - reference\n\n", res_ref);
	
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("        ft_stcmp check\n");
	printf("-----------------------------\n\n");

	char	*s1 = "catdag";
	char	*s2 = "Catdog";
	char	*s3 = "CuteDog";
	char	*s4 = "catdogoooo";

	printf("libasm - reference\n");
	printf("%6d   %9d\n", ft_strcmp(s1, s1), strcmp(s1, s1));
	printf("%6d   %9d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%6d   %9d\n", ft_strcmp(s3, s2), strcmp(s3, s2));
	printf("%6d   %9d\n\n", ft_strcmp(s1, s4), strcmp(s1, s4));

	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("        ft_write check\n");
	printf("-----------------------------\n\n");

	int	fd;
	int	ress;
	
	// all valid
	errno = 0;
	if ((fd = open("test.txt", O_WRONLY)) < 0)
		return (0);
	printf ("fd: %d - libasm\n", fd);
	ress = ft_write(fd, "catdogo", 7);
	if (errno != 0)
		printf("Error: %d\n", errno);
	else
		printf("%d - result\n", ress);
	close(fd);
	if ((fd = open("test_ref.txt", O_WRONLY)) < 0)
		return (0);
	printf ("fd: %d - reference\n", fd);	
	ress = write(fd, "catdogo", 7);
	if (errno != 0)
		printf("Error: %d\n\n", errno);
	else
		printf("%d - result reference\n\n", ress);
	close(fd);
	
	// all valid
	errno = 0;
	fd = 1;
	printf("fd: %d\n", fd);
	ress = ft_write(fd, "catdog", 3);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d - result\n", ress);
		
	ress = write(fd, "catdog", 3);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d - result\n\n", ress);
	
	// invalid fd
	errno = 0;
	fd = -2345;
	printf("fd: %d\n", fd);
	ress = ft_write(fd, "catdogo", 7);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d - result\n", ress);
		
	ress = write(fd, "catdogo", 7);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d - result\n\n", ress);
	if ((fd = open("test.txt", O_WRONLY)) < 0)
		return (0);
	
	// invalid buffer
	errno = 0;
	fd = 1;
	printf("fd: %d, invalid buf\n", fd);
	ress = ft_write(fd, NULL, 7);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d - result\n", ress);
		
	ress = write(fd, NULL, 7);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d - result\n\n", ress);

	// invalid nbytes
	errno = 0;
	fd = 1;
	printf("fd: %d, invalid nbytes\n", fd);
	ress = ft_write(fd, "catdog", -1);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d - result\n", ress);
		
	ress = write(fd, "catdog", -1);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d - result\n\n", ress);
	
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("        ft_read check\n");
	printf("-----------------------------\n\n");

	char	buf[100];
	char	buf_ref[100];
	int		result;
	int		result_ref;

	// all valid
	errno = 0;
	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - libasm\n", fd);
	result = ft_read(fd, buf, 10);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d: %s|\n",result, buf);
	result = ft_read(fd, buf, 10);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d: %s|\n\n",result, buf);
	close(fd);
	if ((fd = open("test_ref.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - reference\n", fd);
	result_ref = read(fd, buf_ref, 10);
	if (errno != 0)
		printf("Error %d - reference\n", errno);
	else
		printf("%d: %s| - reference\n",result_ref, buf_ref);
	result_ref = read(fd, buf_ref, 10);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d: %s| - reference\n\n",result_ref, buf_ref);
	close(fd);
	
	// invalid fd
	errno = 0;
	fd = -12345;
	printf ("fd: %d\n", fd);
	result = ft_read(fd, buf, 10);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d: %s|\n",result, buf);
	result_ref = read(fd, buf_ref, 10);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d: %s| - reference\n\n",result_ref, buf_ref);

	// invalid buf
	errno = 0;
	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - libasm, invalid buf\n", fd);
	result = ft_read(fd, NULL, 10);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d: %s|\n",result, buf);
	close(fd);
	if ((fd = open("test_ref.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - reference, invalid buf\n", fd);
	result_ref = read(fd, NULL, 10);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d: %s| - reference\n\n",result_ref, buf_ref);
	close(fd);
	
	// invalid nbytes
	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - libasm, invalid nbytes\n", fd);
	result = ft_read(fd, buf, -34);
	if (errno != 0)
		printf("Error %d\n", errno);
	else
		printf("%d: %s|\n",result, buf);
	close(fd);
	if ((fd = open("test_ref.txt", O_RDONLY)) < 0)
		return (0);
	printf ("fd: %d - reference, invalid nbytes\n", fd);
	result_ref = read(fd, buf_ref, -34);
	if (errno != 0)
		printf("Error %d - reference\n\n", errno);
	else
		printf("%d: %s| - reference\n\n",result_ref, buf_ref);
	close(fd);
	
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("        ft_strdup check\n");
	printf("-----------------------------\n\n");
	
	char	*new_str;
	char	*new_str_ref;
	char	*old_str = "catdogo";

	if ((new_str = ft_strdup(old_str)) != NULL)
		printf("%s|\n", new_str);
	if ((new_str_ref = strdup(old_str)) != NULL)
		printf("%s| - reference\n\n", new_str_ref);
	if ((new_str = ft_strdup("")) != NULL)
		printf("%s|\n", new_str);
	if ((new_str_ref = strdup("")) != NULL)
		printf("%s| - reference\n", new_str_ref);
	
	printf("-----------------------------\n");
	return (0);
}
