/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _MACRO_H_
#define _MACRO_H_

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

/**
 * container_of - cast a member of a structure out to the containing structure.
 * @ptr: the pointer to the member.
 * @type: the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 */
#define container_of(ptr, type, member) ({              \
    const typeof(((type *)0)->member) *__mptr = (ptr);  \
    (type *)((char *)__mptr - offsetof(type,member));   \
})

#define container_of_safe(ptr, type, member) ({         \
    typeof(ptr) _ptr = (ptr);                           \
    _ptr ? container_of(_ptr, type, member) : NULL;     \
})

#ifndef barrier
# define barrier() __asm__ __volatile__("": : :"memory")
#endif

#endif  /* _MACRO_H_ */