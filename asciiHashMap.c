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

//The hash is the first letter of key, linking to entries
extern int generateHashMap(hashMap *hMap)
{
    int i;
    for(i = ASCIISTART; i < ASCIIEND; i++){
        char firstLetter = (char)i;
        hMap[i].firstLetter = firstLetter;
        hMap[i].keys = malloc(sizeof(hME));
        hMap[i].keys->next = NULL;
    }
    return 0;
}

/*addKey will attempt to add a new key/value pair;
 * The value is this example is a counter
 * if the key already exists, it will only increment the value*/
extern int addKey(hashMap *hMap, char *key, int len)
{
    //Check for overflow
    if(len > MAXKEYSZ){
        printf("Sorry, max key length is %d\n", MAXKEYSZ);
        return 1;
    }

    //Get last item in list
    hME *curr = hMap[(int)key[0]].keys;
    while(curr->next != NULL){
        curr = curr->next;
        
        //Check if key exists (collision)
        if(memcmp(curr->key, key, len) == 0){
            curr->value++;
            return 0;
        }
    }
    
    //Add key to end of list
    curr->next = malloc(sizeof(hME));
    memcpy(curr->next->key, key, len);
    curr->next->key[len] = '\0';
    curr->next->value = 1;
    curr->next->next = NULL;

    //Increment totalCnt, nr of lements in hashtable
    hMap->totalCnt++;

    return 0;
}

//Just lists all entries in hashmap
extern void printHashMap(hashMap *hMap)
{
    printf("This hashmap has %zu items:\n", hMap->totalCnt);
    int i;
    for(i = ASCIISTART; i < ASCIIEND; i++){
        char firstLetter = (char)i;
        hME *head = hMap[i].keys->next;

        if(head != NULL)
            printf("Listing all keys beginning with '%c' (%d):\n", firstLetter, firstLetter);
        while(head != NULL){
            printf("\tKey: '%s', value: %d\n", head->key, head->value);
            head = head->next;
        }
    }
}

//Get the value of key in hashmap
extern int getValue(hashMap *hMap, char *key)
{
    //Get the applicable list from first letter of key
    hME *head = hMap[(int)key[0]].keys->next;

    while(head != NULL){
        if(memcmp(head->key, key, strlen(key)) == 0)
            return head->value;
        head = head->next;
    }
    
    //Default value is non-existend
    return -1;
}

//Free the allocated memory
extern int freeHashMap(hashMap *hMap)
{
    int i;
    for(i = ASCIISTART; i < ASCIIEND; i++){
        hME *curr = hMap[i].keys;
        while(curr != NULL){
            hME *next = curr->next; //Store tmp pointer
            free(curr->key);
            curr = next;
            next = NULL; //!Dangling pointer
        }
    }
    free(hMap);
    return 0;
}
