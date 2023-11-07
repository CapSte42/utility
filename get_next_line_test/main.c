#include "get_next_line_bonus.h"
#include <stdio.h>

void	print_hex(char *str)
{
	while (*str)
	{
		printf("%02hhx ", *str);
		str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		fds[argc - 1];
	char	*line;
	int		i;

	if (argc < 2)
	{
		printf("Uso: %s <file1> [<file2> ...]\n", argv[0]);
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		fds[i - 1] = open(argv[i], O_RDONLY);
		if (fds[i - 1] == -1)
		{
			perror("Errore nell'apertura del file");
			return (2);
		}
	}
	for (i = 0; i < argc - 1; i++)
	{
		printf("=== Contenuto del file: %s ===\n", argv[i + 1]);
		while ((line = get_next_line(fds[i])) != NULL)
		{
			print_hex(line);
			free(line);
		}
		printf("\n\n");
		if (close(fds[i]) == -1)
		{
			perror("Errore nella chiusura del file");
			return (3);
		}
	}
	return (0);
}
