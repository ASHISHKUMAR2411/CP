// kbhit_function
// C++ program to demonstrate use of kbhit()
#include <iostream>
#include <conio.h>

    int
    main()
{
    while (!kbhit())
        printf("Press a key\n");

    return 0;
}
