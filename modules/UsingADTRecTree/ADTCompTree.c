#include <stdlib.h>
#include <assert.h>
#include "ADTRecTree.h"
#include "ADTCompTree.h"
#include <stdio.h>

// Δημιουργεί και επιστρέφει ένα νέο complete δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right
// Υλοποίηση μέσω rectree δέντρου
CompTree comptree_create(Pointer value, CompTree left, CompTree right) {
	RecTree tree = rectree_create(value, (RecTree)left, (RecTree)right);
	return (CompTree)tree;
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.
int comptree_size(CompTree tree) {
	return rectree_size((RecTree)tree);
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.
void comptree_destroy(CompTree tree) {
	free(tree);
}


// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.
Pointer comptree_value(CompTree tree) {
	return rectree_value((RecTree)tree);
}

CompTree comptree_left(CompTree tree) {
	return (CompTree)rectree_left((RecTree)tree);
}

CompTree comptree_right(CompTree tree) {
	return (CompTree)rectree_right((RecTree)tree);
}

// Δημιουργεί και επιστρέφει ένα νέο δέντρο που προκύπτει από το tree μετά την προσθήκη της
// τιμής value στο "τέλος" του δέντρου (ώστε να παραμείνει complete). Τυχόν υποδέντρα που
// "μεταβάλλονται" κατά την προσθήκη αυτή καταστρέφονται αυτόματα.
CompTree comptree_insert_last(CompTree tree, Pointer value){
	CompTree subtree = comptree_create(value, COMP_TREE_EMPTY, COMP_TREE_EMPTY); // Δημιουργεί έναν κόμβο value χωρίς παιδιά
	int pos = comptree_size(tree) ; 			// Βρίσκει τη θέση που πρέπει να μπει ο κόμβος (στο τέλος δηλαδή)
	RecTree new_tree = rectree_replace_subtree((RecTree)tree, pos, (RecTree)subtree);	// Και τον προσθέτει μέσω της rectree_replace_subtree
	return (CompTree)new_tree;															// Επιστρέφει το νέο δέντρο
}

// Δημιουργεί και επιστρέφει ένα νέο δέντρο που προκύπτει από το tree μετά την διαγραφή του
// "τελευταίου" υποδέντρου του (ώστε να παραμείνει complete). Το υποδέντρο που αφαιρείται, και
// τυχόν υποδέντρα που "μεταβάλλονται" κατά τη διαγραφή αυτή καταστρέφονται αυτόματα.
CompTree comptree_remove_last(CompTree tree){
	int pos = comptree_size(tree) - 1;				// Η θέση του τελευταίου στοιχείου
	RecTree new_tree = rectree_replace_subtree((RecTree)tree, pos, REC_TREE_EMPTY); //Σε αυτή τη θέση βάζουμε μέσω της rectree_replace_subtree το κενό δέντρο
	return (CompTree)new_tree;														// Επιστρέφει το νέο δέντρο
}

CompTree comptree_get_subtree(CompTree tree, int pos){
	RecTree new_tree = rectree_get_subtree((RecTree)tree, pos);
	return (CompTree)new_tree;
}

CompTree comptree_replace_subtree(CompTree tree, int pos, CompTree subtree){
	RecTree new_tree = rectree_replace_subtree((RecTree)tree, pos, (RecTree)subtree);
	return (CompTree)new_tree;
}

