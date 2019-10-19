#include "./../../ft.hpp"
#include "./../../deps/catch2/single_include/catch2/catch.hpp"
#include "./../test.hpp"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

static char     buf[512];

static void     *(*volatile pmemcpy)(void *, const void *, size_t);

static void     *aligned(void *p) {
	return (void*)(((uintptr_t)p + 63) & -64);
}

#define N 80
static          void test_align(int dalign, int salign, int len)
{
	char *src = (char*) aligned(buf);
	char *dst = (char *) aligned(buf + 128);
	char *want = (char *) aligned(buf + 256);
	char *p;
	int i;

	if (salign + len > N || dalign + len > N)
		abort();
	for (i = 0; i < N; i++) {
		src[i] = '#';
		dst[i] = want[i] = ' ';
	}
	for (i = 0; i < len; i++)
		src[salign+i] = want[dalign+i] = '0'+i;
	p = (char*) pmemcpy(dst+dalign, src+salign, len);
	if (p != dst+dalign)
		t_error("memcpy(%p,...) returned %p\n", dst+dalign, p);
	for (i = 0; i < N; i++)
		if (dst[i] != want[i]) {
			t_error("memcpy(align %d, align %d, %d) failed\n", dalign, salign, len);
			t_printf("got : %.*s\n", dalign+len+1, dst);
			t_printf("want: %.*s\n", dalign+len+1, want);
			break;
		}
}

TEST_CASE( "ft_memcpy") {
    	int i,j,k;

	pmemcpy = ft_memcpy;
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
			for (k = 0; k < 64; k++)
				test_align(i,j,k);
    REQUIRE( t_status == 0 ); 
	t_status = 0;
}