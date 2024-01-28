#include "comment.h"

Comment createComment(char *username, char *caption)
{
    Comment cmt = (Comment)malloc(sizeof(struct Node));
    assert(cmt != NULL);

    cmt->Username = (char *)malloc(strlen(username) + 1);
    assert(cmt->Username != NULL);

    strcpy(cmt->Username, username);

    cmt->Caption = (char *)malloc(strlen(caption) + 1);
    assert(cmt->Caption != NULL);
    strcpy(cmt->Caption, caption);

    cmt->nxtPost = NULL;
    cmt->prevPost = NULL;
    cmt->Reply = NULL;

    return cmt;
}