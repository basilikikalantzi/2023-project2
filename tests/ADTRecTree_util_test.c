
#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "ADTRecTree.h"
#include <stdio.h>

// Επιστρέφει έναν ακέραιο σε νέα μνήμη με τιμή value
int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}


void test_subtree(void){
	// Φτιάχνω ένα δυαδικό δέντρο με στοιχεία από το 1-4 στους αντίστοιχους κόμβους
    Pointer p3 = create_int(3);	
	RecTree left = rectree_create(p3, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p4 = create_int(4);
	RecTree right = rectree_create(p4, REC_TREE_EMPTY, REC_TREE_EMPTY);

    Pointer p1 = create_int(1);
	left = rectree_create(p1, left, right);
	
	Pointer p2 = create_int(2);
	right = rectree_create(p2, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p0 = create_int(0);
	RecTree tree = rectree_create(p0, left, right);

int pos = 1;			// Παίρνω τυχαία τη θέση 1	
RecTree subtree= rectree_get_subtree(tree, pos);	// Παίρνω το υποδέντρο με ρίζα 1
TEST_ASSERT(rectree_value(subtree) == p1);		// Ελέγχω αν περιέχει η ρίζα το στοιχείο 1
TEST_ASSERT(rectree_value(rectree_left(subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(rectree_value(rectree_right(subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

RecTree subtree_empty = rectree_left(subtree);	//	Παίρνω το αριστερο υποδέντρο
TEST_ASSERT(rectree_left(subtree_empty) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(subtree_empty) == REC_TREE_EMPTY);

subtree_empty = rectree_right(subtree);			//	Παίρνω το δεξί υποδέντρο
TEST_ASSERT(rectree_left(subtree_empty) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(subtree_empty) == REC_TREE_EMPTY);
	
subtree_empty = rectree_right(subtree_empty);	
subtree_empty = rectree_get_subtree(subtree_empty, pos);	// Παίρνω ένα κενό δέντρο 
TEST_ASSERT(subtree_empty== REC_TREE_EMPTY);		// Ε΄λεγχω αν μου επιστρέφει η συνάρτηση REC_TREE_EMPTY


rectree_destroy(rectree_left(subtree));
rectree_destroy(rectree_right(subtree));
rectree_destroy(right);
rectree_destroy(left);
rectree_destroy(tree);
free(p0);
free(p1);
free(p2);
free(p3);
free(p4);
}


void test_replaced(void){

	Pointer p3 = create_int(3);	
	RecTree left = rectree_create(p3, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p4 = create_int(4);
	RecTree right = rectree_create(p4, REC_TREE_EMPTY, REC_TREE_EMPTY);

    Pointer p1 = create_int(1);
	left = rectree_create(p1, left, right);
	
	Pointer p2 = create_int(2);
	right = rectree_create(p2, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p0 = create_int(0);
	RecTree tree = rectree_create(p0, left, right);

int pos = 1;
RecTree subtree= rectree_get_subtree(tree, pos);

// Θα αντικαταστήσω το δεξί δέντρο της ρίζας με το subtree και ουσιαστικά θα γίνει ίδιο με το αριστερό
pos = 2;
RecTree replaced_tree = rectree_replace_subtree(tree, pos, subtree);
TEST_ASSERT(rectree_value(replaced_tree) == p0);		// Ελέγχω αν περιέχει η ρίζα το στοιχείο 0
TEST_ASSERT(rectree_value(rectree_left(replaced_tree)) == p1);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 1
TEST_ASSERT(rectree_value(rectree_right(replaced_tree)) == p1);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 1

//Ελεγχος αριστερου υποδεντρου
RecTree temp_subtree = rectree_left(replaced_tree);
TEST_ASSERT(rectree_value(rectree_left(temp_subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(rectree_value(rectree_right(temp_subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

RecTree empty_subtree = rectree_left(temp_subtree);	//	Παίρνω το υποδέντρο του 3
TEST_ASSERT(rectree_left(empty_subtree) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(empty_subtree) == REC_TREE_EMPTY);



empty_subtree = rectree_right(temp_subtree);	//	Παίρνω το υποδέντρο του 4
TEST_ASSERT(rectree_left(empty_subtree) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(empty_subtree) == REC_TREE_EMPTY);



//Ελεγχος δεξιου υποδεντρου
temp_subtree = rectree_right(replaced_tree);
TEST_ASSERT(rectree_value(rectree_left(temp_subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(rectree_value(rectree_right(temp_subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

empty_subtree = rectree_left(temp_subtree);	//	Παίρνω το αριστερο υποδέντρο
TEST_ASSERT(rectree_left(empty_subtree) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(empty_subtree) == REC_TREE_EMPTY);

rectree_destroy(empty_subtree);

empty_subtree = rectree_right(temp_subtree);	//	Παίρνω το δεξι υποδέντρο
TEST_ASSERT(rectree_left(empty_subtree) == REC_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(rectree_right(empty_subtree) == REC_TREE_EMPTY);


rectree_destroy(rectree_right(rectree_left(replaced_tree)));
rectree_destroy(rectree_right(replaced_tree));
rectree_destroy(replaced_tree);
free(p0);
free(p1);
free(p2);
free(p3);
free(p4);


}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {

	{ "rectree_get_subtree", test_subtree },
	{ "rectree_replace_subtree", test_replaced },
	

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
}; 