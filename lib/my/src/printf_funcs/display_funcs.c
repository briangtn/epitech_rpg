/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** Function for all specific display
*/

#include "my.h"

int display_uint_base(unsigned int nb, char const *base, int fake)
{
	unsigned int base_len = my_strlen(base);
	int disp = 0;

	if (nb / base_len != 0)
		disp += display_uint_base(nb / base_len, base, fake);
	my_putchar_cond(base[nb % base_len], fake);
	disp += 1;
	return (disp);
}

int display_int_base(int nb, char const *base, int fake)
{
	int base_len = my_strlen(base);
	int disp = 0;

	if (nb < 0) {
		if (nb / base_len != 0)
			disp += display_int_base(-(nb / base_len), base, fake);
	}
	else {
		if (nb / base_len != 0)
			disp += display_int_base(nb / base_len, base, fake);
	}
	if (nb == -2147483648)
		nb = nb + base_len;
	if (nb < 0)
		nb = nb * -1;
	my_putchar_cond(base[nb % base_len], fake);
	disp += 1;
	return (disp);
}

int display_long_base(long nb, char const *base, int fake)
{
	long base_len = my_strlen(base);
	int disp = 0;

	if (nb < 0) {
		my_putchar_cond('-', fake);
		disp += 1;
		if (nb / base_len != 0)
			disp += display_long_base(-(nb / base_len), base, fake);
	}
	else {
		if (nb / base_len != 0)
			disp += display_long_base(nb / base_len, base, fake);
	}
	if (nb == -2147483648)
		nb = nb + base_len;
	if (nb < 0)
		nb = nb * -1;
	my_putchar_cond(base[nb % base_len], fake);
	disp += 1;
	return (disp);
}

void put_zero(int *disp, int fake)
{
	my_putchar_cond('0', fake);
	*disp += 1;
}

int display_str_show(char *str, int fake)
{
	int disp = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 32 || str[i] > 126) {
			my_putchar_cond('\\', fake);
			disp += 1;
			if (str[i] < 8)
				put_zero(&disp, fake);
			if (str[i] < 16)
				put_zero(&disp, fake);
			disp += display_int_base(str[i], "01234567", fake);
		}
		else {
			my_putchar_cond(str[i], fake);
			disp += 1;
		}
	}
	return (disp);
}