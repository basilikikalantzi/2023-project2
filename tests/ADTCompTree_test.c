#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "ADTRecTree.h"
#include "ADTCompTree.h"
#include <stdio.h>


// Επιστρέφει έναν ακέραιο σε νέα μνήμη με τιμή value
int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}

void test_create(void){
	// Δημιουργώ ένα απλό δένρο με 3 κόμβους
	Pointer p1 = create_int(1);
	CompTree left = comptree_create(p1, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p2 = create_int(2);
	CompTree right = comptree_create(p2, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p0 = create_int(0);
	CompTree tree = comptree_create(p0, left, right);
	TEST_ASSERT(tree != NULL);							// Ελέγχω αν είναι κενό
	
	TEST_ASSERT(comptree_size(tree) == 3);				//Ελέγχω αν το μεγεθός του είναι 3
	
	
	TEST_ASSERT(comptree_right(tree) != NULL);			// Αν επιστρέφει το αριστερό και το δεξί υποδέντρο
	TEST_ASSERT(comptree_left(tree) != NULL);
	
	
	Pointer p3 = create_int(3);
	tree = comptree_insert_last(tree, p3);				// Προσθέτω έναν κόμβο στο δέντρο
	TEST_ASSERT(comptree_value(tree) == p0);			// Ελέγχω αν το δέντρο είναι σωστό μετά την προσθήκη
	TEST_ASSERT(comptree_value(comptree_left(tree)) == p1);
	TEST_ASSERT(comptree_value(comptree_right(tree)) == p2);
	TEST_ASSERT(comptree_value(comptree_left(comptree_left(tree))) == p3);	//  Ελέγχω αν μπήκε στη σωστή θέση(κάτω αριστερά)
	
	Pointer p4 = create_int(4);
	tree = comptree_insert_last(tree, p4);				// Προσθέτω άλλον έναν κόμβο στο δέντρο
	TEST_ASSERT(comptree_value(tree) == p0);			// Ελέγχω αν το δέντρο είναι σωστό μετά την προσθήκη
	TEST_ASSERT(comptree_value(comptree_left(tree)) == p1);
	TEST_ASSERT(comptree_value(comptree_right(tree)) == p2);
	TEST_ASSERT(comptree_value(comptree_left(comptree_left(tree))) == p3);
	TEST_ASSERT(comptree_value(comptree_right(comptree_left(tree))) == p4);	// Ελέγχω αν μπήκε στη σωστή θέση

	CompTree removed_tree = comptree_remove_last(tree);	// Αφαιρώ τον τελευταίο κόμβο του δέντρου
	TEST_ASSERT(comptree_value(removed_tree) == p0);	// Ελέγχω αν το δέντρο είναι σωστό μετά την αφαίρεση
	TEST_ASSERT(comptree_value(comptree_left(removed_tree)) == p1);
	TEST_ASSERT(comptree_value(comptree_right(removed_tree)) == p2);
	TEST_ASSERT(comptree_right(comptree_left(removed_tree)) == COMP_TREE_EMPTY); //Ελέγχω αν  αφαιρέθηκε 

	removed_tree = comptree_remove_last(tree);	// Αφαιρώ πάλι τον τελευταίο κόμβο του δέντρου
	TEST_ASSERT(comptree_value(removed_tree) == p0);	// Ελέγχω αν το δέντρο είναι σωστό μετά την αφαίρεση
	TEST_ASSERT(comptree_value(comptree_left(removed_tree)) == p1);
	TEST_ASSERT(comptree_value(comptree_right(removed_tree)) == p2);
	TEST_ASSERT(comptree_left(comptree_left(removed_tree)) == COMP_TREE_EMPTY);	//Ελέγχω αν  αφαιρέθηκε

	
	
	
	
	// comptree_destroy(comptree_left(left));
	// comptree_destroy(left);
	// comptree_destroy(right);
	// comptree_destroy(tree);
	// comptree_destroy(removed_tree);
	free(p4);
	free(p3);
	free(p2);
	free(p1);
	free(p0);

	
}


TEST_LIST = {
	{ "comptree_create", test_create },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};