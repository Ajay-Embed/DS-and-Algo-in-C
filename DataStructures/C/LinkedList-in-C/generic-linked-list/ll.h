#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

/**
 * A Linked List Node
 */
typedef struct Node LinkedListNode_t;

struct Node {
    void* data;
    LinkedListNode_t* next;
};

// Warning: This implementation is not thread-safe, and is for educational purposes only.

// Nomenclauture used (to avoid collisions): <data_type>_<method_name>

/**
 * Creates a new linked list head node with the provided data.
 *
 * @param data `void*` to the data.
 * @return A pointer to the start of the new linked list. Returns `NULL` if inner allocation fails.
 */
LinkedListNode_t* ll_new_node(void* data);

/**
 * Frees the memory allocated to the linked list and all its elements.
 *
 * @param head A pointer to the start of the linked list.
 * @param deallocator A function pointer which can deallocate the elements. Exits early if it is not provided.
 */
bool ll_free(LinkedListNode_t* head, void (*deallocator)(void*));

/**
 * Prints the linked list in Python's list style.
 *
 * @param head A pointer to the start of the linked list.
 * @param printer A function pointer which can properly show the elements. Prints memory address in the following format
 * if it is not provided.
 * ```txt
 * [<@0x7fff0000>, <@0x7fff0004>, <@0x7fff0008>, <@0x7fff000c>, <@0x7fff0010>]
 * ```
 */
void ll_print(LinkedListNode_t* head, void (*printer)(void*));

/**
 * Splits the linked list into two halves. If the list has an odd number of nodes, the extra node goes into the front
 * list.
 *
 * @param head A pointer to the start of the linked list.
 * @param front A variable reference where the output first half will be stored.
 * @param back A variable reference where the output second half will be stored.
 */
void ll_split(LinkedListNode_t* head, LinkedListNode_t** front, LinkedListNode_t** back);

/**
 * Returns `true` if the list is empty.
 *
 * @param head A pointer to the start of the linked list.
 * @return A boolean.
 */
bool ll_is_empty(LinkedListNode_t* head);

/**
 * Returns `true` if the list is circular. Internally uses two pointer approach of a fast and slow pointer. The slower
 * one moves one step per iteration whereas the faster one moves two steps.
 *
 * @param head A pointer to the start of the linked list.
 * @return A boolean.
 */
bool ll_is_circular(LinkedListNode_t* head);

/**
 * Creates a copy of the provided linked list.
 *
 * @param head A pointer to the start of the linked list.
 * @param copy_data A function pointer which can copy the elements.
 * @return A pointer to the start of the new linked list. Returns `NULL` if inner allocation fails.
 */
LinkedListNode_t* ll_copy(LinkedListNode_t* head, void* (*copy_data)(void*));

/**
 * Creates a linked list from the provided array.
 *
 * @param array Pointer to an array of elements.
 * @param element_size Size of each element in bytes.
 * @param length Number of elements in the array.
 * @param copy_data A function pointer which can copy the elements.
 * @return A pointer to the start of the new linked list. Returns `NULL` if inner allocation fails.

 */
LinkedListNode_t* ll_from_array(void* array, size_t element_size, size_t length, void* (*copy_data)(void*));

/**
 * Creates a linked list from the provided pointer array.
 *
 * @param array Pointer to an array of pointer of elements.
 * @param length Number of the total elements.
 * @param copy_data A function pointer which can copy the elements.
 * @return A pointer to the start of the new linked list. Returns `NULL` if inner allocation fails.
 */
LinkedListNode_t* ll_from_pointer_array(void** array, size_t length, void* (*copy_data)(void*));

/**
 * Flattens the given linked list into an array.
 *
 * @param head A pointer to the start of the linked list.
 * @param out_length A pointer to a variable where the number of elements would be returned.
 * @return Pointer to an array of pointer of elements.
 */
void** ll_to_array(LinkedListNode_t* head, size_t* out_length);

