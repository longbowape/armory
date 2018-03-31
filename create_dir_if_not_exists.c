#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

extern int create_dir_if_not_exists(const char *dir) {
    size_t i, len;
    char dir_path[PATH_MAX];

    len = strlen(dir);
    if (len >= PATH_MAX) {
        return -1;
    }
    strncpy(dir_path, dir, PATH_MAX);
    for (i = 1; i < len; i++) {
        if (dir_path[i] == '/') {
            dir_path[i] = '\0';
            if (access(dir_path, F_OK) == -1) {
                if (mkdir(dir_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
                    return -1;
                }
            }
            dir_path[i] = '/';
        }
    }
    if (access(dir, F_OK) == -1) {
        if (mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
            return -1;
        }
    }
    return 0;
}
