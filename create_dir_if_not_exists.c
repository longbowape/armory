#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

extern int create_dir_if_not_exists(const char *dir) {
    char *dirc = strdup(dir);
    if (dirc == NULL) {
        return -1;
    }
    char *dname = dirname(dirc);
    if (access(dname, F_OK) == -1) {
        if (create_dir_if_not_exists(dname) == -1) {
            free(dirc);
            return -1;
        }
    }
    free(dirc);
    if (access(dir, F_OK) == -1) {
        if (mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
            return -1;
        }
    }
    return 0;
}
