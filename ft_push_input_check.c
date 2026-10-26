/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_input_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:20:41 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/26 17:19:06 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"

unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

int	ft_check_double_flag(int flag_current, int flag_new)
{
	if (flag_current == 0)
		return (flag_new);
	else
		return (-1);
}

int	*set_flags(int ac, char **av)
{
	int		i;
	int		*flags;

	i = 1;
	flags = ft_calloc (3, sizeof(int));
	if (!flags)
		return (NULL);
	while (i < ac)
	{
		if (!ft_strncmp (av[i], "--simple", 8))
			flags[0] = ft_check_double_flag (flags[0], 1);
		if (!ft_strncmp (av[i], "--medium", 8))
			flags[0] = ft_check_double_flag (flags[0], 2);
		if (!ft_strncmp (av[i], "--complex", 9))
			flags[0] = ft_check_double_flag (flags[0], 3);
		if (!ft_strncmp (av[i], "--adaptive", 10))
			flags[0] = ft_check_double_flag (flags[0], 4);
		if (!ft_strncmp (av[i], "--bench", 7))
			flags[1] = ft_check_double_flag (flags[1], 1);
		if (flags[0] < 0 || flags[1] < 0)
			return (NULL);
		i++;
	}
	return (flags);
}

// Función auxiliar para unir todos los argumentos en uno solo
static char *ft_join_args(int ac, char **av)
{
    char    *full_str;
    char    *tmp1;
    char    *tmp2;
    int     i;

    // Empezamos con una "x " falsa para simular av[0]
    full_str = ft_strjoin("x ", av[1]); 
    i = 2;
    while (i < ac)
    {
        tmp1 = ft_strjoin(full_str, " "); // Añadimos un espacio separador
        free(full_str);
        tmp2 = ft_strjoin(tmp1, av[i]);   // Añadimos el siguiente argumento
        free(tmp1);
        full_str = tmp2;                  // Actualizamos el string principal
        i++;
    }
    return (full_str);
}

char    **ft_process_arg(int ac, char **av, int *flags)
{
    int     i;
    char    *full_str;
    char    **output;

    i = 1;
    while (i < ac)
    {
        // Si hay algún espacio en CUALQUIER argumento, unimos y separamos todo
        if (ft_strchr(av[i], ' '))
        {
            full_str = ft_join_args(ac, av);
            flags[2] = word_count(full_str, ' ');
            output = ft_split(full_str, ' ');
            free(full_str);
            return (output);
        }
        i++;
    }
    // Si llegamos aquí, no había espacios. Devolvemos el original.
    flags[2] = ac;
    return (av);
}


/*
char	**ft_process_arg(int ac, char **av, int *flags)
{
	int		i;
	char	**output;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			tmp = ft_strjoin("x ", av[i]);
			flags[2] = word_count (tmp, ' ');
			output = ft_split (tmp, ' ');
			if (flags[2] == 1)
				write (2, "Error\n", 6);
			free (tmp);
			return (output);
		}
		else
			i++;
	}
	flags[2] = ac;
	return (av);
}
*/