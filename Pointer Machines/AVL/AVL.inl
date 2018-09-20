
template <class K, class D>
int AVL<K,D>::height(Node<K,D> *n){
	return n == NULL ? -1 : n->height;
}

template <class K, class D>
int AVL<K,D>::max( int a, int b ){
    return a > b ? a : b;
}

template<class K, class D>
void AVL<K,D>::turn_side(Node<K,D>** n, bool dir)
{
    Node<K,D>* tmp = (*n);
    (*n) = (*n)->p_child[dir];
    tmp->p_child[dir] = (*n)->p_child[!dir];
    (*n)->p_child[!dir] = tmp;
}

void AVL<K,D>::doble_turn_side(Node<K,D>** n, bool dir)
{
    rotacion(&(*n)->p_child[dir], !dir);
    rotacion(n, dir);
}

void insert(K & key, D & dato){
	insert(p_root, key, dato);
}

template<class K, class D>
bool AVL<K,D>::insert(Node<K,D>** p, K key, D d){
   if ((*p) == NULL) {
        (*p) = new Node<K,D>(key, d);
        return true;
    }
    else if( key < (*p)->key ){
        insert( key, (*p)->p_child[0] );
        if( height( (*p)->p_child[0] ) - height( (*p)->p_child[1] ) == 2 )
	        if( key < (*p)->p_child[0]->key )
	            turn_side((*p), 0);
	        else
	            doble_turn_side((*p), 0);
	    return true;
    }
    else if( (*p)->key < key ){
        insert( key, (*p)->p_child[1] );
        if( height( (*p)->p_child[1] ) - height( (*p)->p_child[0] ) == 2 ){
            if( (*p)->p_child[1]->key < key )
                turn_side((*p), 1);
            else
                doble_turn_side((*p), 1);
        }
        return true;
    }
    else
        ;  // Duplicate; do nothing
    (*p)->h = max( height( (*p)->p_child[0] ), height( (*p)->p_child[1] ) ) + 1; 

    return true;

}