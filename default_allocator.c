#include <stdlib.h>

void *stdlib_malloc(void *ctx, size_t size)
{
        (void)ctx;
        return malloc(size);
}

void stdlib_free(void *ctx, void *allocation)
{
        (void)ctx;
        free(allocation);
}
