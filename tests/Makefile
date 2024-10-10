# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.



UsingHeap_ADTPriorityQueue_test2_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingADTCompTree/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o

## Υλοποιήσεις συναρτήσεων για την υλοποίηση του ADTCompTree μέσω πρώτης υλοποίησης του ADTRecTree
# UsingRecTree_ADTCompTree_util_test_OBJS = ADTCompTree_util_test.o $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o  $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o

## Υλοποιήσεις μέσω ADTSet, το οποίο υλοποιείται μέσω AVL Tree: ADTMap
# UsingMap_ADTMap_test_OBJS = ADTMap_test.o $(MODULES)/UsingADTMap/ADTMap.o $(MODULES)/UsingADTMap/ADTSet.o

## Υλοποιήσεις μέσω ADTMap υλοποίησης του ADTRecTree: ADTCompTree
# UsingLinkedTree_ADTCompTree_test_OBJS = ADTCompTree_test.o $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o $(MODULES)/UsingADTMap/ADTMap.o $(MODULES)/UsingADTMap/ADTSet.o

## Υλοποιήσεις μέσω πρώτης υλοποίησης του ADTRecTree: ADTCompTree
# UsingLinkedTree_ADTCompTree_test_OBJS = ADTCompTree_test.o $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o

## Υλοποιήσεις συναρτήσεων για την υλοποίηση του ADTRecTree μέσω ADTMap
# UsingLinkedTree_ADTRecTree_util_test2_OBJS = ADTRecTree_util_test.o  $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o $(MODULES)/UsingADTMap/ADTMap.o $(MODULES)/UsingADTMap/ADTSet.o

## Υλοποιήσεις συναρτήσεων για την πρώτη υλοποίηση του ADTRecTree
# UsingLinkedTree_ADTRecTree_util_test_OBJS = ADTRecTree_util_test.o  $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/UsingLinkedTree/ADTRecTree_utils.o

## Υλοποιήσεις μέσω ADTMap: ADTRecTree
# UsingMap_ADTTRecTree_test_OBJS = ADTRecTree_test.o $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/UsingADTMap/ADTMap.o $(MODULES)/UsingADTMap/ADTSet.o

## Υλοποίηση: ADTRecTree
# UsingLinkedTree_ADTRecTree_test_OBJS = ADTRecTree_test.o $(MODULES)/UsingLinkedTree/ADTRecTree.o 

## Υλοποιήσεις μέσω Heap: ADTPriorityQueue
## Το Heap χρησιμοποιεί Vector, οπότε χρειαζόμαστε και μια υλοποίηση του ADTVector
# UsingHeap_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingHeap/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o

# Ο βασικός κορμός του Makefile
include ../common.mk


