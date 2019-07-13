#pragma once
#include "Node.h"

class Node;
class SingleNode;
class DoubleNode;

/**
 * The interface List that forces subclasses to implement common methods
 */
class List {
protected:
    /**
     * Updates the actual number of elements in the list
     */
    unsigned int s;

public:

    /**
     * Deletes every linked node
     */
    virtual void clear() = 0;

    /**
     * Returns the total number of nodes in the list
     * @return [unigned int] The total number of elements
     */
    virtual unsigned int size() = 0;

    /**
     * Deletes every linked node
     */
    virtual ~List() {};
};

class SingleList: public List {
protected:
    /**
     * The very first node on the list
     */
    SingleNode ** start;

	friend Sort;

public:

    /**
     * TODO implement
     * Push the node at the beginning of the list
     * @param [SingleNode *] The node to be pushed
     * @return [void]
     */
    void push(SingleNode * SNode);

    /**
     * TODO implement
     * Push the node at the desired place on the list
     * @param [SingleNode *] The node to be pushed
     * @param [usigned int] The position where to push the node
     * @return [void]
     */
    void push(SingleNode * SNode, unsigned int Pos);
    
    /**
     * TODO implement
     * Pulls the last node of the list and unlinks it
     * @return [SingleNode *] The unlinked node
     */
    SingleNode * pull();

    /**
     * TODO implement
     * Pulls the desired node of the list and unlinks it
     * @param [usigned int] The position of the node to unlink
     * @return [SingleNode *] The unlinked node
     */
    SingleNode * pull(unsigned int Pos);

    /**
     * TODO implement
     * Deletes the last node of the list
     * @return [void]
     */
    void remove();

    /**
     * TODO implement
     * Deletes the desired node from the list
     * @param [usigned int] The position of the node to unlink
     * @return [void]
     */
    void remove(unsigned int Pos);

    /**
     * TODO implement
     * Concatenates all the nodes to the output stream
     */
    friend std::ostream & operator << (std::ostream & out, const SingleList & SNode);

    /**
     * TODO implement
     * Deletes every linked node
     */
    void clear();

    /**
     * TODO implement
     * Returns the total number of nodes on the list
     * @return [unigned int] The total number of elements
     */
    unsigned int size();

    /**
     * TODO implement
     * Deletes every linked node
     */
    ~SingleList();
};

class DoubleList: public List {
protected:
    /**
     * The very first node on the list
     */
    DoubleNode ** start;

	friend Sort;

public:

    /**
     * TODO implement
     * Push the node at the beginning of the list
     * @param [DoubleNode *] The node to be pushed
     * @return [void]
     */
    void push(DoubleNode * DNode);

    /**
     * TODO implement
     * Push the node at the desired place on the list
     * @param [DoubleNode *] The node to be pushed
     * @param [usigned int] The position where to push the node
     * @return [void]
     */
	void push(DoubleNode * DNode, unsigned int Pos);
    
    /**
     * TODO implement
     * Pulls the last node of the list and unlinks it
     * @return [DoubleNode *] The unlinked node
     */
    DoubleNode * pull();

    /**
     * TODO implement
     * Pulls the desired node of the list and unlinks it
     * @param [usigned int] The position of the node to unlink
     * @return [DoubleNode *] The unlinked node
     */
    DoubleNode * pull(unsigned int Pos);

    /**
     * TODO implement
     * Deletes the last node of the list
     * @return [void]
     */
    void remove();

    /**
     * TODO implement
     * Deletes the desired node from the list
     * @param [usigned int] The position of the node to unlink
     * @return [void]
     */
    void remove(unsigned int Pos);

    /**
     * TODO implement
     * Concatenates all the nodes to the output stream
     */
    friend std::ostream & operator << (std::ostream & out, const DoubleList & DList);

    /**
     * TODO implement
     * Deletes every linked node
     */
    void clear();

    /**
     * TODO implement
     * Returns the total number of nodes on the list
     * @return [unigned int] The total number of elements
     */
    unsigned int size();

    /**
     * TODO implement
     * Deletes every linked node
     */
    ~DoubleList();
};