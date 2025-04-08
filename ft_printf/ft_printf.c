/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:40:59 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:53:58 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_print(char specifier_format, va_list args_list);

int	ft_printf(char const *format, ...)
{
	va_list			args_list;
	unsigned int	chars_number;
	unsigned int	index;
	char			specifier_format;

	index = 0;
	chars_number = 0;
	va_start(args_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			specifier_format = format[index + 1];
			chars_number += ft_format_print(specifier_format, args_list);
			index++;
		}
		else
			chars_number += ft_putchar(format[index]);
		index++;
	}
	va_end(args_list);
	return (chars_number);
}

static int	ft_format_print(char sp_format, va_list args_list)
{
	int	chars_number;

	chars_number = 0;
	if (sp_format == 'c')
		chars_number = ft_putchar(va_arg(args_list, int));
	else if (sp_format == 's')
		chars_number = ft_putstr(va_arg(args_list, char *));
	else if (sp_format == 'd' || sp_format == 'i')
		chars_number = ft_putnbr(va_arg(args_list, int));
	else if (sp_format == 'u')
		chars_number = ft_putunsigned(va_arg(args_list, unsigned int));
	else if (sp_format == 'x' || sp_format == 'X')
		chars_number = ft_puthexa(va_arg(args_list, unsigned int), sp_format);
	else if (sp_format == 'p')
		chars_number = ft_putaddress(va_arg(args_list, unsigned long long));
	else if (sp_format == '%')
		chars_number = ft_putchar('%');
	return (chars_number);
}

