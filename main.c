#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciiHashMap.h"
/*This file demonstrates usage*/
int main(void)
{
    hashMap *hMap1 = malloc(ASCIIEND * sizeof(hashMap)); //The number of needed ASCII chars, 32 through 126
    hMap1->totalCnt = 0;
    generateHashMap(hMap1);

    //Add keys to list
    addKey(hMap1, "Aard", 4);
    addKey(hMap1, "Aaron", 5);
    addKey(hMap1, "Abel", 4);
    addKey(hMap1, "Thomas", 6);
    addKey(hMap1, "Tom", 3);
    addKey(hMap1, "Jon Snow", 8);
    addKey(hMap1, "Thomas", 6);

    printHashMap(hMap1);
    
    //Demonstration:
    char aName[] = "nonexistent";
    printf("\nValue of key '%s': %d\n", aName, getValue(hMap1, aName));
    
    //free(hMap1);
    return 0;
}
