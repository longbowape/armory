#ifndef ARMORY_H
#define ARMORY_H

#include <stdint.h>

extern int create_dir_if_not_exists(const char *dir);

extern int is_space(uint32_t c);

extern int make_nonblocking(int fd);

#endif
