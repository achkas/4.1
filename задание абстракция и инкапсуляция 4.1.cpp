// задание абстракция и инкапсуляция 4.1.cpp.


#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

class location {
    
    
      
    std::string city ;
    std::string street;
    std::string house ;
    std::string apartment;
    
public:
   

        location(std::string city, std::string street, std::string house, std::string apartment)
    {
        
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;

    }

    void set_inc(std::string city)
    {
        this->city = city;
    }

    void set_ins(std::string street)
    {
        this->street = street;
    }

    void set_inh(std::string house)
    {
        this->house = house;
    }

    void set_ina(std::string apartment)
    {
        this->apartment = apartment;
    }

    /*std::string get_in() {
        return  city;
        
    }

    std::string get_ins() {
        
        return  street;
    }*/
    

    void setout(location* loc_in_array, int size) {
        std::ofstream rf;
        rf.open("out.txt");
        //std::cout << rf .is_open() << std::endl; 
        location temp;
        rf << size;
        rf << "\n";
        
            for (int i = 0; i < size / 2; i++) {
               
                
                temp = loc_in_array[i];
                loc_in_array[i] = loc_in_array[(size - i) - 1];
                loc_in_array[(size - i) - 1] = temp;
            }

            for (int i = 0; i < size; i++){

                rf << loc_in_array[i].city + ",  " + loc_in_array[i].street + ",  "
                    + loc_in_array[i].house + ",  " + loc_in_array[i].apartment + "\n";
            
        }               

        rf.close();

    }

   
    
  location() = default;
   
    
   

   void print_array(location* loc_in_array, int size) {
      std::cout << size << std::endl;
      for (int i = 0; i < size; ++i) {
          std::cout
              << loc_in_array[i].city << std::endl
              << loc_in_array[i].street << std::endl
              << loc_in_array[i].house << std::endl
              << loc_in_array[i].apartment << std::endl;
          std::cout << std::endl;
      }

  } 
    
};





int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    location in(" ", " ", " ", " ");   

    int size;
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;

    std::ifstream wf1;
    wf1.open("in.txt");
    // std::cout << wf1 .is_open() << std::endl;

    wf1 >> size; 
      
     location* loc_in_array = new location[size];
      for (int i = 0; i < size; ++i) {
       wf1 >> city;
       loc_in_array [i].set_inc(city);
       wf1 >> street;
       loc_in_array[i].set_ins(street);
       wf1 >> house;
       loc_in_array[i].set_inh(house);
       wf1 >> apartment;
       loc_in_array[i].set_ina(apartment);
     
 }

      wf1.close();

 in.print_array(loc_in_array, size);

 in.setout(loc_in_array, size);   

    delete[] loc_in_array;

    return 0;

    
}