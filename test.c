#include <unistd.h>
#include <stdio.h>
void in(char *str)
{
		int i = 0;
	while (str[i] && (str[i] <= 32 || str[i] >= 126))
		i++;
	write (1, &str[i], 1);
}

int main ()
{
	in("   ilyas");
	write (1, "\n", 1);
}