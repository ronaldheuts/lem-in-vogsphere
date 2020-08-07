/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 15:40:37 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:15:29 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define BUFFER_SIZE 4096
# define FLOATSTR_SIZE 10000
# define FRACTIONAL_64 64
# define DECIMAL_POINT 1

typedef va_list		t_hacknor;
typedef	union		u_floatunion
{
	long double		value;
	struct			s_bits
	{
		u_int64_t	fractional;
		u_int16_t	exponent:15;
		u_int16_t	sign:1;
	}				t_bits;
}					t_floatunion;
typedef	struct		s_floatstruct
{
	char			*bin_integral;
	char			*dec_integral;
	char			*bin_fractional;
	char			*dec_fractional;
	int32_t			exponent;
	size_t			bin_ilen;
	size_t			dec_ilen;
	size_t			bin_flen;
	size_t			dec_flen;
}					t_floatstruct;
typedef	struct		s_format
{
	char			buffer[BUFFER_SIZE];
	char			*str;
	size_t			size;
	size_t			index;
	size_t			total;
	char			hash_flag;
	char			zero_flag;
	char			minus_flag;
	char			blank_flag;
	char			plus_flag;
	int				min_width;
	int				max_width;
	int				len;
	char			sign;
	char			minus_sign;
	char			precision;
	char			prefix;
	char			colour;
	char			spec;
	int				length_spec;
	int				fd;
}					t_format;
typedef void		(*t_ptrfun)(t_hacknor, t_format *);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_snprintf(char *str, size_t size,
					const char *format, ...);
void				ft_printf_end_of_format(t_format *node);
void				ft_printf_reset_node(t_format *node);
void				ft_printf_ini_fun(t_ptrfun fun_array[57]);
void				ft_printf_ini_node(int fd, t_format *node);
int					ft_printf_isflag(const char format, t_format *node);
int					ft_printf_isconversion(const char spec, t_format *node);
void				ft_printf_buffer_character(const unsigned char c,
					t_format *node);
void				ft_printf_buffer_string(const char *s, int len,
					t_format *node);
void				ft_printf_buffer_prefix(t_format *node);
void				ft_printf_buffer_minusflag(t_format *node);
void				ft_printf_buffer_minussign(t_format *node);
void				ft_printf_buffer_plussign(t_format *node);
void				ft_printf_buffer_blankspace(t_format *node);
void				ft_printf_buffer_maxwidth(t_format *node);
void				ft_printf_buffer_minwidth(t_format *node);
int					ft_printf_buffer_flags(t_format *node);
void				ft_printf_length_di(int64_t *num, t_hacknor ap,
					t_format *node);
void				ft_printf_length_ouxx(u_int64_t *num, t_hacknor ap,
					t_format *node);
void				ft_printf_length_f(long double *num, t_hacknor ap,
					t_format *node);
void				ft_printf_len_sign(int64_t num, t_format *node);
void				ft_printf_len_prefix(t_format *node);
void				ft_printf_len_base(int64_t num, int base, t_format *node);
void				ft_printf_len_base_unsigned(u_int64_t num, int base,
					t_format *node);
void				ft_printf_lltoa_sign(int64_t num, t_format *node);
int					ft_printf_lltoa_base(int64_t num, int64_t base,
					int ulcase, t_format *node);
int					ft_printf_lltoa_base_unsigned(u_int64_t num, u_int64_t base,
					int ulcase, t_format *node);
void				ft_printf_floattoa(long double num, t_format *node);
void				ft_printf_state_base(const char **format, t_hacknor ap,
					t_ptrfun *fun_array, t_format *node);
void				ft_printf_state_flags(const char **format, t_format *node);
void				ft_printf_state_minwidth(const char **format,
					t_format *node);
void				ft_printf_state_precision(const char **format,
					t_format *node);
void				ft_printf_state_length(const char **format, t_format *node);
void				ft_printf_state_spec(const char **format, t_hacknor ap,
					t_ptrfun *fun_array, t_format *node);
void				ft_printf_state_colour(const char **format, t_format *node);
int					ft_printf_colour_list(const char *str, t_format *node);
void				ft_printf_character(t_hacknor ap, t_format *node);
void				ft_printf_string(t_hacknor ap, t_format *node);
void				ft_printf_pointer(t_hacknor ap, t_format *node);
void				ft_printf_decimal(t_hacknor ap, t_format *node);
void				ft_printf_octal(t_hacknor ap, t_format *node);
void				ft_printf_unsigned(t_hacknor ap, t_format *node);
void				ft_printf_hexadecimal(t_hacknor ap, t_format *node);
void				ft_printf_hexadecimal_uppercase(t_hacknor ap,
					t_format *node);
void				ft_printf_float(t_hacknor ap, t_format *node);
void				ft_printf_percent(t_format *node);
char				*ft_printf_newzerostring(size_t size);
void				ft_printf_decimaltobinarystring(t_floatstruct **f,
					u_int64_t number);
void				ft_printf_stringmultiplication(t_floatstruct **f, char add);
void				ft_printf_binaryintegraltoa(t_floatstruct **f);
void				ft_printf_stringdivision(t_floatstruct **f, char add,
					size_t numofdiv);
void				ft_printf_integraladdition(t_floatstruct **f);
void				ft_printf_fractionaladdition(t_floatstruct **f,
					uint16_t len);
void				ft_printf_binaryfractionaltoa(t_floatstruct **f);
void				ft_printf_bitswap(char *a, char *b);
void				ft_printf_bitmoveright(t_floatstruct **f);
void				ft_printf_bitmoveleft(t_floatstruct **f);
void				ft_printf_bitmove(t_floatstruct **f);
size_t				ft_printf_binarystringlen(char *fractional);
void				ft_printf_newfloatstruct(uint16_t exponent, size_t size,
					t_floatstruct **f);
void				ft_printf_freefloatstruct(t_floatstruct **f);
int					ft_printf_isfloatexception(uint16_t sign, uint16_t exponent,
					u_int64_t fractional, t_format *node);
void				ft_printf_rounding(t_floatstruct **f, t_format *node);
void				ft_printf_decintegraltrim(t_floatstruct **f);
void				ft_printf_decfractionaltrim(t_floatstruct **f,
					t_format *node);
void				ft_printf_dectrim(t_floatstruct **f, t_format *node);
void				ft_printf_buffer_blankspace_min(t_format *node);

#endif
