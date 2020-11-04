///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   map_solution.c                                     :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: ychoi <ychoi@student.42seoul.kr>           +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2020/11/02 22:46:14 by scha              #+#    #+#             */
///*   Updated: 2020/11/03 05:53:30 by ychoi            ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "header.h"

//int	**mappuls(int **map)
//{
//	int	col;
//	int	row;
//	int temp;

//	col = 1;
//	row = 1;
//	while (map[col][row])
//	{
//		row = 1;
//		while (map[col][row])
//		{
//			if (map[col][row] == 0)
//				row++;
//			temp = ft_min(map[col][row - 1], map[col - 1][row]);
//			map[row][col] = ft_min(map[col - 1][row - 1], temp) + 1;
//			row++;
//		}
//		col++;
//	}
//	return (map);
//}
