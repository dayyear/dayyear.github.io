#include <iostream>
   #include <string>
   #include <nlohmann/json.hpp>
   
   int main() {
       // create object from string literal
       nlohmann::json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
   
       // or even nicer with a raw string literal
       auto j2 = R"(
         {
           "happy": true,
           "pi": 3.141
         }
       )"_json;
   
       // parse explicitly
       auto j3 = nlohmann::json::parse("{ \"happy\": true, \"pi\": 3.141 }");
   
       // explicit conversion to string
       std::string s = j.dump();    // {\"happy\":true,\"pi\":3.141}
   
       // serialization with pretty printing
       // pass in the amount of spaces to indent
       std::cout << j.dump(4) << std::endl;
       // {
       //     "happy": true,
       //     "pi": 3.141
       // }
   
       // store a string in a JSON value
       nlohmann::json j_string = "this is a string";
   
       // retrieve the string value (implicit JSON to std::string conversion)
       std::string cpp_string = j_string;
       // retrieve the string value (explicit JSON to std::string conversion)
       auto cpp_string2 = j_string.get<std::string>();
       // retrieve the string value (alternative explicit JSON to std::string conversion)
       std::string cpp_string3;
       j_string.get_to(cpp_string3);
       // get_ptr
       auto cpp_string4 = j_string.get_ptr<std::string *>();
       auto cpp_string5 = j_string.get_ptr<nlohmann::json::string_t *>();
       // get_ref
       auto cpp_string6 = j_string.get_ref<std::string &>();
       auto cpp_string7 = j_string.get_ref<nlohmann::json::string_t &>();
   
       // retrieve the serialized value (explicit JSON serialization)
       std::string serialized_string = j_string.dump();
   
       // output of original string
       std::cout << cpp_string << " == " << cpp_string2 << " == " << cpp_string3 << " == " << *cpp_string4 << " == " << *cpp_string5 << " == " << cpp_string6 << " == " << cpp_string7 << '\n';
       // output of serialized value
       std::cout << j_string << " == " << serialized_string << std::endl;
   
       getchar();
       return 0;
   }