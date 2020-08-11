#pragma once

#include "string.hpp"


class PatriciaTreeNode {
public:
    PatriciaTreeNode() : 
        left(this), 
        right(this) 
    {
    }

    PatriciaTreeNode(string& new_key, unsigned long long int new_data) :
        PatriciaTreeNode()
    {
        this->key = new_key;
        this->data = new_data;
    }

    PatriciaTreeNode(string& new_key, unsigned long long int new_data, int new_index, PatriciaTreeNode* new_left, PatriciaTreeNode* new_right) 
    {
        this->key = new_key;
        this->data = new_data;
        this->bit_index = new_index;
        this->left = new_left;
        this->right = new_right;
    }

    void set_left(PatriciaTreeNode* new_left)
    {
        this->left = new_left;
    }
    void set_right(PatriciaTreeNode* new_right)
    {
        this->right = new_right;
    }
    void set_bit_index(int new_index)
    {
        bit_index = new_index;
    }

    void set_key(string& new_key, unsigned long long int new_data)
    {
        key = new_key;
        data = new_data;
    }

    PatriciaTreeNode* get_left()
    {
        return left;
    }

    PatriciaTreeNode* get_right()
    {
        return right;
    }

    int get_bit_index()
    {
        return bit_index;
    }

    string& get_key()
    {
        return key;
    }

    unsigned long long int get_data()
    {
        return data;
    }

    ~PatriciaTreeNode() {
        left = nullptr;
        right = nullptr;
    }

private:
    string key;
    unsigned long long int data;
    int bit_index;
    PatriciaTreeNode* left;
    PatriciaTreeNode* right;
};