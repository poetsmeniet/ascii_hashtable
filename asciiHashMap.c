#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciiHashMap.h"

//The hash is the first letter of key, linking to entries
int generateHashMap(hashMap *hMap)
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
int addKey(hashMap *hMap, char *key, int len)
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
    curr->next->value++;
    curr->next->next = NULL;

    //Increment totalCnt, nr of lements in hashtable
    hMap->totalCnt++;

    return 0;
}

//Just lists all entries in hashmap
void printHashMap(hashMap *hMap)
{
    printf("This hashmap has %d items:\n", hMap->totalCnt);
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
int getValue(hashMap *hMap, char *key)
{
    //Get the applicable list from first letter of key
    hME *head = hMap[(int)key[0]].keys->next;

    while(head != NULL){
        //printf("\tTest if '%s' cmp with '%s' (len: %d)\n", head->key, key, strlen(key));
        if(memcmp(head->key, key, strlen(key)) == 0)
            return head->value;
        head = head->next;
    }
    
    //Default value is non-existend
    return -1;
}
