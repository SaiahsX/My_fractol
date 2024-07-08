/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:10:01 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/08 13:04:03 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_set_double(char *str)
{
	double	output;
	double	denom;

	output = 0.0;
	denom = 1.0;
	while (*str != '.' && ft_isdigit((unsigned char)*str) && *str != '\0')
	{
		output *= 10.0;
		output += (*str++ - '0');
	}
	if (*str == '.')
	{
		str ++;
		while (ft_isdigit((unsigned char)*str) && *str != '\0')
		{
			denom *= 10.0;
			output = output + (*str++ - '0') / denom;
		}
	}
	if (*str && !ft_isdigit((unsigned char)*str))
		return (NAN);
	return (output);
}

// Reasoning Behind output != output Check for NaN:
// NaN Properties: According to the IEEE 754 floating-point standard 
// (used by most modern CPUs), NaN is the only floating-point value that is 
// not equal to itself. This means: If output is NaN, then output != output
// evaluates to true.
// ****
// If output is a numeric value (including positive and negative infinity),
// then output != output evaluates to false.
// Portability and Standard Compliance: The expression output != output is 
// a standard and portable way to check for NaN across different platforms 
// and compilers. It ensures compatibility with the IEEE 754 standard 
// without relying on implementation-specific behaviors.
// ****
// Readability and Intent: Using output != output clearly expresses the
// intent of checking for NaN. It is a recognized idiom in the C/C++
// community and makes the code more understandable for someone familiar 
// with the language conventions.
double	ft_atod(char *str)
{
	double	output;
	int		indx;
	int		polarity;

	output = 0;
	indx = 0;
	polarity = 1;
	if (str[indx] == '-' || str[indx] == '+')
	{
		if (str[indx] == '-')
			polarity *= -1;
		indx++;
	}
	output = ft_set_double(str + indx);
	if (output != output)
		return (output);
	return (output * polarity);
}

//Using similar format as above for output != output to check for NaN,
//x and y are checked against the NaN floating point value if ft_atod fails.
//The parameter range is also checked to ensure that they are between -2.0
//and 2.0 range for both parameter inputs
static void	validate_julia(char *argv[])
{
	double	x;
	double	y;

	x = ft_atod(argv[2]);
	y = ft_atod(argv[3]);
	if (x != x || y != y)
		error_message("Invalid argument detected", \
		"expected format: ./fractol julia <-2.0> <2.0>");
	else if (x < -2.0 || x > 2.0 || y < -2.0 || y > 2.0)
		error_message("Invalid julia parameter range/type detected", \
		"expected range: <-2.0> to <2.0>");
	return ;
}

//The function below is to check if the inputs are valid
//the perror function bellow is to be tested later.
//perror("Insufficient/Invalid arguments!")
void	validate_input(int argc, char *argv[])
{
	if (argc < 2 || argv[1][0] == '\0')
		error_message("Insufficient/Invalid arguments! \
		\nTry ./fractol mandelbrot or ./fractol julia -0.1 0.651", 0);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		if (argc > 2)
			error_message("Too many arguments!", \
			"correct format is: ./fractol mandelbrot");
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			error_message("Invalid argument count detected", \
			"expected format: ./fractol julia <-0.75> <0.11>");
		else
			validate_julia(argv);
	}
	else
		error_message("Invalid fractol name!", \
		"Available options: mandelbrot or julia");
}

// s_col = start colour, e_col = end colour
// intrplt = interpolate
unsigned int	intrplt(double t, unsigned int s_col, unsigned int e_col)
{
	t_interp		colours;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	colours.start_r = (s_col >> 16) & 0xFF;
	colours.start_g = (s_col >> 8) & 0xFF;
	colours.start_b = s_col & 0xFF;
	colours.end_r = (e_col >> 16) & 0xFF;
	colours.end_g = (e_col >> 8) & 0xFF;
	colours.end_b = e_col & 0xFF;
	r = (unsigned char)((1 - t) * colours.start_r + t * colours.end_r);
	g = (unsigned char)((1 - t) * colours.start_g + t * colours.end_g);
	b = (unsigned char)((1 - t) * colours.start_b + t * colours.end_b);
	return ((r << 16) | (g << 8) | b);
}
