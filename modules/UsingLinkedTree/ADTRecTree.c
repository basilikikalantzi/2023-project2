///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include "ADTRecTree.h"
#include <stdio.h>


//  Ένα δέντρο είναι pointer σε αυτό το struct
struct rec_tree {
	Pointer value;
	RecTree right;
	RecTree left;
	int size;
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.
RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	RecTree tree = malloc(sizeof(struct rec_tree));
	tree->value = value;
	tree->left = left;
	tree->right = right;
	tree->size = 1;  				// Η ρίζα του δέντρου
	if(left != REC_TREE_EMPTY){		// Αν η ρίζα έχει αριστερό υπόδεντρο 
		tree->size += left->size;	// Το μέγεθος του δέντρου είναι η ρίζα + το μέγεθος του αρίστερου υπόδεντρου
	}
	if(right != REC_TREE_EMPTY){	// Αν η ρίζα έχει δεξ΄ί υπόδεντρο
		tree->size += right->size;	// Στο μέγεθος του δέντρου προστίθεται και το μέγεθος του δεξιού υπόδεντρου
	}
	// printf("12\n");
	return tree;
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.
int rectree_size(RecTree tree) {
	if(tree == REC_TREE_EMPTY){
		return 0;
	}
	return tree->size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.
void rectree_destroy(RecTree tree) {
	free(tree);
}


// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.
Pointer rectree_value(RecTree tree) {
	return tree->value;
}

RecTree rectree_left(RecTree tree) {
	return tree->left;
}

RecTree rectree_right(RecTree tree) {
	return tree->right;
}

