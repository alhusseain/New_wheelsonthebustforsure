#pragma once
#ifndef DATASTRUCTURES
#define DATASTRUCTIRES
#include<iostream>
using namespace std;

// NODES Class ---------------------------------------------

template<class t>
class Node {
public:
    t data;
    int priority;

    Node<t>* next;
    Node():next(nullptr),priority(NULL){}
    Node(t value) : data(value), next(nullptr), priority(NULL) {}

    Node(t value, int priorityvalue) : data(value), next(nullptr), priority(priorityvalue) {}

    void set_item(t value)
    {
        data = value;
    }
    t get_item()
    {
        return data;
    }

    void set_next(Node<t>* node)
    {
        next = node;
    }

    Node<t>* get_next()
    {
        return next;
    }

    int get_priority()
    {
        return priority;
    }

    void set_priority(int number)
    {
        priority = number;
    }
};

//-------------------------------------------------------------------------------------------

// LIKEDLIST Class ---------------------------------------------------------------------------

template<class k>
class Linked_List
{
private:
    Node<k>* head;
    int count;
    int Size;
public:
    Linked_List()
    {
        head = nullptr;
        count = 0;
        Size = NULL;
    }

    Linked_List(int size) :head(nullptr), count(0), Size(size) {}
    /*void create_array(int size)
    {
        Size = size;
        Node<t>* new_element = new Node<t>(NULL);
        head=new_element
    }*/

    void set_size(int number)
    {
        Size = number;
    }

    bool is_empty()
    {
        if (count == 0) return true;
        else return false;
    }

    bool is_full()
    {
        if (count == Size) return true;
        else return false;
    }

    int get_count() { return count; }
    // if only one parameter is input, by default will append. Else, will insert at specified position
    void insert(k value)
    {
        Node<k>* To_insert = new Node<k>(value);
        if (is_empty())
        {
            head = To_insert;
        }
        else
        {
            /*if (is_full())
            {
                cout << "Sorry, The list is full!";
            }*/
            //else { 
                Node<k>* current;
                current = head;
                for (int i = 0; i < count; i++)
                {
                    current = current->get_next();
                }

                current->set_next(To_insert);
            //}

        }
        count++;
    }

 
    //------------------------------------------------------------------------------------------------------------
    void insert(k value, int index)
    {
        Node<k>* To_insert = new Node<k>(value);
        if (index > count) cout << "out of range!";
        else if (index == count) insert(value);
        else {
            if (is_full())
            {
                cout << "Sorry, The list is full!";
            }
            else {
                Node<k>* current;
                current = head;
                if (index == 0)
                {
                    Node<k>* temp;
                    temp = head;
                    head = To_insert;
                    head->set_next(temp);
                }

                else {
                    for (int i = 0; i < index; i++)
                    {
                        current = current->get_next();
                    }
                    Node<k>* temp;
                    temp = current->get_next();
                    current->set_next(To_insert);
                    To_insert->set_next(temp);
                }
            }
            count++;
        }
    }



    void insert(k value, int index,int priority)
    {
        Node<k>* To_insert = new Node<k>(value,priority);
        if (index > count) cout << "out of range!";
        else {
            if (is_empty())
            {
                head = To_insert;
            }
            else {
                Node<k>* current;
                Node<k>* before_current;
                current = head;
                if (index == 0)
                {
                    Node<k>* temp;
                    temp = head;
                    head = To_insert;
                    head->set_next(temp);
                }

                else {
                    for (int i = 1; i < index; i++)
                    {
                        before_current = current;
                        current = current->get_next();
                    }
                    Node<k>* temp;

                }
            }
            count++;
        }
    }




    void insert2(k value,int priority)
    {
        Node<k>* To_insert = new Node<k>(value,priority);
        if (is_empty())
        {
            head = To_insert;
        }
        else
        {
            if (is_full())
            {
                cout << "Sorry, The list is full!";
            }
            else {
                Node<k>* current;
                current = head;
                for (int i = 0; i < count-1; i++)
                {
                    current = current->get_next();
                }

                current->set_next(To_insert);
            }

        }
        count++;
    }

    //------------------------------------------------------------------------------------------------------------

