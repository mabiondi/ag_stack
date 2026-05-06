#pragma once

void *stdlib_malloc(void *ctx, size_t size);

void stdlib_free(void *ctx, void *allocation);

struct allocator default_allocator = {
        &stdlib_malloc,
        &stdlib_free,
        NULL,
};
