#include <iostream>
#include <fstream>
#include <vector>

using namespace std ;

class CustomException : exception {

    private : string msg ;
    public:
        CustomException(){
            CustomException("File not found.") ;
        }
        CustomException(string msg){
            this->msg = msg ;
        } 
        string getError(){
            return msg ;
        }
} ;

struct InventoryItem {
    string item_description, date_added_to_inventory,
           quantity,wholesale_cost, retail_cost ;
} ;

const string INVENTORY_FILE = "inventory.dat" ;
const char C_STRING_TERMINATION_CHARACTER = '\0' ;
const int EXIT = -1, ADD = 0, DISPLAY = 1, UPDATE = 2,
          DESCRIPTION_MAX_CHARS = 15, MAX_QUANITTY = 5, 
          MAX_PRICE = 8, MAX_DATE = 10 ;

int promptMenu() ;
vector<InventoryItem> openInventory() ;
void closeInventory(vector<InventoryItem>) ;
InventoryItem create_new_item() ;
void showInventory(vector<InventoryItem>) ;
string readMember(fstream&,char*) ;

int main(){
    
    vector<InventoryItem> the_inventory = openInventory() ;

    int selection ;

    while (true) {

        selection = promptMenu() ;

        if (selection == EXIT)
            break ;

        switch(selection){
            case ADD:{
                InventoryItem new_item = create_new_item() ;
                the_inventory.push_back(new_item) ;
                break ;
            }case DISPLAY:{
                showInventory(the_inventory) ;
                break ;
            }case UPDATE:{
                break ;
            }
        }
    }

    closeInventory(the_inventory) ;

}
vector<InventoryItem> openInventory(){

    vector<InventoryItem> loaded_inventory ;
    fstream input_stream(INVENTORY_FILE,ios::binary | ios::in) ;
    if (!input_stream)
        throw CustomException(INVENTORY_FILE + " not found.") ;
    
    input_stream.seekg(0,ios::end) ;
    int file_size = input_stream.tellg() ;
    input_stream.seekg(0,ios::beg) ;

    for (int i = 0 ; i < file_size ; i++){

        InventoryItem item ;
        char *description_buffer = new char[DESCRIPTION_MAX_CHARS+1],
             *date_buffer = new char[MAX_DATE+1],
             *quantity_buffer = new char[MAX_QUANITTY+1],
             *wholesale_buffer = new char[MAX_PRICE+1],
             *retail_buffer = new char[MAX_PRICE+1];
            
        input_stream.read(description_buffer,sizeof(DESCRIPTION_MAX_CHARS)) ;
        description_buffer[DESCRIPTION_MAX_CHARS] = C_STRING_TERMINATION_CHARACTER ;

        input_stream.read(date_buffer,sizeof(MAX_DATE)) ;
        date_buffer[MAX_DATE] = C_STRING_TERMINATION_CHARACTER ;
        
        input_stream.read(quantity_buffer,sizeof(MAX_QUANITTY)) ;
        quantity_buffer[MAX_QUANITTY] = C_STRING_TERMINATION_CHARACTER ;
        
        input_stream.read(wholesale_buffer,sizeof(MAX_PRICE)) ;
        wholesale_buffer[MAX_PRICE] = C_STRING_TERMINATION_CHARACTER ;
        
        input_stream.read(retail_buffer,sizeof(MAX_PRICE)) ;
        retail_buffer[MAX_PRICE] = C_STRING_TERMINATION_CHARACTER ;

        item.item_description = description_buffer ;
        item.date_added_to_inventory = date_buffer ;
        item.quantity = quantity_buffer ;
        item.retail_cost = retail_buffer ;
        item.wholesale_cost = wholesale_buffer ;

        loaded_inventory.push_back(item) ;

        delete[] description_buffer ;
        delete[] date_buffer ;
        delete[] quantity_buffer ;
        delete[] wholesale_buffer ;
        delete[] retail_buffer ;

    }
    input_stream.close() ;
    return loaded_inventory ;

}
void closeInventory(vector<InventoryItem> the_inventory){

    ofstream output_stream(INVENTORY_FILE,ios::binary | ios::in | ios::out) ;
    for (InventoryItem i : the_inventory){
        
    }

}
int promptMenu(){
    return -1 ;
}
InventoryItem create_new_item(){

}
void showInventory(vector<InventoryItem>){

}
