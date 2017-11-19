#ifndef asciiHashMap_H_
#define asciiHashMap_H_
#define MAXKEYSZ 50
#define ASCIISTART 32
#define ASCIIEND 127

//Key/value pairs, linked list
typedef struct hashMapEntry{
    char key[MAXKEYSZ]; 
    int value;
    struct hashMapEntry *next;
}hME;

/*Struct that contains hashmap entries
 * Seperated by first letter*/
typedef struct hashMap{
    char firstLetter;
    size_t totalCnt;
    hME *keys;
}hashMap;

//The hash is the first letter of key, linking to entries
extern int generateHashMap(hashMap *hMap);

/*addKey will attempt to add a new key/value pair;
 * The value is this example is a counter
 * if the key already exists, it will only increment the value*/
extern int addKey(hashMap *hMap, char *key, int len);

//Get the value of key in hashmap, -1 is not found
extern int getValue(hashMap *hMap, char *key);

//Just lists all entries in hashmap
extern void printHashMap(hashMap *hMap);

#endif
