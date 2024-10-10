#include "ADTRecTree.h"




RecTree rectree_get_subtree(RecTree tree, int pos){

    if(tree==REC_TREE_EMPTY){   // Αν το δέντρο είναι κενό επιστρέφει κενό δέντρο
        return REC_TREE_EMPTY;
    }
    if(!pos){                   // Αν η συνάρτηση κληθεί με pos 0 επιστρέφει το ίδιο δέντρο
        return tree;
    }
    if(pos%2 == 0){             // Αν η θ΄έση είναι άρτια τότε βρισκόμαστε σε δεξί παιδί
        pos = pos/2 -1;         // Και ο πατέρας του κόμβου έχει αυτή τη θέση
        if(!pos){               //  Το base case όταν η αναδρομή φτάσει στη ρίζα
            return rectree_right(tree); // Σημαίνει ότι το αρχικό pos ήταν το 2 άρα επιστρέφει το δεξί υποδέντρο
        } 
    }
    else{                       // Αν η θ΄έση είναι περιττή τότε βρισκόμαστε σε αριστερό παιδί
        pos = pos/2;            // Και ο πατέρας του κόμβου έχει αυτή τη θέση
        if(!pos){               //  Το base case όταν η αναδρομή φτάσει στη ρίζα
            return rectree_left(tree);  // Σημαίνει ότι το αρχικό pos ήταν το 1 άρα επιστρέφει το αρίστερο υποδέντρο
        } 

    }
    tree = rectree_get_subtree(tree, pos);  // αναδρομή
    if(pos%2 == 0){                         // Αν βρισκόμαστε σε δεξί παιδί
        return rectree_right(tree);         // Επιστρέφει το δεξί υποδέντρο
    }
    else{                                   // Αν βρισκόμαστε σε αριστερό παιδί
        return rectree_left(tree);          // Επιστρέφει το αρίστερο υποδέντρο
    } 
    
}


RecTree rectree_replace_subtree(RecTree tree, int pos, RecTree subtree){
    int parent;
    RecTree new_parent;
    if(tree==REC_TREE_EMPTY){   // Αν το δέντρο είναι κενό επιστρέφει το υπόδεντρο
        return subtree;
    }
    if(pos%2 == 0){ // Αν η θ΄έση είναι άρτια τότε βρισκόμαστε σε δεξί παιδί
        parent = pos/2 -1;      // Ο πατέρας του κόμβου έχει τη θέση parent
        new_parent = rectree_get_subtree(tree, parent);     //Παίρνουμε το υποδέντρο του πατέρα 
        rectree_destroy(rectree_right(new_parent));         // Διαγράφουμε το δεξί παιδι
        if(!parent){        //  Το base case όταν η αναδρομή φτάσει στη ρίζα
            Pointer temp_value = rectree_value(new_parent);
            RecTree temp_left = rectree_left(new_parent);
            rectree_destroy(new_parent);        // Σε αυτή τη περίπτωση διαγράφουμε και την ρίζα
            new_parent = rectree_create(temp_value, temp_left, subtree);    // Βάζουμε το subtree δεξι παιδί του πατέρα
            return new_parent;
        }
        new_parent = rectree_create(rectree_value(new_parent), rectree_left(new_parent), subtree); // Βάζουμε το subtree δεξι παιδί του πατέρα
        
    }
    else{   // Αν η θ΄έση είναι περιττή τότε βρισκόμαστε σε αριστερό παιδί
        parent = pos/2;     // Ο πατέρας του κόμβου έχει τη θέση parent
        new_parent = rectree_get_subtree(tree, parent);     //Παίρνουμε το υποδέντρο του πατέρα 
        rectree_destroy(rectree_left(new_parent));          // Διαγράφουμε το αριστερό παιδι
         if(!parent){
            Pointer temp_value = rectree_value(new_parent);
            RecTree temp_right = rectree_right(new_parent);
            rectree_destroy(new_parent);            // Σε αυτή τη περίπτωση διαγράφουμε και την ρίζα
            new_parent = rectree_create(temp_value, subtree, temp_right);       // Βάζουμε το subtree αριστερό παιδί του πατέρα
            return new_parent;
        }
        new_parent = rectree_create(rectree_value(new_parent), subtree, rectree_right(new_parent)); // Βάζουμε το subtree αριστερό παιδί του πατέρα
    }
    new_parent = rectree_replace_subtree(tree, parent, new_parent);     // αναδρομή
    return new_parent;
}