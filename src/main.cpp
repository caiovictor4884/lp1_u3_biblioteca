
#include <iostream>
using namespace std;
#include <vector>

    enum Estado {
    EMPRESTADO,
    DISPONÍVEL,
    INDISPONÍVEL
    };
    
    

    class Item{ 
    public: //Tudo public por enquanto para testar;
     string id;
     string nome; 
     Estado status; 
     string IdResponsavel; // qual o id da propria biblioteca // apenas id ou o objeto inteiro  como um encapsulado  
     Item(string n ,  Estado s, string ir, string i ){
         nome = n;
         id = i;
         status  = s;
         IdResponsavel = ir;
     }
    };
    
    class Person{
        public:
        string name; 
        string id; 
        Person(string n, string i){
            name = n; 
            id = i;
        }
    };
    

    
    
    


    class LibraryRepository{ // melhor chamar de bibliotecário, faz tudo o que um faria  
        public: 
        string id = "001";
        vector<Item> Items;
        vector<Person> Users;
        
        /*
        virtual void addItem(Item item) = 0; 
        virtual void removeItem(Item item) = 0;
        virtual void updateItem(Item item) = 0;
        virtual Item findItem(string name) =0;
        */ 
         void listItems(){
            cout<< "LISTANDO ITENS \n";
            for(int c = 0 ; c < Items.size() ; c++){
                cout << "NOME: " <<Items[c].nome << ", STATUS: "<<Items[c].status << ", ID do responsável: "<<Items[c].IdResponsavel;
                cout << "\n" ;
            }
            cout << "\n" ;
            cout << "\n" ;
         }
        void listUsers(){
            cout<< "LISTANDO USUÁRIOS \n";
            for(int c = 0 ; c < Users.size() ; c++){
                cout <<"NOME: " <<Users[c].name  << ", ID: " <<Users[c].id;  
                cout << "\n" ;
            }
         }

        void lendItem(Person person, Item& item, int days){
            if(item.status == DISPONÍVEL){
                item.IdResponsavel = person.id;
                item.status = EMPRESTADO;
                cout << "item " << item.nome << "("<< item.id << ") emprestado para "<< person.name<< "\n\n";
            }else{
                cout<< "item "<< item.nome << "("<< item.id << ") não disponível para empréstimo \n\n";
            }

        }
        
        void returnItem(Person person, Item& item, int days){
            if(item.status == 0){
                item.IdResponsavel = "0";
                item.status = DISPONÍVEL;
                cout << "item " << item.nome << "("<< item.id << ") Devolvido por "<< person.name<< "\n\n";
            }else{
                cout<< "O usuário não pode devolver um livro que não possui";
            }

        }

         
        
    };


int main(){
    // CRIANDO DADOS INICIAIS PARA TESTE DOS MÉTODOS
       vector<Item> Items = {
        Item("Dom Casmurro", DISPONÍVEL, "0", "100" ),
        Item("Dom Casmurro", DISPONÍVEL, "0", "101" ),
        Item("Dom Casmurro", DISPONÍVEL, "0", "102" ),
        Item("1984",DISPONÍVEL, "0" , "200"),
        Item("1984",DISPONÍVEL, "0" , "201"),
        Item("O Hobbit", DISPONÍVEL, "0", "300" ),
        Item("Clean Code", DISPONÍVEL, "0" , "401"),
        Item("Clean Code", DISPONÍVEL, "0" , "402"),
        Item("Clean Code", DISPONÍVEL, "0" , "403"),
        Item("Clean Code", DISPONÍVEL, "0" , "404"),
        Item("Clean Code", DISPONÍVEL, "0" , "405"),
        Item("A Revolução dos Bichos", INDISPONÍVEL, "0" , "500")
    };    
    
    vector<Person> Usuarios = {
        Person("Ana", "002"),
        Person("João", "003"),
        Person("Maria", "004"),
        Person("Pedro", "005")
    };
    
    LibraryRepository Biblioteca1;
    Biblioteca1.Items = Items;
    Biblioteca1.Users = Usuarios;
    
    Biblioteca1.lendItem( Biblioteca1.Users[0],  Biblioteca1.Items[0], 20);
    
    Biblioteca1.lendItem( Biblioteca1.Users[1],  Biblioteca1.Items[0], 20); // Tentando emprestar livro já emprestado. 
    
    Biblioteca1.lendItem( Biblioteca1.Users[1],  Biblioteca1.Items[2], 20); // procurando outro livro igual. 
    
    Biblioteca1.listUsers();
    cout<<"\n\n";
    Biblioteca1.listItems();
    
    Biblioteca1.returnItem( Biblioteca1.Users[0],  Biblioteca1.Items[0], 20);
    
    

    return 0;
}
