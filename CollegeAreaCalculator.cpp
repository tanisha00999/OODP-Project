#include <iostream>
#include <string>
#include <vector>
using namespace std;

// define Department class
template <typename T>
class Department {
    private:
        string name;
        int numRoomsPerFloor;
        int numFloors;
        T area;
    public:
        Department(string deptName, int floors, int rooms) { //Paramaterized                                                    Constructor
        if (floors <= 0 || rooms <= 0) {
                throw invalid_argument("Number of floors and rooms per floor must be positive.");
            }
            name = deptName;
            numFloors = floors;
            numRoomsPerFloor = rooms;
            area = calculateArea();
        }
        virtual string getName() {
            return name;
        }
        inline int getNumFloors() {
            return numFloors;
        }
        int getNumRoomsPerFloor() {
            return numRoomsPerFloor;
        }
        T getArea() {
            return area;
        }
         // overload the "+" operator to calculate the total area of two departments
        friend Department operator+(const Department& dept1, const Department& dept2) {
        Department result(dept1.name + " & " + dept2.name, dept1.numFloors + dept2.numFloors, dept1.numRoomsPerFloor);
            result.area = dept1.area + dept2.area;
            return result;
        }

    private:
        T calculateArea() {

            T floorArea = numRoomsPerFloor * 50; //  room is 50 sq. m.
            T totalArea = floorArea * numFloors;
            return totalArea;
        }
};
   

//Inheritance
class ComputerScience : public Department<double> {
    public:
        ComputerScience(int floors, int rooms) : Department("Computer Science", floors, rooms) {}
         string getName() override {
            return "CS Department";
        }
};

class Mechanical : public Department<int> {
    public:
        Mechanical(int floors, int rooms) : Department("Mechanical Engineering", floors, rooms) {}
};

class Chemical : public Department<double> {
    public:
        Chemical(int floors, int rooms) : Department("Chemical Engineering", floors, rooms) {}
};

class Civil : public Department<double> {
    public:
        Civil(int floors, int rooms) : Department("Civil Engineering", floors, rooms) {}
};

class Bio : public Department<double> {
    public:
        Bio(int floors, int rooms) : Department("Bio Engineering", floors, rooms) {}
};

int main() {
  try{  
    cout<<"***Welcome to LiteCoder's Campus**\n\n";
    cout<<"***Online Area Calculator**\n"<<endl;
    // create departments and calculate their areas
    ComputerScience csDept(7, 20);
    Mechanical mDept(3, 15);
    Chemical chemDept(5, 18);
    Civil cDept(9,15);
    Bio BDept(6,14);

    // print the information about the departments
    cout << "Department Name: " << csDept.getName() << endl;
    cout << "Number of Floors: " << csDept.getNumFloors() << endl;
    cout << "Number of Rooms per Floor: " << csDept.getNumRoomsPerFloor() << endl;
    cout<<"Each room is of 50 sq. m. So the Area will be: "<<csDept.getNumFloors()<<" X 50 X "<<csDept.getNumRoomsPerFloor()<<endl;
    cout << "Area: " << csDept.getArea() << " sq. m." << endl ;
    
    cout<<"----------------------------------------------------------\n";

    cout << "Department Name: " << mDept.getName() << endl;
    cout << "Number of Floors: " << mDept.getNumFloors() << endl;
    cout << "Number of Rooms per Floor: " << mDept.getNumRoomsPerFloor() << endl;
       cout<<"Each room is of 50 sq. m. So the Area will be: "<<mDept.getNumFloors()<<" X 50 X "<<mDept.getNumRoomsPerFloor()<<endl;
    cout << "Area: " << mDept.getArea() << " sq. m." << endl ;
    
     cout<<"----------------------------------------------------------\n";

    cout << "Department Name: " << chemDept.getName() << endl;
    cout << "Number of Floors: " << chemDept.getNumFloors() << endl;
    cout << "Number of Rooms per Floor: " << chemDept.getNumRoomsPerFloor() << endl;
       cout<<"Each room is of 50 sq. m. So the Area will be: "<<chemDept.getNumFloors()<<" X 50 X "<<chemDept.getNumRoomsPerFloor()<<endl;
    cout << "Area: " << chemDept.getArea() << " sq. m." << endl;
    
     cout<<"----------------------------------------------------------\n";
    
    cout << "Department Name: " << cDept.getName() << endl;
    cout << "Number of Floors: " << cDept.getNumFloors() << endl;
    cout << "Number of Rooms per Floor: " << cDept.getNumRoomsPerFloor() << endl;
       cout<<"Each room is of 50 sq. m. So the Area will be: "<<cDept.getNumFloors()<<" X 50 X "<<cDept.getNumRoomsPerFloor()<<endl;
    cout << "Area: " << cDept.getArea() << " sq. m." << endl ;
    
     cout<<"----------------------------------------------------------\n";
    
    cout << "Department Name: " << BDept.getName() << endl;
    cout << "Number of Floors: " << BDept.getNumFloors() << endl;
    cout << "Number of Rooms per Floor: " <<BDept.getNumRoomsPerFloor() << endl;
       cout<<"Each room is of 50 sq. m. So the Area will be: "<<BDept.getNumFloors()<<" X 50 X "<<BDept.getNumRoomsPerFloor()<<endl;
    cout << "Area: " << BDept.getArea() << " sq. m." << endl;
    
     cout<<"----------------------------------------------------------\n";
     

     
    cout<<"-------------------------------------------------------------\n";
    Department<double> dept1("Computer Science", 7, 20);
    Department<double> dept2("Chemical Engineering", 5, 18);
    Department<double> dept3("Civil Engineering", 9, 15);
    Department<double> dept4("Mechanical Engineering", 3, 15);
    Department<double> dept5("Bio Engineering", 6, 14);
    Department<double> dept6 = dept1+dept2+dept3+dept4+dept5;
    
    cout << "Total Area of the department: " << dept6.getArea() << " sq. m." << endl;
  }
  catch (invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    }
    return 0;
}