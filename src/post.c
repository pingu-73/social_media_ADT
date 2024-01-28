#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "post.h"


Post createPost(char *username, char *caption)
{
    Post pst = (Post)malloc(sizeof(struct Node));
    assert(pst != NULL);

    pst->Username = (char *)malloc(strlen(username) + 1);
    assert(pst->Username != NULL);

    strcpy(pst->Username, username);

    pst->Caption = (char *)malloc(strlen(caption) + 1);
    assert(pst->Caption != NULL);
    strcpy(pst->Caption, caption);

    pst->parent = NULL;
    pst->nxtPost = NULL;
    pst->prevPost = NULL;
    pst->Reply = NULL;

    return pst;
}