#include <stdlib.h>
#include <assert.h>
#include "ADTRecTree.h"
#include "ADTMap.h"



// Δημιουργούμε μια ειδική compare συνάρτηση
int compare_pointers(Pointer a, Pointer b) {
	return (int)(a-b);
}

Pointer map_pointer = (Pointer)0;
Map tree_value;
Map tree_left;
Map tree_right;
Map tree_size;



// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.
RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	// Άν ο map_pointer είναι 0 τότε δημιούργούμε τα maps 
	if(!map_pointer){
		tree_value = map_create(compare_pointers,NULL, NULL);
		tree_left = map_create(compare_pointers,NULL, NULL);
		tree_right = map_create(compare_pointers,NULL, NULL);
		tree_size = map_create(compare_pointers,NULL, NULL);
	}
	map_pointer++;				// Αυξάνουμε τον pointer και στη θέση με το αντίστοιχο key προσθέτουμε τα στοιχεία του κόμβου στα maps
	map_insert(tree_value, map_pointer, value);
	map_insert(tree_left, map_pointer, left);
	map_insert(tree_right, map_pointer, right);
	int size=1;					// Η ρίζα του δέντρου
	if(left != REC_TREE_EMPTY){							// Αν η ρίζα έχει αριστερό υπόδεντρο
		size += (int)(long)map_find(tree_size, left);	// Το μέγεθος του δέντρου είναι η ρίζα + το μέγεθος του αρίστερου υπόδεντρου
	}													// Δεν γίνεται cast απευθείας pointer από σε int
	if(right != REC_TREE_EMPTY){						// Αν η ρίζα έχει δεξ΄ί υπόδεντρο
		size += (int)(long)map_find(tree_size, right);	// Στο μέγεθος του δέντρου προστίθεται και το μέγεθος του δεξιού υπόδεντρου
	}
	map_insert(tree_size, map_pointer, (Pointer)(long)size);

	return (RecTree)map_pointer;
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.
int rectree_size(RecTree tree) {
	if(tree == REC_TREE_EMPTY){
		return 0;
	}
	return (int)(long)map_find(tree_size, tree); //ο compiler δεν επιτρέπει να κάνουμε cast int σε pointer, οπότε θα χρειαστεί πρώτα cast σε long και μετά σε pointer.
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.
void rectree_destroy(RecTree tree) {
	// Αφαιρεί τον κόμβο αφαιρώντας τα στοιχεία του από τα maps
	map_remove(tree_value, (Pointer)tree);
	map_remove(tree_left, (Pointer)tree);
	map_remove(tree_right, (Pointer)tree);
	map_remove(tree_size, (Pointer)tree);
	
	if(!map_size(tree_value)){	// Αν αδειάσει κάποιο map τότε το δέντρο είναι κενό άρα καταστρέφουμε τα maps
		map_destroy(tree_value);
		map_destroy(tree_left);
		map_destroy(tree_right);
		map_destroy(tree_size);
		map_pointer = (Pointer)0;
	}

}


// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.
Pointer rectree_value(RecTree tree) {
	return map_find(tree_value, (Pointer)tree);
}

RecTree rectree_left(RecTree tree) {
	return map_find(tree_left, (Pointer)tree);
}

RecTree rectree_right(RecTree tree) {
	return map_find(tree_right, (Pointer)tree);
}