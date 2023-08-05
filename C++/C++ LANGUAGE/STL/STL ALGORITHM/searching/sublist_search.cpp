// sublist search is used to find the list in another list ..
#include<bits/stdc++.h>
using namespace std;
struct ll
{
    int info;
    struct ll *link;
};
bool findList(ll *first , ll *second)
{
    ll *ptr1 = first , *ptr2 = second;
    if(ptr1==NULL && ptr2 == NULL)
        return 1;
    if(ptr1==NULL || (ptr1!=NULL && ptr2==NULL))
        return 0;
    while(ptr1 != NULL)
    {
        ptr2 = second;
        if(ptr1->info == ptr2->info)
        {
            while(ptr1->info == ptr2->info)
            {
                ptr1=ptr1->link;
                ptr2=ptr2->link;
            }
            if(ptr2==NULL)
            {
                return 1;
            }
        }
        else
        {
            ptr1 = ptr1->link;
        }
    }
    return 0;
}

