LIBFT = ./libft
MINILIBX = ./minilibx_macos
L_O = add_area.o add_engine.o add_event.o add_o.o b_accelerator.o b_accelerator_fun.o b_transform.o burning_ship.o catch_events.o color_generator.o copy_o.o d_accelerator.o drop.o find_place.o free.o ft_k_press.o ft_m_move.o ft_m_press.o ft_m_release.o full_test.o get_area.o get_area_by_point.o get_area_engine.o get_area_engine_k_pr.o get_area_engine_m_mv.o get_area_engine_m_pr.o get_area_engine_m_re.o h_accelerator.o heart.o images_to_window.o init_data.o init_obj.o j3_accelerator.o j_accelerator.o j_accelerator_fun.o j_init_td.o j_transform.o julia.o julia3.o key_press.o lim.o m_accelerator.o m_accelerator_fun.o m_init_td.o m_transform.o main.o make_area.o mandlbrot.o mouse_move.o mouse_press.o mouse_release.o new_image.o on_area.o p_p.o read_kernel.o remake_places.o set_1_init.o src1.o src2.o swap_engines.o t_accelerator.o take_all_selections.o tricon.o zoom_point.o
SRC = add_area.c add_engine.c add_event.c add_o.c b_accelerator.c b_accelerator_fun.c b_transform.c burning_ship.c catch_events.c color_generator.c copy_o.c d_accelerator.c drop.c find_place.c free.c ft_k_press.c ft_m_move.c ft_m_press.c ft_m_release.c full_test.c get_area.c get_area_by_point.c get_area_engine.c get_area_engine_k_pr.c get_area_engine_m_mv.c get_area_engine_m_pr.c get_area_engine_m_re.c h_accelerator.c heart.c images_to_window.c init_data.c init_obj.c j3_accelerator.c j_accelerator.c j_accelerator_fun.c j_init_td.c j_transform.c julia.c julia3.c key_press.c lim.c m_accelerator.c m_accelerator_fun.c m_init_td.c m_transform.c main.c make_area.c mandlbrot.c mouse_move.c mouse_press.c mouse_release.c new_image.c on_area.c p_p.c read_kernel.c remake_places.c set_1_init.c src1.c src2.c swap_engines.c t_accelerator.c take_all_selections.c tricon.c zoom_point.c 
LIB = -lm -L./libft -lft -L$(MINILIBX) -lmlx -framework OpenCL -framework OpenGL -framework AppKit
NAME = fractol
LIB_NAME = libft.a

all : $(NAME)

$(NAME) :
	make -C $(LIBFT)
	make -C $(MINILIBX)
	gcc -c $(SRC)
	gcc -o $(NAME) $(L_O) $(LIB)

clean :
	make clean -C $(LIBFT)
	make clean -C $(MINILIBX)
	rm -f $(L_O)

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re : fclean all
