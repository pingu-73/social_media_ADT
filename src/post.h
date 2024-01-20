#ifndef POST_H
#define POST_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char *String;
typedef char **Sentence;

typedef struct Post *Post;
typedef Post Comment;


struct Post{
    String Username;
    Sentence Caption;
    struct Post *nxtPost;
    struct Post *prevPost;
    Comment pComment;
};

Post createPost();
void add_post(String name, Sentence com);
void delete_post();
void view_post();
void Print_post();

#endif