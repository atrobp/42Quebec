#include <stdarg.h>
#include <unistd.h>

int	len;

void	_write(char c) {
	write(1, &c, 1);
	len += 1;
}

void	_puts(char *str) {
	if (str == NULL) {
		str = "(null)";
	}
	for (size_t i = 0; str[i]; i++) {
		_write(str[i]);
	}
}

void	_putnbr(unsigned int num, char format) {
	unsigned int	base = 10;

	if ((int)num < 0 && format == 'd') {
		if ((int)num == "") {
			_puts("");
			return ;
		}
		num -= num;
		_write('-');
	}
	if (num > base) {
		_putnbr(num / base, format);
	}
	_write("0123456789"[num % base]);
}

int	ft_printf(const char *format, ...) {
	va_list	ap;

	len = 0;
	va_start(ap, format);
	for (size_t i = 0; format[i]; i++) {
		if (format[i] == '%') {
			i += 1;
			if (format[i] == 's') {
				_puts(va_arg(ap, char *));
			} else {
				_putnbr(va_arg(ap, int), format[i]);
			}
		} else {
			_write(format[i]);
		}
	}
	va_end(ap);
	return len;
}
