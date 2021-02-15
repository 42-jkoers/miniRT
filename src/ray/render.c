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

void	render_singlethread(t_gui *gui)
{
	unsigned	x;
	unsigned	y;

	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			gui_set_pixel(gui, x, y, compute_color(x, y, gui));
			x++;
		}
		y++;
	}
}

void	*do_job(void *p)
{
	unsigned	x;
	unsigned	y;
	const t_job	*job = (t_job *)p;

	y = job->start_y;
	while (y < job->start_y + job->num_rows)
	{
		x = 0;
		while (x < job->gui->x_size)
		{
			gui_set_pixel(job->gui, x, y, compute_color(x, y, job->gui));
			x++;
		}
		y++;
	}
	return (NULL);
}

void	define_jobs(t_job *jobs, unsigned n, t_gui *gui)
{
	unsigned		i;
	const unsigned	rows_per_thread = gui->y_size / n;

	i = 0;
	while (i < n)
	{
		jobs[i].tid = 69;
		jobs[i].start_y = rows_per_thread * i;
		jobs[i].num_rows = rows_per_thread;
		if (i == n - 1)
			jobs[i].num_rows += gui->y_size % rows_per_thread;
		jobs[i].gui = gui;
		i++;
	}
}

void	render(t_gui *gui)
{
	t_job	jobs[THREADS];
	size_t	i;

	if (!ENABLE_MULTITHREADING || THREADS >= (unsigned)round(gui->y_size))
		return (render_singlethread(gui));
	define_jobs(jobs, THREADS, gui);
	i = 0;
	while (i < THREADS)
	{
		pthread_create(&jobs[i].tid, NULL, do_job, (void *)(&jobs[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(jobs[i].tid, NULL);
		i++;
	}
}
