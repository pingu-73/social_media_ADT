#include "platform.h"

Post globalLastViewedPost = NULL;

Platform* createPlatform()
{
    Platform P = (Platform)malloc(sizeof(struct Platform));
    assert(P != NULL);

    P->posts = NULL;
    return P;
}

