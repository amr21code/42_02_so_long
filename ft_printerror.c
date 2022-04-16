/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:32:46 by anruland          #+#    #+#             */
/*   Updated: 2022/04/16 17:33:39 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printerror(char *errormsg)
{
	ft_printf("%s\n", errormsg);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
