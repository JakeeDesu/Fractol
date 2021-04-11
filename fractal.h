/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:17:18 by hmhindat          #+#    #+#             */
/*   Updated: 2021/04/11 18:22:19 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FRACTAL_H
# define H_FRACTAL_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# include "libft/libft.h"
# include "src.h"
# include "data.h"
# define MAX_SOURCE_SIZE 0x100000

enum			e_event
{
	k_re = 3, k_pr = 2, m_re = 5, m_pr = 4, m_mv = 6
};

typedef enum		e_type
{
	k_press = 1, m_move = 2, m_press = 3, m_release = 4
}					t_type;

typedef struct	s_m
{
	void			*x_m;
	unsigned int	size;
	int				*data;
	int				bpp;
	int				line;
	int				endi;
}				t_m;

typedef struct	s_o
{
	t_m				*m;
	void			*data;
	int				h;
	int				w;
	double			pas;
	int				id;
	t_point			posi;
	t_point			cursor;
	t_lim			s_ox;
	t_lim			s_oy;
	int				active;
	int				selected;
	int				holded;
	struct s_o		*next;
}				t_o;

typedef void	(*t_f_eng)(t_o*);
typedef void	(*t_f_ev)(t_o*, int, int, t_point);
typedef void	(*t_f_m_mv)(t_o*, int, int, t_point);
typedef void	(*t_f_m_pr)(t_o*, int, int, t_point);
typedef void	(*t_f_m_re)(t_o*, int, int, t_point);
typedef void	(*t_f_k_pr)(t_o*, int, int, t_point);

typedef struct	s_engine
{
	int				a_id;
	t_f_eng			f;
	void			*data;
	t_f_m_mv		m_mv;
	t_f_m_pr		m_pr;
	t_f_m_re		m_re;
	t_f_k_pr		k_pr;
	struct s_engine	*next;
}				t_engine;

typedef struct	s_obj
{
	int				cnt;
	void			*x_p;
	void			*x_w;
	t_o				*objs;
	t_engine		*engines;
	t_area			main_s;
	t_area			available;
	t_point			s2_size;
}				t_obj;

typedef struct	s_td
{
	t_o				*o;
	int				*data;
	int				td_line;
	int				i_start;
	double			pas;
	t_lim			ox;
	t_lim			oy;
	long long		iter;
	t_complex		test;
	int				size;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	t_point			min;
	t_point			max;
	t_complex		c;
	t_complex		z;
}				t_td;

void			free_obj(t_obj *obj);
cl_program		read_kernel(char *name, cl_context *context);
void			mandlbrot(t_o *o);
void			burning_ship(t_o *o);
void			drop(t_o *o);
void			tricorn(t_o *o);
void			heart(t_o *o);
void			m_transform(t_o *o);
void			b_transform(t_o *o);
void			*set_1_init(t_o *o);
void			zoom_point(t_o *o, t_point p);
void			ft_m_press(t_o *o, int id, int button, t_point point);
void			ft_m_release(t_o *o, int id, int button, t_point point);
void			ft_m_move(t_o *o, int id, int button, t_point point);
void			ft_k_press(t_o *o, int id, int key, t_point point);
int				get_mandlbrot_p(t_complex c, long long iter);
void			m_accelerator(t_complex z, t_o *o);
void			b_accelerator(t_complex z, t_o *o);
void			d_accelerator(t_complex z, t_o *o);
void			t_accelerator(t_complex z, t_o *o);
void			h_accelerator(t_complex z, t_o *o);
void			m_threads(t_complex c, t_o *o);
t_td			m_init_td(t_complex c, t_o *o);
void			julia(t_o *o);
void			julia3(t_o *o);
void			j_transform(t_o *o);
int				get_julia_p(t_complex z, t_complex c, long long iter);
void			j_threads(t_complex c, t_complex z, t_o *o);
void			j_accelerator(t_complex c, t_complex z, t_o *o);
void			j3_accelerator(t_complex c, t_complex z, t_o *o);
cl_mem			*creat_mem(cl_context *c, t_o *o);
cl_mem			*m_creat_mem(cl_context *c, t_o *o);
cl_mem			*b_creat_mem(cl_context *c, t_o *o);
void			cpm(cl_command_queue *c_q, cl_mem *m_o, t_o *o, t_complex *cz);
void			mcpm(cl_command_queue *c_q, cl_mem *m_o, t_o *o, t_complex z);
void			bcpm(cl_command_queue *c_q, cl_mem *m_o, t_o *o, t_complex z);
t_td			j_init_td(t_complex c, t_complex z, t_o *o);
t_o				*add_o(t_obj *obj);
t_engine		*add_engine(t_obj *obj, t_f_eng f, int a_id);
void			init_data(t_engine *eng, t_o *o, t_sets data_set);
int				make_area(t_obj *obj, int h, int w, t_point posi);
void			init_obj(t_obj *obj, t_f_eng f);
void			images_to_window(t_obj *obj);
t_f_eng			get_area_engine(t_engine *engines, t_o *o);
t_f_m_mv		get_area_engine_m_mv(t_engine *engines, t_o *o);
t_f_m_pr		get_area_engine_m_pr(t_engine *engines, t_o *o);
t_f_m_re		get_area_engine_m_re(t_engine *engines, t_o *o);
t_f_k_pr		get_area_engine_k_pr(t_engine *engines, t_o *o);
t_o				*get_area(t_o *objs, int id);
t_o				*get_area_by_point(t_o *objs, t_point point);
void			swap_engines(t_o *o, t_o *o2);
void			take_all_selections(t_o *objs);
void			images_to_window(t_obj *obj);
void			new_image(t_obj *obj, t_o *o);
int				add_area(t_obj *obj, t_f_eng f);
int				find_place(t_obj *obj, t_point *posi, t_point *size);
void			copy_o(t_o *o, t_o *o2);
int				remake_places(t_obj *obj);
int				full_test(t_point posi, t_point size);
void			next_place(t_point *posi, t_point size);
void			catch_events(t_obj *obj);
int				mouse_move(int x, int y, t_obj *obj);
int				mouse_press(int button, int x, int y, t_obj *obj);
int				mouse_release(int button, int x, int y, t_obj *obj);
int				key_press(int key_code, t_obj *obj);
void			add_event(t_engine *eng, t_f_ev f_event, t_type type);

#endif