/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// IMPRIMIR CARACTER CHAR -> especificador de formato %c
	printf("CARACTER CHAR (int) 'c' \n");
	char chr1 = 'a'; 
	int res_printf = printf("%c\n", chr1);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	int	res_ft_printf = ft_printf("%c\n", chr1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// STRINGS CHAR * -> especificador de formato %S
	printf("STRING CHAR* (char *) 's' \n");
	char str1[25];
	res_printf = printf("%s\n", str1);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%s\n", str1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	char str2[] = "Hola";
	res_printf = printf("%s\n", str2);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%s\n", str2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// NUMEROS ENTEROS INT -> especificador de formato %i
	printf("NUMEROS ENTEROS INT (int) 'i' \n");
	int int1 = -12345;
	res_printf = printf("%i\n", int1);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%i\n", int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// NUMEROS DECIMALES -> especificador de formato %d
	printf("NUMEROS DECIMALES (int) 'd' \n");
	int int2 = 5678;
	res_printf = printf("%d\n", int2);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%d\n", int2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// NUMEROS ENTEROS SIN SIGNO 'UNSIGNED INT' -> especificador de formato %u
	printf("NUMEROS ENTEROS SIN SIGNO (unsigned int) 'u' \n");
	unsigned int unsig_int1 = 567845;
	res_printf = printf("%u\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%u\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// NUMEROS EN HEXADECIMAL 'UNSIGNED LONG' -> especificador de formato %X o %x
	printf("NUM HEXADECIMALES (unsigned long) 'x o X' \n");

	unsigned int unsig_int0 = 0;
	res_printf = printf("%x\n", unsig_int0);		
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%x\n", unsig_int0);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_printf);

	unsigned int unsig_int2 = 567845;
	res_printf = printf("%x\n", unsig_int2);		
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%x\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_printf);

	res_printf = printf("%X\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> printf \n", res_ft_printf);
	res_ft_printf = ft_printf("%X\n", unsig_int2);	
	printf("%d numero caract imprimidos -> ft_printf \n\n", res_ft_printf);		

	// DIRECCION PUNTERO EN HEXADECIMAL 'size_t' -> especificador formato %p
	printf("DIRECCION PUNTERO EN FORMATO HEXADECIMAL (size_t) 'p' \n");
	void *ptr_address = NULL;
	res_printf = printf("%p\n", ptr_address);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%p\n", ptr_address);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);
	
	void *ptr_address1 = "Hola";
	res_printf = printf("%p\n", ptr_address1);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%p\n", ptr_address1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", res_ft_printf);

	// DOBLE CARACTER '%' -> especificador de formato %%
	printf("DOBLE CARACTER  (int) '%%' \n");
	char str3[] = "Ho%%la";
	res_printf = printf("%s\n", str3);	
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%s\n", str3);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n",
		 res_ft_printf);	

	// TEST 42 -----------------------------------------------------------

	//TESTEO FUNCION PROTOTIPO PRINTF SIN BANDERAS
	char str[] = "TESTEO FUNCION PROTOTIPO SIN BANDERAS: cspdiuxX";
	res_printf = printf("%s\n", str);
	printf("%d numero caracteres imprimidos -> printf \n", res_printf);
	res_ft_printf = ft_printf("%s\n",str);
	printf("%d numero caracteres imprimidos -> ft_printf \n\n",
		 res_ft_printf);

	// TEST GESTION ERRORES '0, INTmin, str = ' ', ptr = NULL -------------
	printf("TEST ESPECIFICADORES FORMATO MULTIPLES EN ORACION \n");
	char *str_especial = "GESTION ERRORES -> string nulo %s, numero int 0 "
	" %i y %d, numero int minimo %i, numero sin signo 0 %u, numero " 
	" hexadecimal 0 %X y %x, direccion puntero hexadecimal nula %p \n ";

	char *string0 = NULL;
	int num_int0 = 0;
	int num_d0 = 0;
	int num_int_min =  -2147483648;
	unsigned int num_unsignedint0 = 0;
	unsigned int num_hexa0 = 0;
	void *ptr_address_2_0 = NULL;

	res_printf = printf(str_especial, string0, num_int0, num_d0,
		 num_int_min, num_unsignedint0,	num_unsignedint0, num_hexa0,
		 num_hexa0, ptr_address_2_0);		
	printf("%d numero caracteres imprimidos -> printf \n\n", res_printf);
	res_ft_printf = ft_printf(str_especial, string0, num_int0, num_d0,
		 num_int_min, num_unsignedint0,	num_unsignedint0, num_hexa0,
		 num_hexa0, ptr_address_2_0);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n",
		 res_ft_printf);

	// TEST ESPECIFICADORES FORMATO MULTIPLES --------------------------------
	printf("TEST ESPECIFICADORES FORMATO MULTIPLES EN ORACION \n");
	char *str_multiple = "Ho%%la, caracter %c, string %s, "
		" numero int %i y %d, numero sin signo %u, numero "
		" hexadecimal %X y %x, direccion puntero hexadecimal %p \n ";
	
	char character = 'c';
	char *string = "string";
	int num_int = -234;
	unsigned int num_unsignedint = 235;
	unsigned int num_hexa = 23345654;
	void *ptr_address_2 = "Hola";

	res_printf = printf(str_multiple, character, string, num_int, num_int,
		num_unsignedint, num_hexa, num_hexa, ptr_address_2);	
	printf("%d numero caracteres imprimidos -> printf \n\n", res_printf);
	res_ft_printf = ft_printf(str_multiple, character, string, num_int,
		 num_int, num_unsignedint, num_hexa, num_hexa, ptr_address_2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n",
		 res_ft_printf);

	// TEST ESPECIFICADORES INDENTICOS EN SUCESION -----------------------------
	printf("TEST ESPECIFICADORES FORMATO MULTIPLES EN ORACION \n");
	char *str_plus = " caracter1 %c, caracter2 %c \n string1 %s, string2 %s \n "
		" numero int1 %i y %d, numero int2 %i y %d \n numero sin signo 1 %u, "
		" numero sin signo 2 %u \n numero hexadecimal 1 %X y %x, numero "
		" hexadecimal 2 %X y %x \n direccion puntero hexadecimal 1 %p, "
		" direccion puntero hexadecimal 2 %p\n ";
	
	char character1 = 'c';
	char character2 = 'd';
	char *string1 = "string1";
	char *string2= "string2";
	int num_int1 = -234;
	int num_int2 = -567;
	int num_d1 = -234;
	int num_d2 = -567;
	unsigned int num_unsignedint1 = 235;
	unsigned int num_unsignedint2 = 532;
	unsigned int num_hexa1 = 23345654;	
	unsigned int num_hexa2 = 567657567;
	void *ptr_address_3 = "PUNTERO 1";
	void *ptr_address_4 = "PUNTERO 2";

	res_printf = printf(str_plus, character1, character2, string1, 
		string2, num_int1, num_d1, num_int2, num_d2, num_unsignedint1, 
		num_unsignedint2, num_hexa1, num_hexa1, num_hexa2, num_hexa2, 
		ptr_address_3, ptr_address_4);	
	printf("%d numero caracteres imprimidos -> printf \n\n", res_printf);
	res_ft_printf = ft_printf(str_plus, character1, character2, string1, 
		string2, num_int1, num_d1, num_int2, num_d2, num_unsignedint1, 
		num_unsignedint2, num_hexa1, num_hexa1, num_hexa2, num_hexa2, 
		ptr_address_3, ptr_address_4);
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", 
		res_ft_printf);

	// TEST  printfTester ------------------------------------------------------

	printf("TEST  printfTester \n");
	printf("TEST 10 string \n");
	char *str_0 = NULL;
	printf(" NULL %s NULL \n", str_0);
	ft_printf(" NULL %s NULL \n\n", str_0);

	printf("TEST 04 direccion puntero \n");
	printf(" %p \n", (void *)(16));
	ft_printf(" %p \n\n", (void *)(16));

	printf("TEST 09 direccion puntero \n");
	printf(" %p %p \n", (void *)(0), (void *)(0));
	ft_printf(" %p %p \n\n", (void *)(0), (void *)(0));

	printf("TEST 24 num hexadecimal 'x' \n");
	printf(" %x \n", 2147483647);
	ft_printf(" %x \n\n", 2147483647);

	printf("TEST 25 num hexadecimal 'x' \n");
	printf(" %x \n", (unsigned int)-2147483648);
	ft_printf(" %x \n\n", (unsigned int)-2147483648);

	printf("TEST 27 num hexadecimal 'x' \n");
	printf(" %x \n", (unsigned int) 4294967295);
	ft_printf(" %x \n\n", (unsigned int) 4294967295);

	printf("TEST 28 num hexadecimal 'x' \n");
	printf(" %x \n", (unsigned int) 9223372036854775807LL);
	ft_printf(" %x \n\n", (unsigned int) 9223372036854775807LL);

	printf("TEST 24 num hexadecimal 'X' \n");
	printf(" %X \n", 2147483647);
	ft_printf(" %X \n\n", 2147483647);

	printf("TEST 25 num hexadecimal 'X' \n");
	printf(" %X \n", (unsigned int)-2147483648);
	ft_printf(" %X \n\n", (unsigned int)-2147483648);

	printf("TEST 27 num hexadecimal 'X' \n");
	printf(" %X \n", (unsigned int) 4294967295);
	ft_printf(" %X \n\n", (unsigned int) 4294967295);

	printf("TEST 28 num hexadecimal 'X' \n");
	printf(" %X \n", (unsigned int) 9223372036854775807LL);
	ft_printf(" %X \n\n", (unsigned int) 9223372036854775807LL);

	return (0);
} */
