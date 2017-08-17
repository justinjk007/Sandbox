#include "../include/Animal.h"

#include "../include/animallib_Export.h"

int main(int argc, char *argv[]){
    //Create a new animal instance with name Dog
    Animal animal("Dog");

    //try to call the class's print_name method
    animal.print_name();
    return (0);
}
