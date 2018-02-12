// instead of converting the number into binary we can take a xor with like 1101and 0110 and then 1011. 
#include<stdio.h>
/*int dec_to_binary( int x )
{
	int y = 0;
	int z = 1;
	while( x > 0 )
	{
		y = y + ( (x % 2) * z );
		z *= 10;
		x /= 2;
	}
	return y;
}*/
int flip_bit( int y, int p, int n)
{
	return (~(~0 << n)<<p) ^ y;
	
	
}
int main()
{
	int num = 12;
//	int bin = dec_to_binary( num );
	int pos = 2;
	int bit = 2;
	int done = flip_bit( num, pos, bit);
	printf(" %d\n ", done);
	return 0;
}	
