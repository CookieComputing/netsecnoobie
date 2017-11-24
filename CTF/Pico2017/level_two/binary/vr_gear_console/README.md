# VR Gear Console

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33193392-42813192-d096-11e7-8745-4476569659a4.png)

Let's look at the source code:

```
    #include <stdlib.h>
    #include <stdio.h>

    int login() {
        int accessLevel = 0xff;
        char username[16];
        char password[32];
        printf("Username (max 15 characters): ");
        gets(username);
        printf("Password (max 31 characters): ");
        gets(password);

        if (!strcmp(username, "admin") && !strcmp(password, "{{ create_long_password() }}")) {
            accessLevel = 2;
        } else if (!strcmp(username, "root") && !strcmp(password, "{{ create_long_password() }}")) {
            accessLevel = 0;
        } else if (!strcmp(username, "artist") && !strcmp(password, "my-password-is-secret")) {
            accessLevel = 0x80;
        }

        return accessLevel;
    }

    int main(int argc, char **argv) {
        setbuf(stdout, NULL);
        printf(
            "+----------------------------------------+\n"
            "|                                        |\n"
            "|                                        |\n"
            "|                                        |\n"
            "|                                        |\n"
            "|  Welcome to the VR gear admin console  |\n"
            "|                                        |\n"
            "|                                        |\n"
            "|                                        |\n"
            "|                                        |\n"
            "+----------------------------------------+\n"
            "|                                        |\n"
            "|      Your account is not recognized    |\n"
            "|                                        |\n"
            "+----------------------------------------+\n"
            "\n\n\n\n"
            "Please login to continue...\n\n\n"
        );
        int access = login();

        printf("Your access level is: 0x%08x\n", access);

        if (access >= 0xff || access <= 0) {
            printf("Login unsuccessful.\n");
            exit(10);
        } else if (access < 0x30) {
            printf("Admin access granted!\n");
            printf("The flag is in \"flag.txt\".\n");
            system("/bin/sh");
        } else {
            printf("Login successful.\n");
            printf("You do not have permission to access this resource.\n");
            exit(1);
        }
    }
```

An interesting to note is that `gets()` does not have any input length checking. This means we can overload the buffer and smash the stack if we want to!

The variable we want to smash is located at `ebp - 0xc`, whereas the start of `username` is at `ebp-0x1c`. Some simple math results in `0x1c-0xc = 16`. So we need 16 bytes to overwrite to get to the access level.

Next, we need a good access level character. A character like `!` ought to do the trick.

Here is the result:

![image](https://user-images.githubusercontent.com/24576987/33193337-e9760b90-d095-11e7-9ec6-ffaf81166cb9.png)

