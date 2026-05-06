#include <stddef.h>

#include "allocator.h"

struct node {
	void *elem;
	struct node *next;
};

struct ag_stack {
	struct node *top;
	size_t size;
	struct allocator a;
};

struct ag_stack *ag_stack_create(struct allocator a)
{
	struct ag_stack *s;

	if (!a.malloc_fn || !a.free_fn)
		return NULL;
	s = a.malloc_fn(a.ctx, sizeof(*s));
	s->top = NULL;
	s->size = 0;
	s->a = a;
	return s;
}

void ag_stack_push(struct ag_stack *s, void *new_elem)
{
	struct node *new_node;

	if (!s || !new_elem)
		return;
	new_node = s->a.malloc_fn(s->a.ctx, sizeof(*new_node));
	new_node->elem = new_elem;
	new_node->next = s->top;
	s->top = new_node;
	s->size++;
}

void *ag_stack_pop(struct ag_stack *s)
{
	struct node *n;
	void *elem;

	if (!s || !s->top)
		return NULL;
	n = s->top;
	elem = n->elem;
	s->top = n->next;
	s->a.free_fn(s->a.ctx, n);
	s->size--;
	return elem;
}

void *ag_stack_peek(const struct ag_stack *s)
{
	if (!s || !s->top)
		return NULL;
	return s->top->elem;
}

size_t ag_stack_size(const struct ag_stack *s)
{
	return s ? s->size : 0;
}

void ag_stack_destroy(struct ag_stack *s)
{
	if (!s)
		return;
	while (s->size > 0)
		ag_stack_pop(s);
	s->a.free_fn(s->a.ctx, s);
}
