#ifndef POST_H
#define POST_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node *Post;
typedef struct Node *Comment;
typedef struct Node *Reply;
struct Node{
    char *Username;
    char *Caption;
    struct Node *parent;
    struct Node *nxtPost;
    struct Node *prevPost;
    struct Node *Reply;
};

Post createPost(char *username, char *caption);
#endif