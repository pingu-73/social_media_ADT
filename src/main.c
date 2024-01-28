#include "platform.h"

int main() {
    Platform platform = NULL;
    char input[100];
    char command[20], arg1[100], arg2[100];

    while (1) {
        printf(BLACK_BOLD("Enter a command: "));
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        sscanf(input, "%s", command);

        char *arg_start = strchr(input, ' ');
        if (arg_start != NULL)
        {
            char *arg_end = strchr(arg_start + 1, ' ');
            if (arg_end != NULL)
            {
                strncpy(arg1, arg_start + 1, arg_end - arg_start - 1);
                arg1[arg_end - arg_start - 1] = '\0';
                strcpy(arg2, arg_end + 1);
            } 
            else 
            {
                strcpy(arg1, arg_start + 1);
                arg2[0] = '\0';
            }
        } 
        else 
        {
            arg1[0] = '\0';
            arg2[0] = '\0';
        }

        if (strcmp(command, "create_platform") == 0) {
            if (platform == NULL)
            {
                platform = createPlatform();
                if (platform != NULL)
                {
                    printf(GREEN("Platform created successfully.\n"));
                } 
                else
                {
                    printf(RED_BOLD("Failed to create platform.\n"));
                }
            } 
            else
            {
                printf(YELLOW("Platform already exists.\n"));
            }
        }

        else if (strcmp(command, "add_post") == 0)
        {
            if (strlen(arg1) == 0 || strlen(arg2) == 0)
            {
                printf(RED("Invalid arguments.\n"));
                continue;
            }
            addPost(platform, arg1, arg2);
        }

        else if (strcmp(command, "delete_post") == 0)
        {
            if (strlen(arg1) == 0)
            {
                printf(RED("Invalid arguments.\n"));
                continue;
            }
            int n = atoi(arg1);
            deletePost(&platform, n);
        }
        
        else if (strcmp(command, "view_post") == 0)
        {
            int post_number = atoi(arg1);
            Post v = viewPost(platform, post_number);
            if (v != NULL)
            {
                printf(GREEN("User: %s, \t Caption: %s\n"), v->Username, v->Caption);
            }
            else
            {
                printf(RED("Post not found.\n"));
            }
        }

        else if (strcmp(command, "current_post") == 0) 
        {
            Post currentPost = currPost(platform);
            if (currentPost != NULL)
            {
                printf(GREEN("Current Post: User: %s, \t Caption: %s\n"), currentPost->Username, currentPost->Caption);
            } 
            else
            {
                printf(YELLOW("No post currently viewed.\n"));
            }
        }

        else if (strcmp(command, "previous_post") == 0)
        {
            Post previous = previousPost(platform);
            if (previous != NULL)
            {
                printf(GREEN("Previous Post: User: %s, \t Caption: %s\n"), previous->Username, previous->Caption);
            } 
            else
            {
                printf(RED("No previous post available.\n"));
            }
        }

        else if (strcmp(command, "next_post") == 0) 
        {
            Post next = nextPost(platform);
            if (next != NULL)
            {
                printf(GREEN("Next Post: User: %s, \t Caption: %s\n"), next->Username, next->Caption);
            } 
            else
            {
                printf(RED("No next post available.\n"));
            }
        }

        else if (strcmp(command, "add_comment") == 0) 
        {
            if (platform == NULL || platform->lastViewedPost == NULL) 
            {
                printf(YELLOW("No post has been viewed yet. Unable to add comment.\n"));
            } 
            else 
            {
                char username[100], content[100];
                sscanf(input, "%*s %s %[^\n]", username, content);
                addComment(platform, username, content);
            }
        }

        else if (strcmp(command, "view_comments") == 0) 
        {
            Comment comments = viewComments(platform);
            if (comments != NULL) 
            {
                printf(GREEN("Comments:\n"));
                while (comments != NULL) {
                    printf(GREEN("User: %s, Content: %s\n"), comments->Username, comments->Caption);
                    comments = comments->nxtPost;
                }
            } 
            else 
            {
                printf(YELLOW("No comments available.\n"));
            }
        }

        else if (strcmp(command, "delete_comment") == 0) {
            if (platform == NULL || platform->lastViewedPost == NULL) {
                printf("No post has been viewed yet. Unable to delete comment.\n");
            } 
            else {
                int n = atoi(arg1);
                deleteComment(platform, n);
            }
        }

        else if (strcmp(command, "man") == 0) 
        {
            printf(YELLOW("\n//=============================== Mannual ============================================//\n"
                "[create_platform] \t \t \t- creates an instance of social media platform.\n"
                "[add_post <user_name> <caption>] \t- upload a post by <username> with <contents>.\n"
                "[delete_post <post_no.>] \t \t- deletes <post_no.>th recent post.\n"
                "[view_post <post_no.>] \t \t \t- lists nth recent post along with it's content.\n"
                "[view_comments] \t \t \t- lists all the comments.\n"
                "[add_comment <user_name> <content>] \t- post comment to last viewed post.\n"
                "[delete_comment]\n"
                "[view_comment]\n"
                "[current/previous/next_post]\n"
                "//======================================================================================//\n")
            );
        }

        else if (strcmp(command, "exit") == 0)
        {
            free(platform);
            printf(GREEN_BOLD("******************** thank you *******************\n"));
            return 0;
        }

        else {
            printf(RED_BOLD("------------------ Unknown command -------------\n"));
        }
    }
}
