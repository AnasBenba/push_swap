#include "ft_printf.h"

int main()
{
	static int i = 0;
	int s = ft_printf("%p\n", &i);
	printf("%d\n", s);
	s = printf("%p\n", &i);
	printf("%d\n", s);
}
