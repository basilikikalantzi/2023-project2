#include <stdlib.h>
#include <assert.h>

#include "ADTPriorityQueue.h"
#include "ADTCompTree.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί Vector

// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	CompTree tree;				// Τα δεδομένα, σε comptree 
	CompareFunc compare;		// Η διάταξη
	DestroyFunc destroy_value;	// Συνάρτηση που καταστρέφει ένα στοιχείο του vector.
};

static Pointer node_value(PriorityQueue pqueue, int node_id) {
	// τα node_ids είναι 1-based, το node_id αποθηκεύεται στη θέση node_id - 1
	CompTree subtree = comptree_get_subtree(pqueue->tree, node_id - 1);
    return comptree_value(subtree);
    // return vector_get_at(pqueue->vector, node_id - 1);
}

// Ανταλλάσει τις τιμές των κόμβων node_id1 και node_id2
static void node_swap(PriorityQueue pqueue, int node_id1, int node_id2) {
	// τα node_ids είναι 1-based, το node_id αποθηκεύεται στη θέση node_id - 1
	
	CompTree subtree2 = comptree_get_subtree(pqueue->tree, node_id2 -1);	// παιρνω το υπ΄όδεντρο του ενός
	Pointer value1 = comptree_value(subtree2);								// και κρατάω το value του
	

	CompTree subtree1 = comptree_get_subtree(pqueue->tree, node_id1 -1);	// παίρνω το υπόδεντρο του άλλου
	CompTree temptree1 = comptree_create(comptree_value(subtree1), comptree_left(subtree1), comptree_right(subtree1)); 	// φτιάχνω ένα νέο δέντρο 
	
	pqueue->tree = comptree_replace_subtree(pqueue->tree, node_id2 -1, temptree1); 	// το βάζω στη θέση του πρώτου
	
	CompTree temptree2 = comptree_create(value1, comptree_left(subtree1), comptree_right(subtree1));// φτιαχνω ένα νέο δέντρο με το value αυτου που αντικαταστήσαμε 
	pqueue->tree = comptree_replace_subtree(pqueue->tree, node_id1 -1, temptree2);	// το βάζω στη θέση του άλλου
}



static void bubble_down(PriorityQueue pqueue, int node_id) {
	// βρίσκουμε τα παιδιά του κόμβου (αν δεν υπάρχουν σταματάμε)
	int left_child = 2 * node_id;
	int right_child = left_child + 1;

	int size = pqueue_size(pqueue);
	if (left_child > size)
		return;

	// βρίσκουμε το μέγιστο από τα 2 παιδιά
	int max_child = left_child;
	if (right_child <= size && pqueue->compare(node_value(pqueue, left_child), node_value(pqueue, right_child)) < 0)
			max_child = right_child;

	// Αν ο κόμβος είναι μικρότερος από το μέγιστο παιδί, swap και συνεχίζουμε προς τα κάτω
	if (pqueue->compare(node_value(pqueue, node_id), node_value(pqueue, max_child)) < 0) {
		node_swap(pqueue, node_id - 1, max_child);
		bubble_down(pqueue, max_child);
	}
}

static void efficient_heapify(PriorityQueue pqueue, Vector values){
    int size = vector_size(values);
    // Step 1: Insert values randomly
    for (int i = 0; i < size; i++) {
        pqueue->tree = comptree_insert_last(pqueue->tree, vector_get_at(values, i));
        // vector_insert_last(pqueue->vector, vector_get_at(values, i));
    }

    // Step 2: Bubble down on nodes between root and last internal node
     for (int i= (comptree_size(pqueue->tree)/2); i >0 ; i--) {
        bubble_down(pqueue, i);
    }
}

// static void efficient_heapify(PriorityQueue pqueue, CompTree tree){
//     int size = comptree_size(tree);
    
//     // Step 1: Insert values randomly
//     for (int i = 0; i < size; i++) {
//         comptree_insert_last(pqueue->tree, comptree_get_subtree(tree, i));
//         // vector_insert_last(pqueue->vector, vector_get_at(values, i));
//     }

//     // Step 2: Bubble down on nodes between root and last internal node
//     for (int i= (comptree_size(pqueue->tree)/2); i >0 ; i--) {
//         bubble_down(pqueue, i);
//     }
// }

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	assert(compare != NULL);	// LCOV_EXCL_LINE

	PriorityQueue pqueue = malloc(sizeof(*pqueue));
	pqueue->compare = compare;
	pqueue->destroy_value = destroy_value;

	// Δημιουργία του vector που αποθηκεύει τα στοιχεία.
	// ΠΡΟΣΟΧΗ: ΔΕΝ περνάμε την destroy_value στο vector!
	// Αν την περάσουμε θα καλείται όταν κάνουμε swap 2 στοιχεία, το οποίο δεν το επιθυμούμε.
	// pqueue->vector = vector_create(0, NULL);

	// Αν values != NULL, αρχικοποιούμε το σωρό.
	if (values != NULL)
		efficient_heapify(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	return comptree_size(pqueue->tree);
}

Pointer pqueue_max(PriorityQueue pqueue) {
	return node_value(pqueue, 1);		// root
}

void pqueue_remove_max(PriorityQueue pqueue) {
	int last_node = pqueue_size(pqueue);
	assert(last_node != 0);		// LCOV_EXCL_LINE

	// Destroy την τιμή που αφαιρείται
	if (pqueue->destroy_value != NULL)
		pqueue->destroy_value(pqueue_max(pqueue));

	// Αντικαθιστούμε τον πρώτο κόμβο με τον τελευταίο και αφαιρούμε τον τελευταίο
	node_swap(pqueue, 1, last_node);
    pqueue->tree=comptree_remove_last(pqueue->tree);
	// vector_remove_last(pqueue->vector);

 	// Ολοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού εκτός από τη νέα ρίζα
 	// που μπορεί να είναι μικρότερη από κάποιο παιδί της. Αρα μπορούμε να
 	// επαναφέρουμε την ιδιότητα του σωρού καλώντας τη bubble_down για τη ρίζα.
	bubble_down(pqueue, 1);
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	DestroyFunc old = pqueue->destroy_value;
	pqueue->destroy_value = destroy_value;
	return old;
}

void pqueue_destroy(PriorityQueue pqueue) {
	// Αντί να κάνουμε εμείς destroy τα στοιχεία, είναι απλούστερο να
	// προσθέσουμε τη destroy_value στο vector ώστε να κληθεί κατά το vector_destroy.
    comptree_destroy(pqueue->tree);
	// vector_set_destroy_value(pqueue->vector, pqueue->destroy_value);
	// vector_destroy(pqueue->vector);

	free(pqueue);
}