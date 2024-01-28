#include <string.h>
#include "reply.h"

Reply createReply(str username, Sentence content)
{
    Reply reply = (Reply)malloc(sizeof(Reply));
    assert(reply != NULL);

    reply->Username = (str)malloc(strlen(username) + 1);
    assert(reply->Username != NULL);

    strcpy(reply->Username, username);



    reply->Content = (Sentence)malloc(sizeof(content));
    assert(reply->Content != NULL);

    for (int i = 0; content[i] != NULL; i++)
    {
        reply->Content[i] = (str)malloc(strlen(content[i]) + 1);
        assert(reply->Content[i] != NULL);

        strcpy(reply->Content[i], content[i]);
    }

    reply->nxtComment = NULL;
    reply->prevComment = NULL;

    return reply;
}