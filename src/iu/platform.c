#include "platform.h"
#include <stdlib.h>
#include <stdio.h>


Platform createPlatform()
{
    Platform platform = (Platform)malloc(sizeof(Platform));
    if (platform == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for platform.\n");
        exit(EXIT_FAILURE);
    }
    platform->posts = NULL;
    platform->lastViewedPost = NULL;
    return platform;
}


bool addPost(Platform platform, char *username, char *caption)
{
    if (username == NULL || caption == NULL) {
        fprintf(stderr, "Error: Invalid input parameters.\n");
        return false;
    }

    Post newPost = createPost(username, caption);
    if (newPost == NULL) {
        fprintf(stderr, "Error: Failed to create a new post.\n");
        return false;
    }

    
    newPost->nxtPost = platform->posts;
    if (platform->posts != NULL) {
        platform->posts->prevPost = newPost;
    }
    platform->posts = newPost;

    
    if (platform->lastViewedPost == NULL) {
        platform->lastViewedPost = newPost;
    }
    return true;
}


bool deletePost(Platform *platform, int n) {
    if (platform == NULL || *platform == NULL || n <= 0) {
        fprintf(stderr, "Error: Invalid input parameters.\n");
        return false;
    }

    Post current = (*platform)->posts;
    int count = 0;
    while (current != NULL && count < n - 1) {
        current = current->nxtPost;
        count++;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: No such post found.\n");
        return false;
    }

    if (current->prevPost != NULL) {
        current->prevPost->nxtPost = current->nxtPost;
    } else {

        (*platform)->posts = current->nxtPost;
    }
    if (current->nxtPost != NULL) {
        current->nxtPost->prevPost = current->prevPost;
    }

    // clearCommentsAndReplies(current);

    // freePost(current);

    return true;
}

Post viewPost(Platform platform, int n) {
    if (platform == NULL || n <= 0) {
        fprintf(stderr, "Error: Invalid input parameters.\n");
        return NULL;
    }

    Post current = platform->posts;
    int count = 0;
    while (current != NULL && count < n - 1) {
        current = current->nxtPost;
        count++;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: No such post found.\n");
        return NULL;
    }
    return current;
}

Post currPost(Platform platform) {
    if (platform == NULL) {
        fprintf(stderr, "Error: Platform is not initialized.\n");
        return NULL;
    }
    return platform->lastViewedPost;
}

Post nextPost(Platform platform) {
    if (platform == NULL || platform->lastViewedPost == NULL) {
        fprintf(stderr, "Error: Platform is not initialized or lastViewedPost is NULL.\n");
        return NULL;
    }

    Post current = platform->posts;
    if (current == platform->lastViewedPost) {
        return current;
    }

    while (current != NULL && current->nxtPost != platform->lastViewedPost) {
        current = current->nxtPost;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: Unable to find the next post.\n");
        return NULL;
    }

    return current;
}


Post previousPost(Platform platform) {
    if (platform == NULL || platform->lastViewedPost == NULL) {
        fprintf(stderr, "Error: Platform is not initialized or lastViewedPost is NULL.\n");
        return NULL;
    }

    Post current = platform->posts;


    if (current->prevPost == NULL) {
        return platform->lastViewedPost;
    }

    while (current != NULL && current->prevPost != platform->lastViewedPost) {
        current = current->nxtPost;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: Unable to find the previous post.\n");
        return NULL;
    }

    return current;
}


bool addComment(Platform platform, char *username, char *content) {
    if (username == NULL || content == NULL) {
        fprintf(stderr, "Error: Invalid input parameters.\n");
        return false;
    }

    if (platform == NULL || platform->lastViewedPost == NULL) {
        fprintf(stderr, "Error: No post has been viewed yet.\n");
        return false;
    }

    Comment newComment = createComment(username, content);
    if (newComment == NULL) {
        fprintf(stderr, "Error: Failed to create a new comment.\n");
        return false;
    }


    Comment currentComment = (platform->lastViewedPost)->Reply;
    if (currentComment == NULL) {
        
        (platform->lastViewedPost)->Reply = newComment;
    } else {
        
        while (currentComment->nxtPost != NULL) {
            currentComment = currentComment->nxtPost;
        }
        currentComment->nxtPost = newComment;
    }

    return true;
}


bool deleteComment(Platform platform, int n) {
    if (platform == NULL || platform->lastViewedPost == NULL || (platform->lastViewedPost)->Reply == NULL) {
        fprintf(stderr, "Error: No comments to delete.\n");
        return false;
    }

    Comment currentComment = (platform->lastViewedPost)->Reply;
    Comment prevComment = NULL;
    int count = 0;


    while (currentComment != NULL && count < n - 1) {
        prevComment = currentComment;
        currentComment = currentComment->nxtPost;
        count++;
    }

    if (currentComment == NULL) {
        fprintf(stderr, "Error: Comment not found.\n");
        return false;
    }


    if (prevComment == NULL) {
        (platform->lastViewedPost)->Reply = currentComment->nxtPost;
    } else {
        prevComment->nxtPost = currentComment->nxtPost;
    }


    // clearReplies(currentComment);

    free(currentComment->Username);
    free(currentComment->Caption);
    free(currentComment);

    return true;
}

Comment viewComments(Platform platform) {
    if (platform == NULL || platform->lastViewedPost == NULL) {
        fprintf(stderr, "Error: No post has been viewed yet.\n");
        return NULL;
    }

    return (platform->lastViewedPost)->Reply;
}