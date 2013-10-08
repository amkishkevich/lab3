#include <iostream.h>
struct ListItem
{
    int value;
    ListItem* next;
    ListItem* previous;
};
class List
{
private:
    ListItem* head;
    ListItem* tail;
public:
    List(): head(NULL), tail(NULL) {}
    List(const List& l);
    ~List();
    void show();
    void pushFront(int value);
    void pushBack(int value);
    void addElement(int value, int i);

    int removeElement(int i);
    int removeFront();
    int removeBack();
};
void List::pushFront(int value)
{
    ListItem* curentItem = new ListItem;
    curentItem->value = value;
    curentItem->previous = NULL;
    curentItem->next = head;
    if(head)
        head->previous = curentItem;
    else
        tail = curentItem;
    head = curentItem;
}
void List::pushBack(int value)
{
    ListItem* curentItem = new ListItem;
    curentItem->value = value;
    curentItem->previous = tail;
    curentItem->next = NULL;
    if(tail)
        tail->next = curentItem;
    else
        head = curentItem;
    tail = curentItem;
}
void List::addElement(int value, int index)
{
    if(index == 0)
        pushFront(value);
    else
    {
        ListItem* curentItem = new ListItem;
        curentItem->value = value;
        ListItem* replasedPosition = head;
        while( index && replasedPosition)
        {
            index--;
            replasedPosition = replasedPosition-> next;
        }
        if(replasedPosition)
        {
            curentItem->previous = replasedPosition->previous;
            curentItem->next = replasedPosition;
            replasedPosition->previous->next = curentItem;
            replasedPosition->previous = curentItem;
        }
        else
            pushBack(value);
    }
}

int List::removeFront()
{
    if(head)
    {
        int value = head->value;
        ListItem* itemToRemove = head;
        if(head->next)
            head->next->previous = NULL;
        else
            tail = NULL;
        head = head->next;
        delete itemToRemove;
        return value;
    }

}
int List::removeBack()
{
    if(tail)
    {
        int value = tail->value;
        ListItem* itemToRemove = tail;
        if(tail->previous)
            tail->previous->next = NULL;
        else
            head = NULL;
        tail = tail->previous;
        delete itemToRemove;
        return value;
    }

}
int List::removeElement(int index)
{
    if(index == 0)
        return removeFront();
    else
    {
        ListItem* itemToRemove = head;
        while(index && itemToRemove)
        {
            index--;
            itemToRemove = itemToRemove->next;
        }
        if(itemToRemove==tail || !itemToRemove)
            return removeBack();
        itemToRemove->next->previous = itemToRemove->previous;
        itemToRemove->previous->next = itemToRemove->next;
        int value = itemToRemove->value;
        delete itemToRemove;
        return value;
    }
}

List::List(const List& A):head(NULL), tail(NULL)
{
    ListItem* m = A.head;
    while(m)
    {
        pushBack(m->value);
        m = m->next;
    }
}
List::~List()
{
    ListItem* m;
    while(head)
    {
        m = head;
        head = head->next;
        delete m;
    }
    head = tail = NULL;
}
void	List::show()
{
    ListItem* m = head;
    while(m)
    {
        cout<< m->value << " ";
        m=m->next;
    }
    cout<<endl;

}

int main()
{
    int t,p,k;
    List list;
    cout<<"vvedi kol-vo elementov dlia vstavki v konec"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v konec"<<endl ;
    while(t)
    {
        cin>>p;
        list.pushBack(p);
        t--;
    }
    list.show();
    cout<<"vvedi kol-vo elementov dlia vstavki v nacalo"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v nacalo"<<endl;
    while(t)
    {
        cin>>p;
        list.pushFront(p);
        t--;
    }
    list.show();
    cout<<"vvedi kol-vo elementov dlia vstavki pered indexom"<<endl;
    cin>>t;
    cout<<"vvedi element i index"<<endl;
    while(t)
    {
        cin>>p>>k;
        list.addElement(p,k);
        t--;
    }
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie iz nacala"<<endl;
    cin>>t;
    while(t)
    {
        list.removeFront();
        t--;
    }
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie pered indexom"<<endl;
    cin>>t;
    cout<<"vvedi index"<<endl;
    while(t)
    {
        cin>>k;
        list.removeElement(k);
        t--;
    }
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie iz konca"<<endl;
    cin>>t;
    while(t)
    {
        list.removeBack();
        t--;
    }
    list.show();
    system("pause");
}
