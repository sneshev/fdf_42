#include "../fdf.h"

#define R 0 
#define G 1 
#define B 2 

double	find_t(int val, int min, int max)
{
	double	t;

	if (min != max)
		t = (double)(val - min) / (double)(max - min);
	else
		t = 0;
	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	return (t);
}

unsigned int	find_exact_color(double t, unsigned int color_low, unsigned int color_high)
{
	unsigned int	low[3];
	unsigned int	high[3];
	unsigned int	new[3];

    if (t < 0.0)
        t = 0.0;
    else if (t > 1.0)
	{
        t = 1.0;
	}

	low[R] = (color_low >> 16) & 0xFF;
	low[G] = (color_low >> 8) & 0xFF;
	low[B] = color_low & 0xFF;
	high[R] = (color_high >> 16) & 0xFF;
	high[G] = (color_high >> 8) & 0xFF;
	high[B] = color_high & 0xFF;
	new[R] = (unsigned int)((1.0 - t) * low[R] + (0.0 + t) * high[R]);
	new[G] = (unsigned int)((1.0 - t) * low[G] + (0.0 + t) * high[G]);
	new[B] = (unsigned int)((1.0 - t) * low[B] + (0.0 + t) * high[B]);
	return ((new[R] << 16) | (new[G] << 8) | new[B]);
}
