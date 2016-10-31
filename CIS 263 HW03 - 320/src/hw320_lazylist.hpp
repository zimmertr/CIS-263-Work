
#ifndef CS263_LAZY_LIST_H
#define CS263_LAZY_LIST_H

#include <utility>

/**
 * WARNING: The following code is INCOMPLETE and WILL NOT COMPILE!!!
 * This file is provided so question 3.20 (b) is clearly specified when
 * you completed all the "TODO"s in this file. In addition to these "TODO"s
 * you may have to add/design the supporting inner classes
 *
 */
namespace  gvsu {

template<typename Z>
class lazylist {

public:
    class iterator; /* forward declaration of inner classes */
private:
    class Node;      /* forward declaration of inner classes */
    Node *head;
    Node *tail;
    int num_deleted, num_nondeleted;
public:
    lazylist() { /* constructor */

    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;

    num_deleted = 0;
    num_nondeleted = 0;

    head->prev = nullptr;
    tail->next = nullptr;
    }

    /* This constructor allows us to construct and initialize using
     * an init-list:   { ___ , ___ , ___ , ____ }
     */
    lazylist(std::initializer_list<Z> values) : lazylist(){
        for (auto x = values.begin(); x != values.end(); ++x)
            push_back(*x);
    }

    ~lazylist() {
        while (!isEmpty())
            pop_back();
        delete head;
        delete tail;
    }

    bool isEmpty() const {
        if (num_nondeleted > 0){
            return false;
        }
        else{
            return true;
        }
    }

    int size() const {
        return num_nondeleted;
    }

    void push_back (const Z& item) {
        Node *S = new Node;
        S->data = item;
        S->prev = tail->prev;
        S->next = tail;
        tail->prev->next = S;   /* next of K */
        tail->prev = S;
        ++num_nondeleted;
    }

    void pop_back() {
        if (!isEmpty()) {
            erase(tail->prev);
        }
    }

    Z& front() {
        return  head->next->data;
    }

    const Z& front()  const {
        return front();
    }

    iterator insert (iterator pos, const Z& key) {
        Node *kn = new Node;
        kn->data = key;
        kn->prev = pos.currentNode->prev;
        pos.currentNode->prev->next = kn;
        pos.currentNode->prev = kn;
        kn->next = pos.currentNode;
        return iterator(kn);
    }

    iterator erase (iterator pos) {
        pos.currentNode->deleted = true;
        ++num_deleted;
        --num_nondeleted;
        if (num_deleted >= num_nondeleted){
            iterator iter = begin();
            iterator tmp(begin());
            while(iter.currentNode != tail)
                if(iter.currentNode->deleted){
                    iter.currentNode->prev->next = iter.currentNode->next;
                    iter.currentNode->next->prev = iter.currentNode->prev;
                    tmp = iterator(iter.currentNode->prev);
                    delete iter.currentNode;
                }
            return tmp;
        }
        return iterator(pos.currentNode->prev);
    }

    bool contains (const Z& key) const {
        iterator iter = head->next;

        while(iter != tail){

            if(!iter.currentNode->deleted)
                if(iter.currentNode->data == key)
                    return true;

            ++iter;
        }
        return false;
    }

    iterator begin() const {
        return iterator(head->next);
    }
    iterator end() const {
        return iterator(tail);
    }

    class iterator {
    private:
        Node *currentNode;
    public:
        iterator (Node *n){
        currentNode = n;
        }

        bool operator != (const iterator& rhs) const {
            return this->currentNode != rhs.currentNode;
        }

        bool operator == (const iterator& rhs) const {
            return this->currentNode == rhs.currentNode;
        }

        void operator++ () {
            do
                currentNode = currentNode->next;
            while(currentNode->deleted);
        }

		void operator--(){
			do
			currentNode=currentNode->prev;
			while(!currentNode->prev.deleted);
		}

        Z& operator* () {
            return currentNode->data;
        }
        friend class lazylist;
    };
};

template<typename Z>
class lazylist<Z>::Node {
public:
    Z data;
    bool deleted = false;
    Node *next; /* singly-linked lazylist */
    Node *prev; /* Doubly-linked lazylist */
};
}



#endif
