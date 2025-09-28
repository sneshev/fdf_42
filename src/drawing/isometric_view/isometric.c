#include "../../fdf.h"
#include "../drawing.h"

void	draw_top_view(t_data data, t_map *map);

// th in degrees
float	find_x(int x, int y, int z, float th)
{
	(void)z;
	th *= M_PI / 180.0;
	return ((x - y) * cos(th));
}

// th in degrees
float	find_y(int x, int y, int z, float th)
{
	th *= M_PI / 180.0;
	return ((x + y) * sin(th) - z);
}

static void draw_horizontal_lines(t_data data, t_map map, float angle_deg)
{
    int row, col;
    int cd[2], ncd[2];
    unsigned int color[2];

    for (row = 0; row < map.height[REAL]; row++)
    {
        for (col = 0; col < map.width[REAL] - 1; col++)
        {
            // Current point
            float x_proj = find_x(col, row, map.points[row][col].value, angle_deg);
            float y_proj = find_y(col, row, map.points[row][col].value, angle_deg);
            cd[X] = (int)(x_proj);
            cd[Y] = (int)(y_proj);
            color[0] = map.points[row][col].color;

            // Next point in the row
            x_proj = find_x(col + 1, row, map.points[row][col + 1].value, angle_deg);
            y_proj = find_y(col + 1, row, map.points[row][col + 1].value, angle_deg);
            ncd[X] = (int)(x_proj);
            ncd[Y] = (int)(y_proj);
            color[1] = map.points[row][col + 1].color;

            draw_coordinate_line(data, cd, ncd, color);
        }
    }
}

static void draw_vertical_lines(t_data data, t_map map, float angle_deg)
{
    int row, col;
    int cd[2], ncd[2];
    unsigned int color[2];

    for (col = 0; col < map.width[REAL]; col++)
    {
        for (row = 0; row < map.height[REAL] - 1; row++)
        {
            // Current point
            float x_proj = find_x(col, row, map.points[row][col].value, angle_deg);
            float y_proj = find_y(col, row, map.points[row][col].value, angle_deg);
            cd[X] = (int)(x_proj);
            cd[Y] = (int)(y_proj);
            color[0] = map.points[row][col].color;

            // Next point in the column
            x_proj = find_x(col, row + 1, map.points[row + 1][col].value, angle_deg);
            y_proj = find_y(col, row + 1, map.points[row + 1][col].value, angle_deg);
            ncd[X] = (int)(x_proj);
            ncd[Y] = (int)(y_proj);
            color[1] = map.points[row + 1][col].color;

            draw_coordinate_line(data, cd, ncd, color);
        }
    }
}

void	draw_isometric_projection(t_data data, t_map map, t_rotation rot)
{
	t_map	new_map;

	copy_map_values(map, &new_map, FRONT);
	new_map.points = alloc_newmap(&map);
	if (!new_map.points)
	{
		printf("failed to allocate newmap\n");
		return ;
	}
	replace_points(map, &new_map, FRONT);
	draw_horizontal_lines(data, new_map, rot.xt);
	draw_vertical_lines(data, new_map, rot.xt);
	// rotate_points_xyz(&map, rot);
	// draw_top_view(data, &map);
	mlx_put_image_to_window(data.mlxt.mlx, data.mlxt.win, data.mlxt.img, 0, 0);
	free_points(new_map.points, new_map.height[REAL]);
}
