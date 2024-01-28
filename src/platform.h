#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdbool.h>
#include "post.h"
#include "comment.h"
#include "reply.h"

extern Post globalLastViewedPost;

typedef struct Platform *Platform;
struct Platform 
{
    Post posts;
};


Platform* createPlatform();
void addPost(str username, Sentence caption);
void deletePost(int n);
Post viewPost(int n);
Post currPost();
Post nextPost();
Post previousPost();
bool addComment(str username, Sentence content);
bool deleteComment(int n);
Comment viewComment();

bool addReply(str username, Sentence content, int n); // n adds reply to nth recent comment on last viewed post
bool deleteReply(int n, int m);

// void viewLastPost(Platform *platform);

#endif