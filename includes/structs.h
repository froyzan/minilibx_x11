#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_vars {
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_image {
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_icoord {
	int				x;
	int				y;
}					t_icoord;

typedef struct		s_coord {
	double			x;
	double			y;
}					t_coord;

typedef struct		s_dblcolor {
	double			r;
	double			g;
	double			b;
}					t_dblcolor;

typedef struct		s_color {
	int				a;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_wall
{
	int				color;
	int				tex_x;
	int				tex_y;
	double			step;
	double			texpos;
}					t_wall;

typedef struct		s_floor
{
	t_image			*img;
	float			stepx;
	float			stepy;
	double			dist;
	int				p;
	int				color;
}					t_floor;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			spritex;
	double			spritey;
	double			transformx;
	double			transformy;
	int				texture;
	int				hit;
	int				spritescreenx;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
}					t_sprite;

typedef struct		s_spr_cast
{
	t_sprite		*curr;
	t_image			*img;
	t_icoord		tex;
	double			dist;
}					t_spr_cast;

typedef struct		s_frame {
	t_coord			raydir;
	t_coord			line;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				raytex;
	double			wallx;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}					t_frame;

typedef struct		s_map {
	int				*s_order;
	char			**tab;
	char			**tmp;
	double			*s_dist;
	t_icoord		size;
	t_icoord		start;
	t_sprite		*sprite;
	int				n_sprite;
}					t_map;

typedef struct		s_params {
	t_vars			vars;
	t_map			map;
	t_image			img;
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			west;
	t_image			walltex;
	t_image			sprite;
	t_color			floor;
	t_color			ceil;
	t_dblcolor		shadecol;
	t_coord			dir;
	t_coord			pos;
	t_coord			plane;
	int				local_endian;
	int				move;
	int				w;
	int				h;
	double			shadedist;
	double			sinr;
	double			sinmr;
	double			cosr;
	double			cosmr;
	double			movespeed;
	int				parser;
	int				captureframe;
	int				*mapwidth;
	int				*mapheight;
	double			*zbuffer;
	char			*spritebuffer;
}					t_params;

typedef struct		s_bitmap
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixeldataoffset;
	unsigned int	headersize;
	unsigned int	imagewidth;
	unsigned int	imageheight;
	unsigned short	planes;
	unsigned short	bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}					t_bitmap;
#endif
