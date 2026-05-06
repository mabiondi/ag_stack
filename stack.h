#pragma once

#include <stddef.h>

#include "allocator.h"

struct ag_stack;

struct ag_stack	*	ag_stack_create(struct allocator a);
void			ag_stack_destroy(struct ag_stack *s);

void			ag_stack_push(struct ag_stack *s, void *elem);
void *			ag_stack_pop(struct ag_stack *s);
void *			ag_stack_peek(const struct ag_stack *s);
size_t			ag_stack_size(const struct ag_stack *s);
