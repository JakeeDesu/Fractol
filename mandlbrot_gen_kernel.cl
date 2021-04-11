__kernel void mandlbrot_gen(__global int *D, __global double *Z_im,__global double *Z_re, __global int *I)
{
	int			idx = get_global_id(0);
	int			i = 0;
	double		z_im = 0;
	double		z_re = 0;
	double		mz = 0;
	int			r = 0;
	int			g = 0;
	int			b = 0;
	int			c = 0;

	double		z_i = 0;
	double		z_r = 0;

	double		alpha;
	while (mz < 4 && i < I[0])
	{
		z_i = z_im;
		z_r = z_re;
		z_im = z_i * z_r * 2;
		z_re = (z_r * z_r) - (z_i * z_i);



		z_im += Z_im[idx];
		z_re += Z_re[idx];


		mz = (z_im * z_im) + (z_re * z_re);
		i++;
	}
	if (i == I[0])
		D[idx] = 0x000;
	else
	{
//		alpha = (((convert_double(I[0]) / convert_double(255)) * convert_double(i)));
//		r = convert_int(convert_double(255) - alpha);
//		g = convert_int(alpha);
//		b = convert_int(alpha);

		r = 126;
		g = 100;
		b = 10;
		alpha = (((convert_double(I[0]) / convert_double(r)) * convert_double(i)));
		r = convert_int(alpha);
		alpha = (((convert_double(I[0]) / convert_double(255 - g)) * convert_double(i)));
		g = convert_int(convert_double(g) + alpha);
		alpha = (((convert_double(I[0]) / convert_double(255 - b)) * convert_double(i)));
		b = convert_int(convert_double(b) + alpha);
		c = 0;
		if (r > 0)
			c += r * 65536;
		if (g > 0)
			 c += g * 256;
		if (b > 0)
			c += b;

		D[idx] = c;
//		lapha = (convert_double(i) / convert_double(I[0]));
//		D[idx] = c;
	//	D[idx] = convert_int(gn * convert_double(i));
	}
}
