#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        Node<T>* toDelete;
        T data;

        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            toDelete = prev->next;
            prev->next = toDelete->next;
        }

        data = toDelete->data;
        delete toDelete;
        n--;
        return data;
    }

    T get(int pos) override {
        return (*this)[pos];
    }

    int search(T e) override {
        Node<T>* aux = first;
        int i = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return i;
            }
            aux = aux->next;
            i++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list) {
        out << "[";
        Node<U>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) {
                out << ", ";
            }
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};

#endif
