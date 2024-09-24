#include <iostream>
using namespace std;

class foodItem {
    string foodName;
    int foodPrice;

    public:
    foodItem(){foodName = "none"; foodPrice=0;}
    foodItem(string name, int price):foodName(name), foodPrice(price){}
    void setFoodName(string name){foodName = name;}
    void updatePrice(int price){ foodPrice = price;}
    string getFoodName()const{return foodName;}
    int getFoodPrice()const{return foodPrice;}
};

class foodOrder: public foodItem{
    int quantity;
    public:
    foodOrder(){}
    foodOrder(string name, int price, int q=0):foodItem(name,price), quantity(q){}
    void setQuantity(int q){quantity = q;}
    int getQuantity()const{return quantity;}
    int  getTotalPrice()const{return quantity * getFoodPrice();}
};

int menu(const foodOrder order[]){
    cout << "Order Menu\n\n";
    for(int i=0; i<5; i++){
        cout << i + 1 << ". " << order[i].getFoodName() << " - " << order[i].getFoodPrice() << " Taka\n";
    }
    cout << "0. conform order\n";

    cout << "\n select item\n";
    int choice;
    cin >> choice;
    return choice;
}


int totalPrice(const foodOrder item[]){
    int total=0;
    for(int i=0; i<5; i++){
        if(item[i].getQuantity()!=0)
         total += item[i].getTotalPrice();
    }

    return total;
}

void confirm(const foodOrder item[]){
    cout << "Name \t Price\tQuantity\n\n";
    for(int i=0; i<5; i++){
        if(item[i].getQuantity()!=0)
        cout << item[i].getFoodName() << " - " << item[i].getFoodPrice() << " - " << item[i].getQuantity() << "\n";  
    }
    cout << "Total Price: " << totalPrice(item);
}

void selectOrder(foodOrder item[]){
    int choice;
    do{
         choice = menu(item);
    
        if(choice==0){
            confirm(item);
        } else{
            cout << "Quantity: ";
            int quantity;
            cin >> quantity;
            item[choice-1].setQuantity(quantity);
        }
        
    }while(choice!=0);
}


int main(){
    foodOrder order[5];
    order[0] = foodOrder("Burger", 120);
    order[1] = foodOrder("Hot Dog", 180);
    order[2] = foodOrder("Chicken Nuggets (6 pcs)", 200);
    order[3] = foodOrder("Grilled Chicken Wrap", 250);
    order[4] = foodOrder("Chicken Sandwich", 100);
    selectOrder(order);
    
    return 0;
}