    void delete_node(int index)
    {
        if (is_empty()) cout << "list is already empty";
        else {
            if (index == 0)
            {
                Node<k>* temp;
                temp = head;
                head = head->get_next();
                delete temp;
            }
            else
            {
                Node<k>* temp;
                temp = get_node(index);
                get_node(index - 1)->set_next(get_node(index + 1));

            }
            count--;
        }
    }

    //------------------------------------------------------------------------------------------------------------
    Node<k>* get_node(int index)
    {
        Node<k>* current;
        current = head;
        if (index == 0) return current;
        for (int i = 0; i < index; i++)
        {
            current = current->get_next();
        }
        return current;
    }


    k get_value(int index)
    {
        Node<k>* selected_node;
        selected_node = get_node(index);
        k item = selected_node->get_item();
        return item;
    }

    k* get_value_pointer(int index)
    {
        Node<k>* selected_node;
        selected_node = head;
        for (int i = 0; i < index; i++)
        {
            selected_node = selected_node->get_next();
        }
        k value = selected_node->get_item();
        k* value_ptr = &value;
        return value_ptr;
    }


    //------------------------------------------------------------------------------------------------------------

   /* int get_priority_num(int index)
    {

        Node<t>* selected_node;
        selected_node = get_node(index);
        return selected_node->get_priority();
    }*/

    int get_priority_index()
    {
        int initial = 0;
        Node<k>* current;
        Node<k>* priority_node;
        current = head;
        int i;
        for (i = 0; i < count; i++)
        {

            priority_node = current;
            initial = priority_node->get_priority();
            if (initial != 0)
            {
                return i;
            }
            current = current->get_next();

        }
        return i;
    }

    //------------------------------------------------------------------------------------------------------------;

    void set_value(k value, int index)
    {
        Node<k>* selected_node;
        selected_node = get_node(index);
        return selected_node->set_item(value);
    }
    //------------------------------------------------------------------------------------------------------------

    void display_all()
    {
        Node<k>* current;
        current = head;
        for (int i = 0; i < count; i++)
        {
            cout << current->get_item() << " ";
            current = current->get_next();
        }
    }

    void create_array(int array_size)
    {
        Node<k>* current = new Node<k>;
        Size = array_size;
        head = current;
        count++;
        for (int i = 1; i < array_size; i++)
        {
            Node<k>* next_node = new Node<k>;
            current->set_next(next_node);
            current = next_node;
            count++;
        }
    }


};


template<class j>
class Queue
{
private:
    int queue_size;
    Linked_List<j> linked_queue;
public:
    void set_size(int number)
    {
        queue_size = number;
    }
    Queue()
    {
    }
    Queue(int number)
    {
        queue_size = number;
        linked_queue.set_size(queue_size);

    }

    int get_count()
    {
        return linked_queue.get_count();
    }

    void enqueue(j value)
    {
        linked_queue.insert(value,0);
        //count++;
    }

    void priority_enqueue(j value, int priority)
    {

        if (get_count() == 0) linked_queue.insert(value, 0, priority);
        else if (priority == 1)
        {
            linked_queue.insert(value);
        }
        else
        {
            linked_queue.insert(value, linked_queue.get_priority_index(),priority);
        }
    }

    j dequeue()
    {
        if (linked_queue.is_empty()) cout << " The queue is already empty!!";
        else
        {
            j value;
            value = linked_queue.get_value(0);
            linked_queue.delete_node(0);
            //count--;
            return value;
        }
    }
    void display_all()
    {
        linked_queue.display_all();
    }

};
/*int main()
{
    Linked_List<int> test(9);
    test.insert(7);
    test.insert(8);
    test.insert(9);
    test.insert(1);
    test.set_value(3, 2);
    test.insert(4, 2);
    test.display_all();

    Queue<int> test(9);
    test.enqueue(1);
    test.enqueue(9);
    test.enqueue(8);
    test.enqueue(7);
    cout << test.dequeue()<<" ";
    cout << test.dequeue()<<" ";
    cout << test.dequeue() << " ";
    cout << test.dequeue() << " ";
    cout << test.dequeue() << " ";
    cout << test.dequeue() << " ";
    cout << test.dequeue() << " ";
    cout << test.dequeue() << " ";
    return 0;
}
*/

#endif // !DATASTRUCTURES
