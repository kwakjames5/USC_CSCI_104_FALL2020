#include <iostream>
#include <string>
#include <memory>
using namespace std;


class GroceryList {
    public:
    GroceryList();
GroceryList(size_t n);
	GroceryList(const GroceryList& other);
    ~GroceryList();
    void addItem(string item);
    void removeItem(string item);
    void merge(const GroceryList& other);
    const string& getItem(size_t position) const;
    void printList() const;
    bool empty() const;
    size_t size()const;
    GroceryList& operator=(const GroceryList& rhs);
    private:
    size_t num_items;
    size_t list_size;
    unique_ptr<string[]> list;
    void doubleList();
};

GroceryList::GroceryList(){
    num_items = 0;
    list_size = 5;
    list = make_unique<string []>(5);
}
GroceryList::GroceryList(size_t n){
    num_items = 0;
    list_size = n;
    list = make_unique<string []>(n);
}

GroceryList::GroceryList(const GroceryList& other)
{
	list = make_unique<string []>(other.list_size);
	num_items = other.num_items;
	list_size = other.list_size; 
	for(int i = 0; i < num_items; i++)
	{
		list[i] = other.list[i];
	}
}

GroceryList::~GroceryList(){
    //cout <<"destroying list" <<endl;
}

GroceryList& GroceryList::operator=(const GroceryList& rhs)
{
	if(&rhs == this)
	{
		return *this;
	}

	list = make_unique<string []>(other.list_size);
	num_items = other.num_items;
	list_size = other.list_size; 
	for(int i = 0; i < num_items; i++)
	{
		list[i] = other.list[i];
	}

	return *this;
}

bool GroceryList::empty() const {
    return (num_items==0);
}

size_t GroceryList::size() const {
    return num_items;
}

void GroceryList::printList() const {
    for (size_t i = 0; i < num_items; i++){
       cout << list[i] << " ";
    }
    cout << endl;
}

void GroceryList::removeItem(string item){
    size_t i, j;
    for (i = 0; i < num_items; i++){
       if (list[i] == item) break;
    }
    if (i == num_items) return;
    for (j = i; j < num_items-1; j++){
       list[j] = list[j+1];
    }
    list[j]="";
    num_items--;
}

const string& GroceryList::getItem(size_t position) const{
    // Add error checking that position is in list
    return list[position];
}

void GroceryList::doubleList(){
    unique_ptr<string[]> old_list(list.release());
    list = make_unique<string []>(list_size*2);
    for (size_t i = 0; i < num_items; i++){
        list[i] = old_list[i];
    }
    list_size *= 2;
}

void GroceryList::addItem( string item){
    if( num_items == list_size) doubleList();
    list[num_items] = item;
    num_items++;
}
void GroceryList::merge(const GroceryList& other){
    size_t limit = other.size();
    for (size_t i = 0; i  < limit; i++){
        this->addItem(other.getItem(i));
    }
}

int main()
{
   
   GroceryList list1, list2;
   list1.printList();
   list1.addItem("apples");
   list1.addItem("bananas");
   list1.addItem("peaches");
   list1.printList();
   list2.addItem("onions");
   list2.addItem("peppers");
   list2.addItem("broccoli");
   list1.merge(list2);
   list1.printList();
   list1.removeItem("broccoli");
   list1.printList();
  
}
