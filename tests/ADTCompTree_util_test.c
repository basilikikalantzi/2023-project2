#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing


#include "ADTCompTree.h"
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
	CompTree left = comptree_create(p3, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p4 = create_int(4);
	CompTree right = comptree_create(p4, COMP_TREE_EMPTY, COMP_TREE_EMPTY);

    Pointer p1 = create_int(1);
	left = comptree_create(p1, left, right);
	
	Pointer p2 = create_int(2);
	right = comptree_create(p2, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p0 = create_int(0);
	CompTree tree = comptree_create(p0, left, right);

int pos = 1;			// Παίρνω τυχαία τη θέση 1	
CompTree subtree= comptree_get_subtree(tree, pos);	// Παίρνω το υποδέντρο με ρίζα 1
TEST_ASSERT(comptree_value(subtree) == p1);		// Ελέγχω αν περιέχει η ρίζα το στοιχείο 1
TEST_ASSERT(comptree_value(comptree_left(subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(comptree_value(comptree_right(subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

CompTree subtree_empty = comptree_left(subtree);	//	Παίρνω το αριστερο υποδέντρο
TEST_ASSERT(comptree_left(subtree_empty) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(subtree_empty) == COMP_TREE_EMPTY);

subtree_empty = comptree_right(subtree);			//	Παίρνω το δεξί υποδέντρο
TEST_ASSERT(comptree_left(subtree_empty) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(subtree_empty) == COMP_TREE_EMPTY);
	
subtree_empty = comptree_right(subtree_empty);	
subtree_empty = comptree_get_subtree(subtree_empty, pos);	// Παίρνω ένα κενό δέντρο 
TEST_ASSERT(subtree_empty== COMP_TREE_EMPTY);		// Ε΄λεγχω αν μου επιστρέφει η συνάρτηση REC_TREE_EMPTY


// rectree_destroy(tree_test);
// rectree_destroy(subtree_empty);
// rectree_destroy(right);
// rectree_destroy(left);
// rectree_destroy(tree);
free(p0);
free(p1);
free(p2);
free(p3);
free(p4);
}


void test_replaced(void){

	// Φτιάχνω ένα δυαδικό δέντρο με στοιχεία από το 1-4 στους αντίστοιχους κόμβους
    Pointer p3 = create_int(3);	
	CompTree left = comptree_create(p3, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p4 = create_int(4);
	CompTree right = comptree_create(p4, COMP_TREE_EMPTY, COMP_TREE_EMPTY);

    Pointer p1 = create_int(1);
	left = comptree_create(p1, left, right);
	
	Pointer p2 = create_int(2);
	right = comptree_create(p2, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
	
	Pointer p0 = create_int(0);
	CompTree tree = comptree_create(p0, left, right);

int pos = 1;
CompTree subtree= comptree_get_subtree(tree, pos);

// Θα αντικαταστήσω το δεξί δέντρο της ρίζας με το subtree και ουσιαστικά θα γίνει ίδιο με το αριστερό
pos = 2;
CompTree replaced_tree = comptree_replace_subtree(tree, pos, subtree);
// Pointer p10 = comptree_value(replaced_tree);
// printf("%d\n", *(int*)p10);
TEST_ASSERT(comptree_value(replaced_tree) == p0);		// Ελέγχω αν περιέχει η ρίζα το στοιχείο 0
TEST_ASSERT(comptree_value(comptree_left(replaced_tree)) == p1);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 1
TEST_ASSERT(comptree_value(comptree_right(replaced_tree)) == p1);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 1

//Ελεγχος αριστερου υποδεντρου
CompTree temp_subtree = comptree_left(replaced_tree);
TEST_ASSERT(comptree_value(comptree_left(temp_subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(comptree_value(comptree_right(temp_subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

CompTree empty_subtree = comptree_left(temp_subtree);	//	Παίρνω το υποδέντρο του 3
TEST_ASSERT(comptree_left(empty_subtree) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(empty_subtree) == COMP_TREE_EMPTY);



empty_subtree = comptree_right(temp_subtree);	//	Παίρνω το υποδέντρο του 4
TEST_ASSERT(comptree_left(empty_subtree) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(empty_subtree) == COMP_TREE_EMPTY);



//Ελεγχος δεξιου υποδεντρου
temp_subtree = comptree_right(replaced_tree);
TEST_ASSERT(comptree_value(comptree_left(temp_subtree)) == p3);	// Ελέγχω αν περιέχει το αριστερό παιδί το στοιχείο 3
TEST_ASSERT(comptree_value(comptree_right(temp_subtree)) == p4);	// Ελέγχω αν περιέχει το δεξί παιδί το στοιχείο 4

empty_subtree = comptree_left(temp_subtree);	//	Παίρνω το αριστερο υποδέντρο
TEST_ASSERT(comptree_left(empty_subtree) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(empty_subtree) == COMP_TREE_EMPTY);

comptree_destroy(empty_subtree);

empty_subtree = comptree_right(temp_subtree);	//	Παίρνω το δεξι υποδέντρο
TEST_ASSERT(comptree_left(empty_subtree) == COMP_TREE_EMPTY);	// Ελέγχω αν τα παιδιά του είναι REC_TREE_EMPTY
TEST_ASSERT(comptree_right(empty_subtree) == COMP_TREE_EMPTY);


comptree_destroy(empty_subtree);

// rectree_destroy(right);
comptree_destroy(left);
// rectree_destroy(tree);
free(p0);
free(p1);
free(p2);
free(p3);
free(p4);


}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {

	{ "comptree_get_subtree", test_subtree },
	{ "comptree_replace_subtree", test_replaced },
	

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
}; 