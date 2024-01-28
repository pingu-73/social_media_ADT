#include "platform.h"

// // int main()
// // {
// //     Platform platform = NULL;
// //     char input[100];
// //     while (true) {
// //         printf("Enter a command: ");
// //         fgets(input, sizeof(input), stdin);
// //         input[strcspn(input, "\n")] = '\0';

// //         if (strcmp(input, "create_platform") == 0) {
// //             if (platform == NULL) {
// //                 platform = createPlatform();
// //                 if (platform != NULL) {
// //                     printf("Platform created successfully.\n");
// //                 } else {
// //                     printf("Failed to create platform.\n");
// //                 }
// //             } else {
// //                 printf("Platform already exists.\n");
// //             }
// //         } else {
// //             printf("Unknown command.\n");
// //         }

// //         if (strcmp(input, "add_post") == 0){
// //             char *username; char *content;
// //             scanf("Enter your username: %s", &username);
// //             scanf("Enter content for post: %s", &content);
// //             addPost(platform, username, content);
// //         }

// //         if (strcmp(input, "delete_post") == 0){
// //             int n; scanf("%d", &n);
// //             deletePost(platform, n);
// //         }

// //         if (strcmp(input, "view_post") == 0){
// //             int n; scanf("%d", &n);
// //             Post v = viewPost(platform, n);
// //             printf("User: %s,  Caption: %s",v->Username, v->Caption);
// //         }
// //     }
// // }



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
        } else if (strcmp(input, "add_post") == 0) {
            char username[100], content[100];
            printf("Enter your username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Enter content for post: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = '\0';
            addPost(platform, username, content);
        } else if (strcmp(input, "delete_post") == 0) {
            int n;
            printf("Enter the post number to delete: ");
            scanf("%d", &n);
            getchar();
            deletePost(&platform, n);
        } else if (strcmp(input, "view_post") == 0) {
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
        } else {
            printf("Unknown command.\n");
        }
    }
}



// #define MAX_INPUT_LENGTH 100

// int main(){
//     Platform platform = createPlatform();
//     char input[MAX_INPUT_LENGTH];
//     char *command, *username, *caption;
//     int postIndex;

//     while (1) {
//         fgets(input, MAX_INPUT_LENGTH, stdin);
//         input[strcspn(input, "\n")] = '\0';  // Remove newline character
        
//         command = strtok(input, " ");
        
//         if (strcmp(command, "create_platform") == 0) {
//             printf("Platform created.\n");
//         } else if (strcmp(command, "add_post") == 0) {
//             username = strtok(NULL, " ");
//             caption = strtok(NULL, "\n");
//             if (addPost(platform, username, caption)) {
//                 printf("Post added successfully.\n");
//             } else {
//                 printf("Failed to add post.\n");
//             }
//         } else if (strcmp(command, "delete_post") == 0) {
//             postIndex = atoi(strtok(NULL, " "));
//             if (deletePost(&platform, postIndex)) {
//                 printf("Post deleted successfully.\n");
//             } else {
//                 printf("Failed to delete post.\n");
//             }
//         } else {
//             printf("Invalid command.\n");
//         }
//     }

//     return 0;
// }