#include "TCircularList.h"
#include <stdio.h>
int main(){
    TCircularList* L1 = TCircularList_create();
    int j, a, b=0;
    scanf("%d %d", &j, &a);
    int V[j];
    for(int i=0; i<j; i++){
        V[i] = i+1;
    }
    for(int i=0; i<j; i++){
        if(!TCircularList_insert_end(L1, V[i]))
            printf("Não consegui inserir o V[%d]=%d na L1\n", i, V[i]);
    }
    for(int i = 0, b = 0; i <= 3; i++, b+2){
       int c = a+b;
       TCircularList_remove_after_n_steps(L1, c);
       TCircularList_print(L1);
       printf("\n%d %d\n", b, c);
       b+2;
    }
    return 0;
}