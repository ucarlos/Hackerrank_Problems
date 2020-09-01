/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 09/01/2020 at 05:03 PM
 * 
 * AttributeParser.cc
 * We have defined our own markup language HRML. In HRML, each element consists 
 * of a starting and ending tag, and there are attributes associated with each 
 * tag. Only starting tags can have attributes. We can call an attribute by 
 * referencing the tag, followed by a tilde, '~' and the name of the attribute. 
 * The tags may also be nested. 
 *
 * 
 * -----------------------------------------------------------------------------
 */

// The opening tags follow the format:
// <tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
// The closing tags follow the format:
// </tag-name>

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <memory>
using namespace std;



struct Variable{
    Variable()=default;
    Variable(const string &str) :value{str} { }

    string value{};
};

class Tag{
public:
    Tag()=default;
    Tag(const string &str) : name{str} { }
    Tag(const string &str, const vector<Tag*> &children,
	vector<Variable> &var_list){
	this->name = str;
	this->children = children;
	this->var_list = var_list;
    }

    // Kill me.
    
private:
    string name;
    vector<Tag*> children;
    vector<Variable> var_list;  
};

// Global Variables:
list<Tag*> stack;
map<string, Tag> xml;

void read_line_input(istream &is);
int main(void){

    
}
