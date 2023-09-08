#include "hash.h"

int main()
{
    HashTable *ht = create_table(CAPACITY);
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");
    print_search(ht, (char *)"1");
    print_search(ht, (char *)"2");
    print_search(ht, (char *)"3");
    print_search(ht, (char *)"Hel");
    print_search(ht, (char *)"Cau"); /*Collision!*/
    print_table(ht);
    ht_delete(ht, (char *)"1");
    ht_delete(ht, (char *)"Cau");
    print_table(ht);
    free_table(ht);
    return 0;
}
