#ifndef TCIRCULAR_LINKED_LIST_H
#define TCIRCLAR_LINKED_LIST_H
#include <stdbool.h>

typedef struct linked_list TCircularList;
/**
 * Cria uma uma instância válida de TCircularList
 * @return TCircularList*
 * */
TCircularList* TCircularList_create();
/**
 * Deleta apropriadamente uma uma instância válida de TCircularList
 * @param TCircularList* ponteiro para uma lista válida
 *  */
void TCircularList_destroy(TCircularList*);
/**
 * Insere um inteiro no início da lista.
 * @param TCircularList* ponteiro da lista
 * @param int informação a ser inserida
 * @return _Bool (se deu certo ou não)
 * */
_Bool TCircularList_insert_begin(TCircularList*, int);
/**
 * Insere um inteiro no fim da lista.
 * @param TCircularList* ponteiro da lista
 * @param int informação a ser inserida
 * @return _Bool (se deu certo ou não)
 * */
_Bool TCircularList_insert_end(TCircularList*, int);

/**
 * Remove o nó após n passos na lista circular a partir do início.
 * @param TCircularList* ponteiro da lista
 * @param int quantidade de voltas na lista
 * @return _Bool (se deu certo ou não)
 * */
_Bool TCircularList_remove_after_n_steps(TCircularList*, int);
/**
 * Imprime uma lista 
 * @param TCircularList* ponteiro para uma lista válida
 *  */
void TCircularList_print(TCircularList*);

#endif