/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:39:59 by clados-s          #+#    #+#             */
/*   Updated: 2025/09/30 16:01:48 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	// 1. Inicia a conexão com o servidor gráfico. Essencial.
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
	{
		printf("Erro: mlx_init() falhou. Verifique a sua conexão com o servidor gráfico.\n");
		return (1); // Se falhar, não podemos continuar.
	}

	// 2. Cria uma nova janela com um tamanho e título.
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "FdF");
	if (vars.win == NULL)
	{
		// Se a criação da janela falhar, temos de limpar a conexão já estabelecida.
		printf("Erro: mlx_new_window() falhou.\n");
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}

	// 3. Associa a nossa função `key_hook` ao evento de pressionar uma tecla.
	// O &vars é o ponteiro que a nossa função hook receberá como argumento.
	mlx_key_hook(vars.win, key_hook, &vars);

	// 4. Inicia o loop de eventos da mlx.
	// O programa ficará "preso" aqui, à espera de eventos (teclado, rato, etc.).
	mlx_loop(vars.mlx);

	return (0);
}	