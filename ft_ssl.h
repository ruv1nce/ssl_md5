#ifndef FT_SSL_H
# define FT_SSL_H

# define DGST_COUNT 2
# define BUF_SIZE 64
# define LEN_SIZE 8

# define A new_hash[0]
# define B new_hash[1]
# define C new_hash[2]
# define D new_hash[3]
# define E new_hash[4]
# define F new_hash[5]
# define G new_hash[6]
# define H new_hash[7]

# define LROT(x, c) ((x << c) | (x >> (32 - c)))
# define RROT(x, c) ((x >> c) | (x << (32 - c)))
# define RROT64(x, c) ((x >> c) | (x << (64 - c)))

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "libft/libft.h"

typedef enum	error
{
	no_arg,
	inv_cmd,
	ill_opt,
	no_string,
	bad_read,
}				t_err;

typedef enum	source
{
	std_input,
	string_arg,
	file_arg,
}				t_source;

typedef void	(*t_dgst)(int fd);

typedef struct	s_ssl_options
{
	const char	*cmd;
	t_dgst		dgst;
	uint8_t		p;
	uint8_t		q;
	uint8_t		r;
	uint8_t		ill;
	uint8_t		printed;
	char		*msg;
	uint32_t	msglen;
	uint32_t	lentmp;
	char		*filename;
	t_source	src;
	char		*hash;
}				t_ssl_opt;

void			ssl_perr(const char **cmds, char *arg, t_err err);
void			ssl_parser(int *argc, char **argv, int *i);
void			ssl_iterator(int argc, char **argv);
void			ft_md5(int fd);
void			ft_sha256(int fd);
void			get_block(int fd, uint8_t *buf, uint8_t *pad_done);
void			print_hash();

#endif