/**
 * Searches for an element inside the list and returns the first occurence with its index.
 *
 * @param head A pointer to the start of the linked list.
 * @param target A pointer to the data to be compared against.
 * @param cmp A function pointer which can compare the `target` and the elements. `-1`: lhs < rhs; `0`: lhs = rhs;
 * `+1`: lhs > rhs;
 * @param out_index A pointer to a variable where the index where the `target` is found is returned.
 * @return Pointer to the node where the `target` is found. It can be `NULL` if it is not found or if some error occurs.
 */
LinkedListNode_t* ll_find(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), size_t* out_index);

/**
 * Returns the length of the list.
 *
 * @param head A pointer to the start of the linked list.
 * @return Length of the list.
 */
size_t ll_length(LinkedListNode_t* head);

/**
 * Index into the linked list and returns the node at that index.
 *
 * @param head A pointer to the start of the linked list.
 * @param index Index to be returned.
 * @return A pointer to the `index`-th node. `NULL` if not found.
 */
LinkedListNode_t* ll_index(LinkedListNode_t* head, size_t index);

/**
 * Get the last node of the list.
 *
 * @param head A pointer to the start of the linked list.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_get_tail(LinkedListNode_t* head);

/**
 * Insert a new node at the start of the list.
 *
 * @param head A pointer to the start of the linked list.
 * @param data Pointer to the data to be inserted inside the `head` node.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_insert_head(LinkedListNode_t* head, void* data);

/**
 * Insert a new node at the end of the list.
 *
 * @param head A pointer to the start of the linked list.
 * @param data Pointer to the data to be inserted inside the last node.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_insert_tail(LinkedListNode_t* head, void* data);

/**
 * Insert a new node at the provided index.
 *
 * @param head A pointer to the start of the linked list.
 * @param data Pointer to the data to be inserted inside the node.
 * @param index Index at which the new node would be placed at.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_insert_index(LinkedListNode_t* head, void* data, size_t index);

/**
 * Nests a list inside another one at the provided index.
 *
 * @param head A pointer to the start of the linked list.
 * @param new_list A pointer to the start of the linked list.
 * @param index Index at which the `new_list` would be placed at.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_insert_ll_index(LinkedListNode_t* head, LinkedListNode_t* nested_list, size_t index);

/**
 * Appends a list to another.
 *
 * @param head A pointer to the start of the linked list.
 * @param other A pointer to the start of the linked list.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_append(LinkedListNode_t* head, LinkedListNode_t* other);

/**
 * Searches an element inside the linked list and removes its first occurence if found. To remove all matching
 * elements use `ll_remove_all` instead.
 *
 * @param head A pointer to the start of the linked list.
 * @param target A pointer to the data to be compared against.
 * @param cmp A function pointer which can compare the `target` and the elements.
 * @param deallocator A function pointer which can properly handle the deallocation of the element.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_remove(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*));

/**
 * Removes the provided index from the linked list.
 *
 * @param head A pointer to the start of the linked list.
 * @param index Index to be removed.
 * @param deallocator A function pointer which can properly handle the deallocation of the element.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_remove_index(LinkedListNode_t* head, size_t index, void (*deallocator)(void*));

/**
 * Removes a range of elements from the linked list.
 *
 * @param head A pointer to the start of the linked list.
 * @param start First element to be removed.
 * @param end Last element to be removed.
 * @param deallocator A function pointer which can properly handle the deallocation of the element.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_remove_range(LinkedListNode_t* head, size_t start, size_t end, void (*deallocator)(void*));

/**
 * Searches an element inside the linked list and removes all of its occurences if found.
 *
 * @param head A pointer to the start of the linked list.
 * @param target A pointer to the data to be compared against.
 * @param cmp A function pointer which can compare the `target` and the elements.
 * @param deallocator A function pointer which can properly handle the deallocation of the element.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_remove_all(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*));

/**
 * Sorts the linked list.
 *
 * @param head A pointer to the start of the linked list.
 * @param cmp A function pointer which can compare the `target` and the elements.
 * @return A pointer to the start of the sorted linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_sort(LinkedListNode_t* head, int (*cmp)(void*, void*));

/**
 * Reverse an linked list.
 *
 * @param head A pointer to the start of the linked list.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_reverse(LinkedListNode_t* head);

/**
 * Applies a function onto the list and returns a newly allocated one with the the function `fx` applied.
 * ```C
 * void printer(void* data) { printf("%d", *(int*)data); }
 *
 * void* twice(void* e) {
 *     int* i = malloc(sizeof(int));
 *
 *     *i = *(int*)e * 2;
 *
 *     return i;
 * }
 *
 * int arr[] = {4, 7, 1, 6, 2, 8, 9, 3, 0, 5};
 * int n = sizeof(arr) / sizeof(int);
 *
 * LinkedListNode_t* ll = ll_from_array((void*)arr, sizeof(int), n, copy_data);
 * ll_print(ll_map(ll, twice), printer); // [8, 14, 2, 12, 4, 16, 18, 6, 0, 10]
 * ```
 *
 * @param head A pointer to the start of the linked list.
 * @param fx A function pointer to the operation to be performed. Allocations would be handled by this itself.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_map(LinkedListNode_t* head, void* (*fx)(void*));

/**
 * Applies a predicate onto the list and returns a newly allocated one with only those elements which fulfill the given
 * predicate. A deallocator is provided in case if the filter fails middle of linked list.
 * ```C
 * void printer(void* data) { printf("%d", *(int*)data); }
 *
 * bool is_even(void* e) { return *(int*)e % 2 == 0; }
 *
 * void* copy_element(void* e) {
 *     int* copy = (int*)malloc(sizeof(int));
 *     if (!copy) return NULL;
 *
 *     *copy = *(int*)e;
 *     return copy;
 * }
 *
 * void deallocator(void* e) { free(e); }
 *
 * int arr[] = {4, 7, 1, 6, 2, 8, 9, 3, 0, 5};
 * int n = sizeof(arr) / sizeof(int);
 *
 * LinkedListNode_t* ll = ll_from_array((void*)arr, sizeof(int), n, copy_element);
 * ll_print(ll_filter(ll, is_even, copy_element, deallocator), printer); // [4, 6, 2, 8, 0]
 * ```
 *
 * @param head A pointer to the start of the linked list.
 * @param predicate A function pointer which returns `true` or `false` based upon whether a condition is satisfied or
 * not.
 * @param copy_element A function pinter to a function which will manage copying and allocation of the newly copied
 * elements.
 * @param deallocator A function pointer which can deallocate the elements. Exits early if it is not provided.
 * @return A pointer to the start of the new linked list. Returns `NULL` if failure.
 */
LinkedListNode_t* ll_filter(LinkedListNode_t* head, bool (*predicate)(void*), void* (*copy_element)(void*), void (*deallocator)(void*));

/**
 * Reduces the whole linked list into a single state element.
 * ```C
 * void sum(void* state, void* curr) { *(int*)state += *(int*)curr; } // `fx`
 *
 * int arr[10] = {4, 7, 1, 6, 2, 8, 9, 3, 0, 5};
 * LinkedListNode_t* ll = ll_from_array((void*)arr, sizeof(int), 10, copy_data);
 *
 * int total = 0; // `state`
 * ll_reduce(ll, &total, sum);
 *
 * printf("%d\n", total); // 45
 * ```
 *
 * @param head A pointer to the start of the linked list.
 * @param state A pointer to the initial state.
 * @param fx A function which takes the current elemenet and the state and does some operation and saves the result to
 * state. The first parameter is state.
 * @return Returns the pointer to the final state.
 */
void* ll_reduce(LinkedListNode_t* head, void* state, void (*fx)(void*, void*));

#endif  // LINKEDLIST_H