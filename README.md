# ag_stack
"A Good Stack." A teeny tiny library implementing one or more data structures at my own pace, primarily because I would like get better at C and systems programming in general.
When initializing any data structure, you can provide a unique allocator that is representable as an instance of the `allocator` struct defined in `alloc.h`, including the default allocator exposed in `default_allocator.h` that uses `malloc()` and `free()` from the standard library. Just please make sure that any allocator you use with this doesn't provide 0 as a valid memory address!!! Thanks.
