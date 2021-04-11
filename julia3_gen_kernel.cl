__kernel void julia3_gen(__global int *D, __global double *Z_im,__global double *Z_re, __global double *C_im, __global double *C_re, __global int *I)
{
	int			idx = get_global_id(0);
	int			i = 0;
	double		z_im = Z_im[idx];
	double		z_re = Z_re[idx];
	double		mz = 0;
	int			r = 0;
	int			g = 0;
	int			b = 0;
	int			c = 0;
	double		z_i = 0;
	double		z_r = 0;
	double		alph;

	double		alpha;
	while (mz < 4 && i < I[0])
	{
		z_i = z_im;
		z_r = z_re;
		z_im = (3 * z_i * (z_r * z_r)) - (z_i * z_i * z_i);
		z_re = (z_r * z_r * z_r) - (3 * z_r * (z_i * z_i));



		z_im += C_im[0];
		z_re += C_re[0];


		mz = (z_im * z_im) + (z_re * z_re);
		i++;
	}
//	if (i == I[0])
//		D[idx] = 0x000;
//	else
//	{
		r = 10;
		g = 200;
		b = 0;
//		alph = (convert_double(I[0]) / 255);
		alpha = (((convert_double(I[0]) / convert_double(255 - r)) * convert_double(i)));
		r = convert_int(convert_double(r) + alpha);
//		if (convert_int(i % 2) == 1)
//		{
//			g = convert_int(convert_double(255) - alpha);
//			b = convert_int(convert_double(255) - alpha);
//		}
//		else
//		{
//			g = convert_int(alpha);
//			b = convert_int(alpha);
//		}
//		g = convert_int(convert_double(i) * alph);
//		b = convert_int(convert_double(i) * alph);
		alpha = (((convert_double(I[0]) / convert_double(255 - g)) * convert_double(i)));
		g = convert_int(convert_double(g) + alpha);
		alpha = (((convert_double(I[0]) / convert_double(255 - b)) * convert_double(i)));
		b = convert_int(convert_double(b) + alpha);
		if (r > 0)
			c += r * 65536;
		if (g > 0)
			c += g * 256;
		if (b > 0)
			c += b;
		D[idx] = c;
//		gn = (convert_double(0xFFFFFF) / convert_double(25));
//		D[idx] = convert_int(gn * convert_double(i));
//	}
}
