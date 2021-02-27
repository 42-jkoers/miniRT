/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 13:18:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:21:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "gui.h"
#include "constants.h"
#include <pthread.h>
#include <math.h>
#include <stdio.h>

static void	log_progress(size_t i, const t_gui *gui)
{
	static unsigned int	skip = 0;

	if (i + 1 == gui->y_size)
	{
		printf("\rProgress %7.3lf%%  ", 100.0);
		return ;
	}
	if (skip != 0)
	{
		skip--;
		return ;
	}
	skip = (unsigned)round(gui->y_size * 0.001);
	printf("\rProgress %7.3lf%%  ", ((double)(i + 1) / gui->y_size) * 100.0);
	fflush(stdout);
}

static bool	find_row(unsigned int *y, const t_thread *thread)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(thread->row_done_lock);
	while (i < thread->gui->y_size)
	{
		if (thread->gui->row_done[i] == false)
		{
			*y = i;
			thread->gui->row_done[i] = true;
			if (LOG_PROCESS)
				log_progress(i, thread->gui);
			pthread_mutex_unlock(thread->row_done_lock);
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(thread->row_done_lock);
	return (false);
}

static void	*run_thread(void *p)
{
	unsigned int	x;
	unsigned int	y;
	t_thread		*thread;

	thread = (t_thread *)p;
	while (find_row(&y, thread))
	{
		x = 0;
		while (x < thread->gui->x_size)
		{
			gui_set_pixel(thread->gui, x, y, compute_color(x, y, thread->gui));
			x++;
		}
	}
	return (NULL);
}

static void	start_threads(
	t_thread *threads,
	t_gui *gui,
	pthread_mutex_t *row_done_lock)
{
	size_t	i;

	i = 0;
	while (i < THREADS)
	{
		threads[i].gui = gui;
		threads[i].row_done_lock = row_done_lock;
		pthread_create(&threads[i].id, NULL, run_thread, (void *)(&threads[i]));
		i++;
	}
}

void	render(t_gui *gui)
{
	t_thread		threads[THREADS];
	size_t			i;
	pthread_mutex_t	row_done_lock;

	ft_bzero(gui->row_done, gui->y_size * sizeof(bool));
	pthread_mutex_init(&row_done_lock, NULL);
	start_threads(threads, gui, &row_done_lock);
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i].id, NULL);
		i++;
	}
	pthread_mutex_destroy(&row_done_lock);
}
