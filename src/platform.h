#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "post.h"
#include "comment.h"


#define GREEN(x) "\033[0;32m" x "\033[0m"
#define RED(x) "\033[0;31m" x "\033[0m"
#define BLACK(x) "\033[0;30m" x "\033[0m"
#define YELLOW(x) "\033[0;33m" x "\033[m"

#define GREEN_BOLD(x) "\033[1;32m" x "\033[0m"
#define RED_BOLD(x) "\033[1;31m" x "\033[0m"
#define BLACK_BOLD(x) "\033[1;30m" x "\033[0m"
#define YELLOW_BOLD(x) "\033[1;33m" x "\033[m"


typedef struct Platform *Platform;

struct Platform {
    Post posts;
    Post lastViewedPost;
};

Platform createPlatform();
bool addPost(Platform platform, char *username, char *caption);
bool deletePost(Platform *platform, int n);
Post viewPost(Platform platform, int n);
Post currPost(Platform platform);
Post nextPost(Platform platform);
Post previousPost(Platform platform);
Comment viewComments(Platform platform);
bool deleteComment(Platform platform, int n);
bool addComment(Platform platform, char *username, char *content);

#endif 