#pragma once

#include "PatriciaTreeNode.hpp"
#include <fstream>

using ull = unsigned long long;

class PatriciaTree {
public:
    PatriciaTree()
    {
        root = new PatriciaTreeNode();
        root->set_bit_index(-1);
    }

    PatriciaTree(string& key, unsigned long long int data)
    {
        root = new PatriciaTreeNode(key, data);
        root->set_bit_index(0);
    }
    
    bool find(string& key, ull& value)
    {
        PatriciaTreeNode *p, *x;

        p = root;
        x = root->get_left();

        while(x->get_bit_index() > p->get_bit_index()) {
            p = x;
            x = key.digit(x->get_bit_index()) ? x->get_right() : x->get_left();
        }

        if(!(key == x->get_key())) {
            return false;
        }
        value = x->get_data();
        return true;
    }

    void insert(string& key, unsigned long long int data)
    {
        PatriciaTreeNode *p, *t, *x;
        p = root;
        t = p->get_left();


        while(p->get_bit_index() < t->get_bit_index()) {
            p = t;
            t = key.digit(t->get_bit_index()) ? t->get_right(): t->get_left();
        }

        if(t->get_key() == key) {
            return;
        }
        int i;
        for(i = 0; t->get_key().digit(i) == key.digit(i); i++);

        p = root;
        x = root->get_left();

        while((p->get_bit_index() < x->get_bit_index()) && (x->get_bit_index() < i)) {
            p = x;
            x = key.digit(x->get_bit_index()) ? x->get_right() : x->get_left();
        }

        t = new PatriciaTreeNode(key, data);
            t->set_bit_index(i);
            t->set_left(key.digit(t->get_bit_index()) ? x : t);
            t->set_right(key.digit(t->get_bit_index()) ? t : x);

        if(key.digit(p->get_bit_index())) {
            p->set_right(t);
        } else {
            p->set_left(t);
        }
    }

    void remove(string& key) 
    {
        PatriciaTreeNode *pp, *p, *t;
        pp = root;
        p = root;
        t = root->get_left();
        while(p->get_bit_index() < t->get_bit_index()) {
            pp = p;
            p = t;
            t = key.digit(t->get_bit_index()) ? t->get_right() : t->get_left();
        }

        if(!(key == t->get_key())) {
            return;
        }

        if(t != p) {
            t->set_key(p->get_key(), p->get_data());
        }

        if(p->get_bit_index() < p->get_left()->get_bit_index() || p->get_bit_index() < p->get_right()->get_bit_index()) {

            if(p != t) {
                PatriciaTreeNode *lp, *x;
                lp = p;
                x = p->get_key().digit(p->get_bit_index()) ? p->get_right(): p->get_left();

                while(lp->get_bit_index() < x->get_bit_index()) {
                    lp = x;
                    x = p->get_key().digit(x->get_bit_index()) ? x->get_right(): x->get_left();
                }

                if(!(p->get_key() == x->get_key())) {
                    return;
                }

                if(p->get_key().digit(lp->get_bit_index())) {
                    lp->set_right(t);
                } else {
                    lp->set_left(t);
                }
            }

            if(pp != p) {
                PatriciaTreeNode* ch = key.digit(p->get_bit_index()) ? p->get_left() : p->get_right();
                if(key.digit(pp->get_bit_index())) {
                    pp->set_right(ch);
                } else {
                    pp->set_left(ch);
                }
            }

        } else {
             if(pp != p) {
                 PatriciaTreeNode* l = p->get_left();
                 PatriciaTreeNode* r = p->get_right();
                 PatriciaTreeNode* x = (l == r) ? pp : (l == p) ? r : l;
                 if(key.digit(pp->get_bit_index())) {
                     pp->set_right(x);
                 } else {
                     pp->set_left(x);
                 }
             }
        }

        delete p;
    }

    void fwriteR(std::ofstream& file, PatriciaTreeNode* node) {
        file << node->get_bit_index() << " " << node->get_key() << " " << node->get_data() << "\n";

        if(node->get_left()->get_bit_index() > node->get_bit_index()) {
            fwriteR(file, node->get_left());
        }

        if(node->get_right()->get_bit_index() > node->get_bit_index()) {
            fwriteR(file, node->get_right());
        }
    }

    int fwrite(string& file_name) {
        std::ofstream file;
        file.open(file_name.cstr());
        if(!file.is_open()) {
            return -1;
        }
        if(root->get_left() == root) {
            file << "-1 empty";
            return 0;
        }
        fwriteR(file, root->get_left());
        file.close();
        return 0;
    }

    int fread(string& file_name) {
        if(root->get_left() != root) {
            destroyR(root->get_left());
        }
        root->set_left(root);
        std::ifstream file;
        file.open(file_name.cstr());
        if(!file.is_open()) {
            return -1;
        }
        int bit;
        unsigned long long int data;
        string key;
        char c;
        while(file >> bit) {
            if(bit == -1) {
                break;
            }
            file.get(c);
            file >> key >> data;
            file.get(c);
            root->set_left(insertR(root->get_left(), key, data, bit, root));
        }
        file.close();
        return 0;
    }

    ~PatriciaTree() 
    {
        if(root->get_left() != root) {
            destroyR(root->get_left());
        }

        delete root;
    }
private:
    PatriciaTreeNode* root;

    PatriciaTreeNode* findR(PatriciaTreeNode* h, string& key, int d) {
        //std::cout << h->get_bit_index() << " " << d <<"\n";
        //std::cout << h << "\n";
        if (h->get_bit_index() <= d) return h;
        if (key.digit(h->get_bit_index()) == 0) {
            return findR(h->get_left(), key, h->get_bit_index());
        } else {
            return findR(h->get_right(), key, h->get_bit_index());
        }
    }

    PatriciaTreeNode* insertR(PatriciaTreeNode* h, string& key, unsigned long long int data, int d, PatriciaTreeNode* p) 
    {
        if(h->get_bit_index() >= d || h->get_bit_index() <= p->get_bit_index()) {
            PatriciaTreeNode* t = new PatriciaTreeNode(key, data);
            t->set_bit_index(d);
            t->set_left(key.digit(t->get_bit_index()) ? h : t);
            t->set_right(key.digit(t->get_bit_index()) ? t : h);
            return t;
        }
        if (key.digit(h->get_bit_index()) == 0) {
            h->set_left(insertR(h->get_left(), key, data, d, h));
        } else {
            h->set_right(insertR(h->get_right(), key, data, d, h));
        }
        return h;
    }

    void destroyR(PatriciaTreeNode* node) 
    {
        if(!node) return;
        if(node->get_left()->get_bit_index() > node->get_bit_index()) {
            destroyR(node->get_left());
        }
        if(node->get_right()->get_bit_index() > node->get_bit_index()) {
            destroyR(node->get_right());
        }
        delete node;
    }
};