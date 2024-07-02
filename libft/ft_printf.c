/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:03:51 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/28 16:08:33 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is the primary function file for my ft_printf.

	My ft_printf.c with a prototype "int	ft_printf(const char *format, ...)"
	is	a variadic function, that is, it accepts a variable	number arguments 
	that is denoted by the ellipses "..." in the protoype.
	A struct 't_check' was declared in my header file, "ft_printf.h" in the 
	format:
	
	typedef struct s_check
	{
	int	error;
	int	count;
	}				t_check;
	
	This provides the a means to 
	1.	check for errors and return(ends the program).
	2.	counts and logs each variable that is being written.
	note: it is imperative this struct would be applied to all functions and 
	processes of the ft_printf function.
	
	My ft_printf is declared with a return type of 'int' to indicate the
	number of characters succesfully written to the standard output/printed
	as 'return(audit.count)'.
	If an error occurs during printing, a negative value is returned.
	This is done via the struct 't_check' that was earlier declared.

	The variable 'char *format' reperesents the format flags (cspdiuxX%) that
	tells the program what type of variable its writing to the standard output.

	To begin, we would need the standard C library 'stdarg.h' which was included
	in header file ft_printf.h. This would allow us to make use of the variardic
	functions.
	The following variardic functions (macros): va_start, va_arg, and va_end.
	The va_start() macro must be called first and We would also need to declare
	the argument pointer 'va_list' as a parameter to these macros. This is 
	declared as 'arg_pnt'(argument pointer).
	And this 'arg_pnt' is passed to va_arg() for each argument to be processed.
	
	Struct 't_check' is declared as 'audit' and the variables, error and count
	within are initalised to '0'.
	Calling va_end within the same function is imperative as it signals the
	end of the program.
	
	We start the macros 'va_start' with the parameter declared via 'va_list' 
	and using format: va_start(arg_pnt, format) which is utilised for 'va_arg'.
	In the primary ft_printf function, the method used after all of the above
	is done is to create a while loop that behavesin a way to check for the 
	modulo '%' if not found then performs other required tasks. If the 
	modulo is found, then the format flags are checked for.
	To check for the format flags, a static helper function 'ft_format_check'
	is made.
	ft_format_check directs the program to its expected helper function via
	the conditional statements checking the format flags.
	A special case for the helper function 'print_hexadecimal', should have its 
	va_arg parameter as unsigned int, for some reason unsigned long breaks.	*/

#include "libft.h"

static void	ft_format_check(va_list arg_pnt, char format, t_check *audit)
{
	if (format == 'c')
		print_char_fd(va_arg(arg_pnt, int), audit);
	else if (format == '%')
		print_char_fd('%', audit);
	else if (format == 's')
		print_str_fd(va_arg(arg_pnt, char *), audit);
	else if (format == 'd' || format == 'i')
		print_nbr_fd(va_arg(arg_pnt, int), audit);
	else if (format == 'u')
		print_unsign_fd(va_arg(arg_pnt, unsigned int), audit);
	else if (format == 'x' || format == 'X')
		print_hexadecimal(va_arg(arg_pnt, unsigned int), audit, format);
	else if (format == 'p')
		print_pointer_hex(va_arg(arg_pnt, unsigned long), audit);
	else
	{
		print_char_fd('%', audit);
		print_char_fd(format, audit);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_pnt;
	t_check	audit;

	audit.error = 0;
	audit.count = 0;
	va_start(arg_pnt, format);
	while (*format && audit.error == 0)
	{
		if (*format == '%')
		{
			format++;
			ft_format_check(arg_pnt, *format, &audit);
		}
		else if (*format != '\0')
			print_char_fd(*format, &audit);
		if (*format != '\0')
			format++;
	}
	va_end(arg_pnt);
	if (audit.error < 0)
		return (-1);
	return (audit.count);
}
