/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:49:35 by jserpa-p          #+#    #+#             */
/*   Updated: 2022/02/14 16:15:34 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	argument_checker(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Error: no map");
	if (argc > 2)
		ft_error("Error: too many arguments");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Error: incorrect extension");
	}
	else
		ft_error("Error: incorrect extension");
}

int	main(int argc, char **argv)
{
	argument_checker(argc, argv);
	so_long(argv[1]);
	return (0);
}
