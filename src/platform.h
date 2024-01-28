#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "post.h"
#include "comment.h"

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