#include <stdio.h>
#include <string.h>

void func() {
    int num;
    char myname[32];

    printf("Please enter your age: ");
    scanf("%d", &num);
    printf("\n\tYou're  %d years old. (printf)", num);

    getchar();

    printf("\n\nNow please enter your name: ");
    gets(myname);
    printf("\n\tHello ");
    puts(myname);
}

int main()
{
    //write a void function which asks for a number with scanf and print it out with printf,
    //then asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    //A: gets does not work after scanf. I added a getchar() inbetween.

    func();

    return 0;
}
