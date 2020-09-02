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
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <memory>
using namespace std;



struct Variable{
    Variable()=default;
    Variable(string n, string val) : name{std::move(n)}, value{std::move(val)} { }
    friend ostream& operator<<(ostream &os, const Variable &v);
    string name;
    string value{};
};

ostream& operator<<(ostream &os, const Variable &v){
    return os << "Name: " << v.name << "\tValue: " << v.value;
}

class Tag{
public:
    Tag()=default;
    explicit Tag(string str) : name{std::move(str)} { }
    Tag(const string &str, const vector<Tag*> &children,
	vector<Variable> &var_list){
	this->name = str;
	this->children = children;
	this->var_list = var_list;
    }
    
    const string& get_name() { return name; }
    
    vector<Tag*>& get_children() { return children; }
    [[nodiscard]] const vector<Tag*>& get_children() const { return children; }

    vector<Variable>& get_var_list() { return var_list; }
    [[nodiscard]] const vector<Variable>& get_var_list() const { return var_list; }
    
    friend bool operator==(const Tag &t1, const Tag &t2);
    friend bool operator!=(const Tag &t1, const Tag &t2) { return !(t1 == t2); }
    friend ostream& operator<<(ostream &os, const Tag &t);
private:
    string name;
    vector<Tag*> children;
    vector<Variable> var_list;  
};

bool operator==(const Tag &t1, const Tag &t2){
    return t1.name == t2.name;
}

ostream& operator<<(ostream &os, const Tag &t){
    ostringstream o;
    o << "Tag Name: " << t.name << endl;
    
    // Now print children:
    o << "Children List: ";
    if (t.children.empty())
	o << "None";
    else
	for (auto &i : t.children)
	    o << i->get_name() << " ";
    o << endl;
    
    // Now print variables:
    o << "Variable List: ";
    if (!t.var_list.empty()){
	o << "\n";
	for (auto &i: t.var_list)
	    o << i << endl;
    }
    else o << "None\n";
	
    return os << o.str();
}

// Global Variables:
list<Tag*> stack;
list<Tag> tag_list;


//------------------------------------------------------------------------------
// is_endtag(): Check if the line is a endtag
//------------------------------------------------------------------------------
bool is_endtag(const string &str){
    char first_char = str.front();
    string tag_name;
    auto stack_name = stack;
    if (first_char == '/'){

	tag_name = str.substr(1);

	if (stack.empty())
	    throw runtime_error("Cannot compare a empty stack.");
	
	bool check_stack = stack.back()->get_name() == tag_name;
	if (!check_stack){
	    string error_message = "Got an endtag ";
	    error_message += tag_name;
	    error_message += " for a tag that is ended early or does not";
	    error_message += " exist yet.";		
	    throw runtime_error(error_message);
	}
	else{
	    stack.pop_back();
	    return true; // Too early?
	}
	
    }

    return false; // Not a endtag
}



//------------------------------------------------------------------------------
// adjust_stack(): If the tag is processed correctly, add it to the front
// of the stack, and then adjust the children of each tag.
// As an example, say that the stack is tag1 -> tag2, and tag3 is passed
// as parameter. tag3 is added to the stack, and tag2 will included tag3
// as its child. tag1 will then add tag2 as a child if it hasn't already.
//------------------------------------------------------------------------------
void adjust_stack(Tag &t){
    //Add the current tag to the stack
    // Show stack for debugging.
    auto stack_copy = stack;
    
    tag_list.push_back(t);
    if (stack.empty()){
	stack.push_back(&tag_list.back());
	return;
    }
    
    stack.push_back(&tag_list.back());
    stack_copy = stack;
    auto end = stack.end();
    end--;
    for (auto it = stack.begin(); it != end; it++){
	// Check if the current tag has the next tag as a child.
	// Skip if in list, otherwise add it.
	auto vector = (*it)->get_children();
	auto item = it; item++;
	auto search = find(vector.begin(), vector.end(), (*item));
	//If search is empty, add it to list.
	if (search == vector.end())
	    (*it)->get_children().push_back(*item);
	else continue;
	
	


    }
    

}

void read_line(vector<string> &token_list){
    string str = token_list[0];
    bool check = is_endtag(str);
    if (check){
	// token_list should be one if it only contains a endtag.
	if (token_list.size() > 1)
	    throw runtime_error("Endtag should not contain variables"
				" and other tokens.");
	return;
    }

    // Otherwise, create a Tag with name token_list
    Tag tag{str};
    // Search for variables if token_list > 1
    if (token_list.size() == 1){
	adjust_stack(tag);
	return; // lines with the tag name are okay!
    }

    // Otherwise, the tag will follow this pattern:
    // tag_name variable_name = value ... variable_n = value_n
    if (token_list.size() % 3 != 1){
	throw runtime_error("Tag attributes do not follow the format "
			    " tag_name variable_name = value. "
			    " You may have an extra token somewhere.");
	
    }

    //Now parse each token as a variable:
    string name, value;

    for (unsigned long i = 1; i < token_list.size(); i+= 3){
	name = token_list[i];
	value = token_list[i + 2];
	tag.get_var_list().push_back(Variable{name, value});
	
    }

    // Now adjust stack.
    adjust_stack(tag);
}

void read_input(ifstream &ifs){
    // Get a line.
    string line;
    bool check;
    stringstream ss;
    while (ifs.good()){
	// clear ss
	ss.clear();
	getline(ifs, line);
	if (line.empty()){
	    cerr << "Skipping empty line.\n";
	    continue;
	}
	    
	check = (line.front() == '<' and line.back() == '>');
	if (!check)
	    throw runtime_error("Line must start with '<' and end with '>'.");


	// Skip any lines that are <> only
	if (line.length() == 2){
	    cerr << "Skipping line with no tags.\n";
	    continue;
	}
	    
	// Remove the first and last character
	line.erase(0, 1);
	line.pop_back();
	// Now tokenize the line, by using space.
	    
	ss.str(line);
	vector<string> token_list;
	string temp;

	while (ss >> temp)
	    token_list.push_back(temp);

	read_line(token_list);
    }
}

int main(){
    // As an example, read from a ifstream
    string file_name = "../Example.txt";
    // string file_name = "./Example.txt";
    ifstream ifs{file_name, ios_base::in};
    read_input(ifs);

    // Now for each tag in tag_list, print its children, and then each variable
    for (auto &i : tag_list)
	cout << i << endl;
}
