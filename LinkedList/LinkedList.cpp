#include <iostream>
/**
 * This is a Singly Linked List. It is capable of doing things a regular ARRAY could do. 
*/
template <typename T>
class LinkedList
{
private:
    int _size = 0;

    /**
     * Basic node structure that contains value and pointer pairs.
    */
    struct node
    {
        T value;
        node *next;
        node(const T &_value = 0, node *_next = NULL)
        {
            value = _value;
            next = _next;
        }
    };

    node *begin() const
    {
        return root;
    }
    node *end() const
    {
        return NULL;
    }

    node *root = NULL;

public:
    LinkedList()
    {
    }
    ~LinkedList()
    {
    }

    const int size() const
    {
        return _size;
    }
    const bool is_empty() const
    {
        return begin() == end();
    }

    void push_back(const T &item)
    {
        if (!is_empty())
        {
            node *tmp = begin();

            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new node(item);
            _size++;
        }
        else
        {
            root = new node(item);
            _size++;
        }
    }

    const T value_at(int index) const
    {
        if (index < 0 || index >= _size)
        {
            system("color a");
            std::cerr << "Out of Range!\n";
            std::cin.get();
            std::exit(0);
        }
        node *tmp = begin();
        int count = 0;
        while (tmp->next != NULL)
        {
            if (count == index)
            {
                return tmp->value;
            }
            tmp = tmp->next;
            count++;
        }
        return tmp->value;
    }

    void push_front(const T &item)
    {
        if (!is_empty())
        {
            node *tmp = new node(item);

            tmp->next = root;
            root = tmp;
            _size++;
        }
        else
        {
            root = new node(item);
            _size++;
        }
    }

    void pop_front()
    {
        if (is_empty())
        {
            std::cerr << "List is Empty!\n";
            return void();
        }
        else
        {
            delete root;
            root = root->next;
            _size--;
        }
    }

    const void print() const
    {
        if (is_empty())
        {
            std::cerr << "List is Empty!\n";
            return void();
        }
        else
        {
            for (int i = 0; i < size(); i++)
            {
                std::cout << value_at(i) << " ";
            }
            std::cout << "\n";
        }
    }

    void pop_back()
    {
        if (is_empty())
        {
            std::cerr << "List is Empty!\n";
            return void();
        }
        else if (size() == 1)
        {
            delete root;
            root = NULL;
            _size--;
        }
        else
        {
            node *tmp = begin();

            while (tmp->next->next != NULL)
            {
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = NULL;
            _size--;
        }
    }

    const T &front() const
    {
        return root->value;
    }

    const T &back() const
    {
        node *tmp = begin();

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    void insert(int index, const T &item)
    {
        if (index < 0 || index > _size)
        {
            system("color a");
            std::cerr << "Out of Range!\n";
            std::cin.get();
            std::exit(0);
        }
        else if (index == 0)
            push_front(item);
        else if (index == size())
            push_back(item);
        else
        {
            int count = 0;
            node *tmp = begin();
            while (tmp->next != NULL)
            {
                if (count == index - 1)
                {
                    node *newnode = new node(item, tmp->next);

                    tmp->next = newnode;
                    _size++;
                    break;
                }
                else
                {
                    tmp = tmp->next;
                    count++;
                }
            }
        }
    }

    void erase(int index)
    {
        if (index < 0 || index >= _size)
        {
            system("color a");
            std::cerr << "Out of Range!\n";
            std::cin.get();
            std::exit(0);
        }
        else if (index == 0)
            pop_front();
        else if (index == size() - 1)
            pop_back();
        else
        {
            node *tmp = begin();
            int count = 0;
            while (tmp != NULL)
            {
                if (count == index - 1)
                {
                    node *point = tmp->next->next;

                    delete tmp->next;
                    tmp->next = point;
                    _size--;
                    break;
                }
                else
                {
                    tmp = tmp->next;
                    count++;
                }
            }
        }
    }

    const T value_n_from_end(int n)
    {
        if (n <= 0 || n > size())
        {
            system("color a");
            std::cerr << "Out of Range!\n";
            std::cin.get();
            std::exit(0);
        }
        else if (is_empty())
        {
            system("color a");
            std::cerr << "List is Empty!\n";
            std::cin.get();
            std::exit(0);
        }
        else if (n == 1)
            return back();
        else if (n == size())
            return front();
        else
        {
            int item_index = size() - n;
            int count = 0;
            node *tmp = begin();
            while (tmp->next != NULL)
            {
                if (count = item_index)
                {
                    tmp = tmp->next;
                    return tmp->value;
                }
                else
                {
                    tmp = tmp->next;
                    count++;
                }
            }
        }
    }

    void reverse()
    {
        if (is_empty())
        {
            system("color a");
            std::cerr << "List is Empty!\n";
            std::cin.get();
            std::exit(0);
        }
        else if (size() == 1)
        {
            return void();
        }
        else
        {
            node *pointer_front = begin();
            node *pointer_back = begin();

            T tmp_value_front;
            T tmp_value_back;

            for (int i = 0; i < size() / 2; i++)
            {

                for (int j = 0; j < i; j++)
                {
                    pointer_front = pointer_front->next;
                }
                tmp_value_front = pointer_front->value;

                for (int k = 0; k < size() - i - 1; k++)
                {
                    pointer_back = pointer_back->next;
                }
                tmp_value_back = pointer_back->value;

                pointer_front->value = tmp_value_back;
                pointer_back->value = tmp_value_front;

                pointer_front = begin();
                pointer_back = begin();
            }
        }
    }

    void remove_value(const T &value)
    {
        node *tmp = begin();

        if (is_empty())
        {
            std::cerr << "List is Empty!\n";
        }
        else if (tmp->value == value)
        {
            erase(0);
        }
        else
        {
            int count = 1;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
                if (tmp->value == value)
                {
                    erase(count);
                }
                else
                {
                    count++;
                }
            }
        }
    }
};