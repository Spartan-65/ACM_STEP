#ifndef LRUCACHE_H_INCLUDED
#define LRUCACHE_H_INCLUDED
int LRUCacheCreate(int capacity, void **lruCache);
int LRUCacheDestory(void **lruCache);
int LRUCacheSet(void *lruCache, char key, char data);
char LRUCacheGet(void *lruCache, char key);
void LRUCachePrint(void *lruCache);


#endif // LRUCACHE_H_INCLUDED
