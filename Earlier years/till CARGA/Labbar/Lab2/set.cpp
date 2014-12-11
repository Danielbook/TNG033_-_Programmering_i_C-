#include <iostream>
#include "set.h"
#include <new>

//Default constructor
Set::Set ()
{
    //S�tt instansvariabler
    //Tomt setobjekt
    head = new Node(0, nullptr);
}

//Constructor creating a set
//from n integers in a non-sorted array a
//Skapar ett sorterat set
Set::Set (int a[], int n)
{
    //Pekar p� "tomt" head-objekt med nullptr
    head = new Node(0, nullptr);
    //Loopa igenom alla slots i arrayen
    for (int i = 0; i<n; i++){
        //Tempor�r head-node
        Node *temp = head;

        //Om v�rdet pekar p� inte �r nullptr samt sortera
        while (temp->next && temp->next->value < a[i]){
            temp = temp->next;
        }
        //F�r v�rdet ligger i r�tt ordning i array'n
        Node *nextptr = new Node(a[i], temp->next);
        temp->next = nextptr;
    }
}

//copy constructor
Set::Set (const Set &source)
{
    head = new Node(0, nullptr);

    //*tempSet, Pekare p� f�rsta elementet i S1.head, som �r noden med 1 fr�n b�rjan
    Node *tempSet = source.head->next;
    //Pekar p� "tomt" head-objekt med nullptr
    Node *temp = head;

    //N�r det fortfarande finns pekare i den vi kopierar fr�n (S1)
    while(tempSet)
    {
        //Skapar node med med v�rdet fr�n tempSet.value, dvs 1
        Node *n = new Node(tempSet->value, nullptr);

        //Pekar vidare fr�n temp till n�sta i listan, som blir n
        temp->next = n;
        //S�tter temp till noden n, l�ngst fram i listan
        temp = n;

        //Pekar vidare p� n�sta node i listan S1
        tempSet = tempSet->next;
    }
}

//Destructor: deallocate all nodes
//N�r destruktorn kallas p� vill vi ta bort alla noder
Set::~Set ()
{
    do{
        //n tilldelas f�rsta noden i listan vi befinner oss i
        Node *n = head->next;

        if (n != nullptr){
            //flyttar om f�rsta nodens pekare bak�t till skr�pNoden f�r att inte
            //bli av med pekarv�gen vid eliminering
            head->next = n->next;
            //Efter omflyttning s� tar vi bort objektet
            delete n;
        }
    //Tar bort noderna s�l�nge skr�pNoden inte pekar p� nullptr tar bort skr�pnoden
    }while (head->next != nullptr);
    delete head;
    //Warning Warning!!!
}

//Test if set is empty
bool Set::empty () const
{
    //Om noden efter skr�pnod �r nullptr, d� �r empty
    if (head->next == nullptr)
        return true;
    else
        return false;
}

//Return number of elements in the set
int Set::cardinality() const
{
    int counter = 0;
    Node *temp = head;

    while(temp->next)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

//Test if x is an element of the set
bool Set::member (int x) const
{
    Node *temp = head->next;

    //S� l�nge n�sta nod har en pekare
    while (temp){
        //Om nodens v�rde �r x
        if (temp->value == x){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Kolla om S �r subset av R
//Kolla om R �r subset av S
//I s� fall lika
//Se om alla tal i this (S2) �r "member" av b (S3)
bool Set:: operator<=(const Set& b) const
{
    Node *temp = head->next;

    while (temp != nullptr){
        if(b.member(temp->value)){
            temp=temp->next;
        }
        else{
            return false;
        }
    }
    return true;
}


//J�mf�r om S1 == S2.
//Anv�nd att om S1 <= S2 och S1 >= S2, d� BOOM
//Om S1 �r en m�ngd S2 och om S2 �r en m�ngd i S1, sant
bool Set:: operator==(const Set& b) const
{
    if ((*this <= b) && (b <= *this))
        return true;
    return false;
}

//Alla tal i this m�ste finnas i b och b m�ste vara st�rre
//f�r att f� ett proper subset
bool Set:: operator<(const Set& b)  const
{
    if (*this <= b && b.cardinality() > cardinality())
        return true;
    return false;
}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{
    //Skapa ett set fr�n this
    Set c(*this); //<----- S1

    //Peka p� header-noden i b
    Node *temp = b.head->next;

    while (temp->next){
        if (!c.member(temp->value)){
            c.ins (temp->value);

        }
        temp = temp->next;
    }
    return c;
}

//Set intersection
Set Set::operator* (const Set& b) const
{
    Set c;
    Node *temp = head->next;

    while (temp){
        //L�gg till i tomma setet om temp->value FINNS i b
        if (b.member(temp->value)){
            c.ins(temp->value);
        }
        temp = temp->next;
    }
    return c;
}

//Set difference
Set Set::operator- (const Set& b) const
{
    Set c;
    Node *temp = head->next;

    while (temp){
        //L�gg till i tomma setet om INTE temp->value finns i b
        if (!b.member(temp->value)){
            c.ins(temp->value);
        }
        temp = temp->next;
    }
    return c;
}

//set union with set {x}
Set Set::operator+(int x) const
{
    //Anv�nd member-funktionen f�r att se om talet x finns i setet
    Set c(*this);
    if (!c.member(x)){
        c.ins(x);
    }
    return c;
}

//set difference with set {x}
Set Set::operator- (int x) const
{
    Set c(*this);
    if (c.member(x)){
        c.del(x);
    }
    return c;
}

//Assignment operator
const Set& Set::operator=(const Set &s){
    //Om den �r lika med beh�ver inget g�ras
    //EVENTUELLT HA SET C RETURN C

    if (this != &s){
        this->~Set();

        //nullptr
        head = new Node(0, nullptr);

        //Pekar p� "tomt" head-objekt med nullptr
        Node *tempNode = head;
        //*tempSet, Pekare p� f�rsta elementet i S1.head, som �r noden med 1 fr�n b�rjan
        Node *newNode = s.head->next;

        //L�gg in i
        while(newNode != nullptr){
            tempNode->next = new Node(newNode->value, nullptr);
            tempNode = tempNode->next;
            newNode = newNode->next;
        }
    }
    return *this;
}

void Set::ins(int num)
{
    //temp pekar p� f�rsta dummynoden i this (C)
    Node* temp = head;

    //L�gger in talet p� r�tt plats i listan f�r att sorteras
    while((temp->next != nullptr) && (temp->next->value <= num)){
        temp = temp->next;
    }

    //Ny nod skapas fr�n number l�ggs in p� r�tt plats i listan
    Node* newNode = new Node (num, temp->next);
    temp->next = newNode;
}

void Set::del(int num)
{
    //temp pekar p� f�rsta dummynoden i this (C)
    Node *temp = head;

    //Om n�sta nods v�rde �r samma som nummer, ta bort noden
    //och peka f�rbi den
    while (temp->next){
        if (temp->next->value == num){
            //Ta bort nod
            delete temp->next;

            //Peka till noden efter den som �r borttagen
            //--------------VARF�R-------------
            temp->next = temp->next->next;
            break;
        }
        temp=temp->next;
    }
}

//Skickar in set'et typ, S1, S2, S3, etc
ostream& operator<< (ostream& os, const Set& theSet)
{
    Node* temp = theSet.head->next;

    //Om setet �r tomt, skriv ut empty
    if (theSet.empty()){
        os << "Set is empty!";
    }

    else{
        //S� l�nge temp pekar p� n�got, skriv ut
        while(temp != nullptr){
            os << temp->value << " ";
            //Peka p� n�sta
            temp = temp->next;
        }
    }
    return os;
}
