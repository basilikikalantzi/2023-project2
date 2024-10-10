![run-tests](../../workflows/run-tests/badge.svg)

## 2023 Project 2

Εκφώνηση: https://k08.chatzi.org/projects/project2/


### Προσωπικά στοιχεία

__Όνομα__: Βασιλική Καλαντζή

__Α.Μ.__: sdi2200057

### Ασκήσεις που παραδίδονται

Συμπληρώστε εδώ τις ασκήσεις (και τυχόν bonus) που παραδίδετε. Αν κάποια άσκηση
βρίσκεται σε μη αναμενόμενα αρχεία αναφέρετε και τα αρχεία αυτά.

- Άσκηση 1
- Άσκηση 2
- Άσκηση 3
- Άσκηση 4 (το τεστ με την υλοποίηση μέσω map βγαινει failed)
- Άσκηση 5  (έχω κάνει κάτι λίγα)

### Documentation

Συμπληρώστε εδώ __όσο documentation χρειάζεται__ ώστε οι βαθμολογητές να
κατανοήσουν πλήρως τις λύσεις σας και να τις βαθμολογήσουν ανάλογα. Αυτό θα
πρέπει να γίνει ανεξάρτητα με το αν ο κώδικάς σας είναι καλά σχολιασμένος,
πράγμα που συνιστάται.

Πολυπλοκότητες
Άσκηση 2:
    Η map_create βασίζεται στη set_create, η οποία έχει πολυποκότητα  O(1).
    Η map_insert βασίζεται στη set_insert,που χρησιμοποιει την set_find, η οποία είναι υλοποιημένη με AVL άρα έχει πολυπλοκότητα  O(logn).
    Επομένως, rectree_create η οποία χρησιμοποιεί τις map_create και map_insert έχει πολυπλοκότητα O(logn).

    Η rectree_size βασίζεται στη map_find, άρα και στη set_find η οποία έχει πολυπλοκότητα O(logn).

    Η rectree_destroy βασίζεται στην map_destroy, η οποία έχει πολυπλοκοτητα Ο(1) και στην map_remove, η οποία στηρίζεται στην set_find, άρα εχει πολυπλοκότητα O(logn). Επομένως η rectree_destroy εχει πολυπλοκότητα O(logn).

    Οι συναρτήσεις rectree_value, rectree_left, rectree_right στηρίζονται στην map_find άρα και στη sset_find άρα έχουν πολυπλοκότητα O(logn).

Άσκηση 3:
    H συνάρτηση rectree_get_subtree έχει πολυπλοκότητα O(h) και  η rectree_replace_subtree O(h^2), αφού καλεί h φορές την rectree_get_subtree,  αναλόγως το ύψος του δέντρου αφού δεν είναι complete

Άσκηση 4:
    Οι πολυπλοκότητες διαφέρουν ανάλογα με την υλοποίηση της rectree που θα χρησιμοποιήσουμε
    Με βάση της πρώτη υλοποίηση:
    Οι συναρτήσεις comptree_create, comptree_destroy, comptree_size, comptree_left, comptree_right, comptree_value έχουν πολυπλοκότητα Ο(1), ενώ οι comptree_insert_last και comptree_remove_last έχουν πολυπλοκότητα Ο(logn) αφού βασίζονται στην rectree_replace_subtree και το δέντρο είναι complete
    Με βάση την map υλοποίηση:
    Οι συναρτήσεις comptree_create, comptree_destroy, comptree_size, comptree_left, comptree_right, comptree_value έχουν πολυπλοκότητα Ο(logn), ενώ οι comptree_insert_last και comptree_remove_last έχουν πολυπλοκότητα Ο(logn^2) αφού βασίζονται στην rectree_replace_subtree και το δέντρο είναι complete
