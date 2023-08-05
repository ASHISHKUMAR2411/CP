#include <stdio.h>
#include <stdlib.h>
struct checking
{
    /* data */
    struct checking *ptr;
    struct checking *ctr;
};
int main()
{
    // ! it wil be a segmentation fault as it is unlegal address.
    struct checking *A = NULL;
    printf("\n the address when the struct point to NULL ");
    printf("\n %d %d %d ", A, A->ctr, A->ptr);
    return 0;
}
