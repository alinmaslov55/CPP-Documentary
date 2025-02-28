#include <iostream>
#include <string>
#include <vector>
#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <deque>

std::deque<char> queue;

boost::optional<char> get_data(){
    if(!queue.empty()){
        return boost::optional<char>(queue.back());
    } else {
        return boost::optional<char>();
    }
}

int main(){
    boost::variant<nullptr_t, char> v;

    boost::optional<char> op; // op is unitialized, co char is constructed

    op = 'A';
    op = get_data();

    if(!op){
        std::cout << "No data is available" << std::endl;
    } else {
        std::cout << "op contains: " << op.get() << std::endl;// crash if op is uninitialized
        std::cout << "op contains: " << *op << std::endl;// crash if op is uninitialized
    }

    op.reset(); // reset op to uninitialized state
    std::cout << op.get_value_or('z') << std::endl; 
    // returns 'z' is is unitialized
    char* p = op.get_ptr(); // returns null if op is empty

    struct A {
        std::string name;
        int value;
    };
    A a;
    boost::optional<A> opA0; // constructor is not called
    boost::optional<A> opA(a); // a is copy-constructed into opA
    std::cout << opA->name << " " << opA->value << std::endl;

    // Pointer
    boost::optional<A*> opAP(&a);
    (*opAP)->name = "Bob";

    // Reference
    boost::optional<A&> opAR(a);
    opAR->name = "John";

    
    return 0;
}