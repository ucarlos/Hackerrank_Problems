/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/22/2020 at 01:38 AM
 *
 * Box_It.cc
 *
 * -----------------------------------------------------------------------------
 */

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


class Box {
public:
    Box() =default;
    Box(int l, int b, int h) : length{l}, breadth{b}, height{h} { }

    int getLength() { return length; }
    int getHeight() { return height; }
    int getBreath() { return breadth; }

    long long CalculateVolume() { return (long long)height * length * breadth; }
    bool operator<(const Box &b1);
private:
    int height{0};
    int length{0};
    int breadth{0};
    friend ostream& operator<<(ostream &os, Box &b);
};

ostream& operator<<(ostream &os, Box &b){
    return os << b.getLength() << " " << b.getBreath() << " "
	      << b.getHeight() << endl;
}

bool Box::operator<(const Box &b1){
    if (length != b1.length) return length < b1.length;
    else if (breadth != b1.breadth) return breadth < b1.breadth;
    else if (height != b1.height) return height < b1.height;
    else return false;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
