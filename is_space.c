#include <stdint.h>

extern int is_space(uint32_t c) {
    return (c == ' ') || (c <= 0x000d && c >= 0x0009)
           || (c >= 0x0080 &&
               (c == 0x0085 || c == 0x00a0 || c == 0x1680 || c == 0x180e || (c >= 0x2000 && c <= 0x200a) ||
                c == 0x2028 || c == 0x2029 || c == 0x202f || c == 0x205f || c == 0x3000));
}
