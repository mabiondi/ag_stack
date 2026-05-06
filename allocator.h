#pragma once

#include <stddef.h>

struct allocator {
	void *(*malloc_fn)(void *, size_t);
	void (*free_fn)(void *, void *);
	void *ctx;
};
