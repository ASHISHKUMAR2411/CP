
-> In this section we will have different algorithm for till now which we have learned 


-> PARTITION -> QUICK SORT ALGORITHM 

-> 1.) USED IN QUICK SORT 
used for 3 way quick sort 
- in which we have to sort a array in which we have pivot element as element with many occuruence in the array so for that we do one thing we divie the group in the three sub array in which further partiton is done . 

 PARTITION(array , left_index, right_index, i , j )
{
    //here i and j are will keep an eye on the index for the three sub array
    // it is a bit hectic process
    //TODO

 }


-> 2.)FOR QUICK SORT 

USED IN QUICK SORT 

PARTITION(ARRAY, low , high)
 {
     // low means left and high means right
     // what we are doing is that we are just dividing the array across pivot element in order
     T pivot = arr[high];
     i = low - 1;                          // setting i before the array so that it will increse when needed and it will used for swapping
     for (int j = low; j <= high - 1; j++) // loop for  checking the pivot element and similarly calling the swaps
     {
         /* code */
         if (arr[j] < pivot)
         {
             // it check whether the j th element is less than pivot as we will do this we are swapping the element in the order of their acsndence i.e we wre just swapping all the elemenet smaller than pivot before a specific position I+1 so that at position when we will swap that with pivort then it will divide the array into two sub array where we will again apply the parition in those sun arrays
             i++;
             swapping(arr[i], arr[j]);
         }
     }
     swapping(arr[i + 1], arr[high]);
     return i + 1;

}


-> 3 ) DUTCH NATIONAL FLAG ALGORIThM 

USED FOR SORTING 

In thsi dutch algoritm we do  the same thing ias we did in three way sorting  but with a different approach 

PARTITIION(ARRAY, low , high , i , j )
{
    if (high - low <= 1)
    {
        if (array[high] < array[low])
        {
            swap(array[high], array[low]);
        }
        i = low;
        j = high;
        return;
    }
    mid = low;
    while (mid <= high)
    {
        if (arra[mid] < pivot)
        {
            swap(arr[mid++], arr[low++]);
        }
        else if (arr[mid] == pivot)
        {
            mid++;
        }
        else if (arr[mid] > pivot)
        {
            swap(arr[mid], arr[high--]);
        }
    }
    i = low - 1;
    j = mid;
}

BUBBLE SORT ALGORITHM

    used in bubble sort

        bubbleSort(array, size)
{
    bool swapped = false;
    // cretes a swappimg elemet which we keep an eye whether sorting done or not tis will save time once
    //sorting is acheived in earlier stages
    for (int i = 0; i < size - 1; i++)
    {
        // here we running the loop in such a way that it check every element for te sorting
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            // in this algorithm we check that every consceutive element order and swap them when needed .
            if (arr[j] > arr[j + 1])
            {
                swapping(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}