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

static void	log_progress(unsigned int i, const t_gui *gui)
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
	skip = (unsigned int)round(gui->y_size * 0.001);
	printf("\rProgress %7.3lf%%  ", ((double)(i + 1) / gui->y_size) * 100.0);
	fflush(stdout);
}

// Every render of a scene consists of gui->y_size rows
// find_row() is called by any thread that needs a new row to render

static bool	find_row(unsigned int *y, const t_thread *thread)
{
	bool	found_non_rendered_row;

	pthread_mutex_lock(thread->row_to_render_lock);
	if (thread->gui->row_to_render < thread->gui->y_size)
	{
		*y = thread->gui->row_to_render;
		thread->gui->row_to_render++;
		found_non_rendered_row = true;
		if (LOG_PROCESS)
			log_progress(*y, thread->gui);
	}
	else
		found_non_rendered_row = false;
	pthread_mutex_unlock(thread->row_to_render_lock);
	return (found_non_rendered_row);
}

// Render rows until there are none left

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
	t_thread *threads, t_gui *gui, pthread_mutex_t *row_to_render_lock)
{
	size_t	i;

	i = 0;
	while (i < THREADS)
	{
		threads[i].gui = gui;
		threads[i].row_to_render_lock = row_to_render_lock;
		pthread_create(&threads[i].id, NULL, run_thread, (void *)(&threads[i]));
		i++;
	}
}

void	render(t_gui *gui)
{
	t_thread		threads[THREADS];
	size_t			i;
	pthread_mutex_t	row_to_render_lock;

	gui->row_to_render = 0;
	pthread_mutex_init(&row_to_render_lock, NULL);
	start_threads(threads, gui, &row_to_render_lock);
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i].id, NULL);
		i++;
	}
	pthread_mutex_destroy(&row_to_render_lock);
}
