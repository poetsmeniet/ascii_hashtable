/*
asciiHashMap V1

Copyright (c) 2017 Thomas Wink <thomas@geenbs.nl>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

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

    ////Add keys to list
    addKey(hMap1, "Aard", 4);
    addKey(hMap1, "Aaron", 5);
    addKey(hMap1, "Abel", 4);
    addKey(hMap1, "Thomas", 6);
    addKey(hMap1, "Tom", 3);
    addKey(hMap1, "Jon Snow", 8);
    addKey(hMap1, "Thomas", 6);

    printHashMap(hMap1);
    
    ////Demonstration:
    char aName[] = "nonexistent";
    printf("\nValue of key '%s': %d\n", aName, getValue(hMap1, aName));
    
    freeHashMap(hMap1);
    return 0;
}
