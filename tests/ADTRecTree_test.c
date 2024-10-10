
#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "ADTRecTree.h"


// Επιστρέφει έναν ακέραιο σε νέα μνήμη με τιμή value
int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}

void test_create(void){
	// Δημιουργώ ένα απλό δένρο με 3 κόμβους
	Pointer p1 = create_int(5);
	RecTree left = rectree_create(p1, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p2 = create_int(10);
	RecTree right = rectree_create(p2, REC_TREE_EMPTY, REC_TREE_EMPTY);
	
	Pointer p3 = create_int(15);
	RecTree tree = rectree_create(p3, left, right);
	TEST_ASSERT(tree != NULL);				// Ελέγχω αν είναι κενό
	
	TEST_ASSERT(rectree_size(tree) == 3);	//Ελέγχω αν το μεγεθός του είναι 3
	
	
	TEST_ASSERT(rectree_right(tree) != NULL);	// Αν επιστρέφει το αριστερό και το δεξί υποδέντρο
	TEST_ASSERT(rectree_left(tree) != NULL);
	
	
	int* p = rectree_value(tree);			// Ελέγχω αν επιστρέφει σωστά το value της ρίζας
	TEST_ASSERT(*p==15);
	rectree_destroy(left);					// Καταστρέφω τα υποδέντρα και τη ρίζα και την ελέγχω κοιταζοντας αν έχει η όχι leaks
	rectree_destroy(right);
	rectree_destroy(tree);
	free(p1);
	free(p2);
	free(p3);
}


TEST_LIST = {
	{ "rectree_create", test_create },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};