/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/22/2020 at 01:44 PM
 *
 * Inherited_Code.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

struct BadLengthException : std::exception {
    explicit BadLengthException(int v);
    const char * what() const noexcept override;
private:
    int val;
    std::string message{};
};

BadLengthException::BadLengthException(int v) {
    val = v;
    ostringstream os;
    os << val;
    message = os.str();
}

const char * BadLengthException::what() const noexcept {
    return message.c_str();
}

//------------------------------------------------------------------------------
// Don't Edit this!
//------------------------------------------------------------------------------

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5)
	throw BadLengthException(n);
    
    for (int i = 0; i < n-1; i++) 
	if (username[i] == 'w' && username[i+1] == 'w') 
	    isValid = false;
	
    
    return isValid;
}

int main() {
    int T; cin >> T;
    while(T--) {
	string username;
	cin >> username;
	try {
	    bool isValid = checkUsername(username);
	    if(isValid) {
		cout << "Valid" << '\n';
	    } else {
		cout << "Invalid" << '\n';
	    }
	} catch (BadLengthException e) {
	    cout << "Too short: " << e.what() << '\n';
	}
    }
    return 0;
}
