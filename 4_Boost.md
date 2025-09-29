# Boost Library

## ```<boost/lexical_cast.hpp>```

1. is type-safe and easy-to-use
2. allows all convertion types

- standart convertion

    ```cpp
    int main(){

        /* Converting from string

        atof - Convert from string to double
        atoi - Convert from string to integer
        atol - Convert from string to long integer
        atoll - Convert from string to long long integer
        strtod - Convert from string to double
        strtof - Convert from string to float
        strtol - Convert from string to long integer
        strtold - Convert from string to long double
        strtoll - Convert from string to long long integer
        strtoul - Convert from string to unsigned long integer
        strtoull - Convert from string to unsigned long long integer

        Converting to string
        
        std::stringstream strm;
        strm << int_val;
        string s = strm.str();

        */

        return 0;
    }
    ```

- using ```<boost/lexical_cast.hpp>```

    ```cpp
    #include <iostream>
    #include <string>
    #include <boost/lexical_cast.hpp>

    int main(){

        int s = 23;

        std::string str = boost::lexical_cast<std::string>(s);

        str = "Message: " + boost::lexical_cast<std::string>('A') + "=" + boost::lexical_cast<std::string>(35.4f);

        std::cout << str << std::endl;

        int integer = boost::lexical_cast<int>("34.5"); // throws exception "bad_lexical_cast"
        integer = boost::lexical_cast<int>("3456.6", 4) // no exception thrown

        return 0;
    }
    ```

## ```<boost/variant.hpp>```

- type-safe alternative to ```union```, allowing a variable to store one of mutiple types at a time
- similar to ```std::variant``` - c++17
- is preffered ```std::variant```
- Avoids manual ```void*``` handling
- Type-safe with built-in visitor pattern for access

1. Basic

    ```cpp
    #include <boost/variant.hpp>
    #include <iostream>

    int main() {
        boost::variant<int, std::string> var; // Can hold int or string

        var = 42;
        std::cout << "Int: " << boost::get<int>(var) << "\n";

        var = "Hello, Boost!";
        std::cout << "String: " << boost::get<std::string>(var) << "\n";

        return 0;
    }
    ```

2. Accessing the stored value

    ```cpp
    if (var.which() == 0) {  // Index of current type (0 = int, 1 = std::string)
        std::cout << "Stored int: " << boost::get<int>(var) << "\n";
    } else {
        std::cout << "Stored string: " << boost::get<std::string>(var) << "\n";
    }
    ```

3. Error handling

    ```cpp
    try {
        std::cout << boost::get<int>(var) << "\n"; // Works if var holds int
    } catch (const boost::bad_get& e) {
        std::cout << "Wrong type access: " << e.what() << "\n";
    }
    ```

4. Using visitors (```boost::static_visitor```)

```cpp
#include <boost/variant.hpp>
#include <iostream>

struct PrintVisitor : public boost::static_visitor<void> {
    void operator()(int i) const {
        std::cout << "Integer: " << i << "\n";
    }
    void operator()(const std::string& s) const {
        std::cout << "String: " << s << "\n";
    }
};

int main() {
    boost::variant<int, std::string> var = "Hello";
    boost::apply_visitor(PrintVisitor(), var); // Calls the correct overload

    var = 99;
    boost::apply_visitor(PrintVisitor(), var); // Calls integer overload
}
```

## ```<boost/any>```

- data that is used to hold any type of data
- is very flexible
- flexibility is not free, as it uses dynamic storage
- no overload of ```std::cout <<``` for ```boost::any```
- has alternative ```std::any``` - c++17

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <boost/any.hpp>
#include <typeinfo> // required for typeid()

int main(){
    boost::any x, y, z;


    x = std::string("Hello");

    x = 2.3;
    y = 'z';
    z = std::vector<int>();

    std::cout << boost::any_cast<char>(y) << std::endl;
    // return a copy of y's data

    std::cout << boost::any_cast<int>(x) << std::endl;
    // throws exception: "bad_any_cast"

    boost::any_cast<std::vector<int>>(z).push_back(23);
    int i = boost::any_cast<std::vector<int>>(z).back();
    // will crash because any_cast returns a copy of the vector

    if(x.empty()){
        std::cout << "x is empty" << std::endl;
    }
    
    if(x.type() == typeid(char)){ // runtime verification
        std::cout << "is a char: " << boost::any_cast<char>(x) << std::endl;
    }


    std::vector<boost::any> m;
    m.push_back('a');
    m.push_back("asdfghjkl");
    m.push_back(123);


    struct Property{
        std::string name;
        boost::any value;
    };
    std::vector<Property> properties;

    return 0;
}
```

## ```boost/optional```

- wrapper that can hold either
    1. A valid value of type T
    2. an empty(*null*) state
- Safer alternative to raw pointers
- Avoids using special values like ```-1``` or "N/A"
- Useful for function return values where ```T``` might not always exist
- Better alternative is ```std::optional```

```cpp
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
```
