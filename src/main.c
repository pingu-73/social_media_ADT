#include "platform.h"

int main() {
    Platform platform = NULL;
    char input[100];
    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "create_platform") == 0) {
            if (platform == NULL) {
                platform = createPlatform();
                if (platform != NULL) {
                    printf("Platform created successfully.\n");
                } else {
                    printf("Failed to create platform.\n");
                }
            } else {
                printf("Platform already exists.\n");
            }
        }

        else if (strcmp(input, "add_post") == 0) {
            char username[100], content[100];
            printf("Enter your username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Enter content for post: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = '\0';
            addPost(platform, username, content);
        }

        else if (strcmp(input, "delete_post") == 0) {
            int n;
            printf("Enter the post number to delete: ");
            scanf("%d", &n);
            getchar();
            deletePost(&platform, n);
        }
        
        else if (strcmp(input, "view_post") == 0) {
            int n;
            printf("Enter the post number to view: ");
            scanf("%d", &n);
            getchar();
            Post v = viewPost(platform, n);
            if (v != NULL) {
                printf("User: %s, Caption: %s\n", v->Username, v->Caption);
            } else {
                printf("Post not found.\n");
            }
        }
        
        else if (strcmp(input, "add_comment") == 0) {
            if (platform == NULL || platform->lastViewedPost == NULL) {
                printf("No post has been viewed yet. Unable to add comment.\n");
            } else {
                char username[100], content[100];
                printf("Enter your username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                printf("Enter content for comment: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = '\0';
                addComment(platform, username, content);
            }
        }

        else if (strcmp(input, "delete_comment") == 0) {
            if (platform == NULL || platform->lastViewedPost == NULL) {
                printf("No post has been viewed yet. Unable to delete comment.\n");
            } else {
                int n;
                printf("Enter the comment number to delete: ");
                scanf("%d", &n);
                getchar();
                deleteComment(platform, n);
            }
        }

        else if (strcmp(input, "view_comments") == 0) {
            Comment comments = viewComments(platform);
            if (comments != NULL) {
                printf("Comments:\n");
                while (comments != NULL) {
                    printf("User: %s, Content: %s\n", comments->Username, comments->Caption);
                    comments = comments->nxtPost;
                }
            } else {
                printf("No comments available.\n");
            }
        } 

        else if (strcmp(input, "current_post") == 0){
            Post currentPost = currPost(platform);
            if (currentPost != NULL) {
                printf("Current Post: User: %s, Caption: %s\n", currentPost->Username, currentPost->Caption);
            } else {
                printf("No post currently viewed.\n");
            }
        }

        else if (strcmp(input, "previous_post") == 0){
            Post previous = previousPost(platform);
            if (previous != NULL) {
                printf("Previous Post: User: %s, Caption: %s\n", previous->Username, previous->Caption);
            } else {
                printf("No previous post available.\n");
            }
        }

        else if (strcmp(input, "next_post") == 0) {
            Post next = nextPost(platform);
            if (next != NULL) {
                printf("Next Post: User: %s, Caption: %s\n", next->Username, next->Caption);
            } else {
                printf("No next post available.\n");
            }
        }

        else if (strcmp(input, "exit") == 0) {
            free(platform);
            printf("******************** thank you *******************\n");
            return 0;
        }

        else {
            printf("Unknown command.\n");
        }
    }
}