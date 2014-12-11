#include <iostream>
#include "set.h"
#include <new>

//Default constructor
Set::Set ()
{
    //Sätt instansvariabler
    //Tomt setobjekt
    head = new Node(0, nullptr);
}

//Constructor creating a set
//from n integers in a non-sorted array a
//Skapar ett sorterat set
Set::Set (int a[], int n)
{
    //Pekar på "tomt" head-objekt med nullptr
    head = new Node(0, nullptr);
    //Loopa igenom alla slots i arrayen
    for (int i = 0; i<n; i++){
        //Temporär head-node
        Node *temp = head;

        //Om värdet pekar på inte är nullptr samt sortera
        while (temp->next && temp->next->value < a[i]){
            temp = temp->next;
        }
        //För värdet ligger i rätt ordning i array'n
        Node *nextptr = new Node(a[i], temp->next);
        temp->next = nextptr;
    }
}

//copy constructor
Set::Set (const Set &source)
{
    head = new Node(0, nullptr);

    //*tempSet, Pekare på första elementet i S1.head, som är noden med 1 från början
    Node *tempSet = source.head->next;
    //Pekar på "tomt" head-objekt med nullptr
    Node *temp = head;

    //När det fortfarande finns pekare i den vi kopierar från (S1)
    while(tempSet)
    {
        //Skapar node med med värdet från tempSet.value, dvs 1
        Node *n = new Node(tempSet->value, nullptr);

        //Pekar vidare från temp till nästa i listan, som blir n
        temp->next = n;
        //Sätter temp till noden n, längst fram i listan
        temp = n;

        //Pekar vidare på nästa node i listan S1
        tempSet = tempSet->next;
    }
}

//Destructor: deallocate all nodes
//När destruktorn kallas på vill vi ta bort alla noder
Set::~Set ()
{
    do{
        //n tilldelas första noden i listan vi befinner oss i
        Node *n = head->next;

        if (n != nullptr){
            //flyttar om första nodens pekare bakåt till skräpNoden för att inte
            //bli av med pekarvägen vid eliminering
            head->next = n->next;
            //Efter omflyttning så tar vi bort objektet
            delete n;
        }
    //Tar bort noderna sålänge skräpNoden inte pekar på nullptr tar bort skräpnoden
    }while (head->next != nullptr);
    delete head;
    //Warning Warning!!!
}

//Test if set is empty
bool Set::empty () const
{
    //Om noden efter skräpnod är nullptr, då är empty
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

    //Så länge nästa nod har en pekare
    while (temp){
        //Om nodens värde är x
        if (temp->value == x){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Kolla om S är subset av R
//Kolla om R är subset av S
//I så fall lika
//Se om alla tal i this (S2) är "member" av b (S3)
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


//Jämför om S1 == S2.
//Använd att om S1 <= S2 och S1 >= S2, då BOOM
//Om S1 är en mängd S2 och om S2 är en mängd i S1, sant
bool Set:: operator==(const Set& b) const
{
    if ((*this <= b) && (b <= *this))
        return true;
    return false;
}

//Alla tal i this måste finnas i b och b måste vara större
//för att få ett proper subset
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
    //Skapa ett set från this
    Set c(*this); //<----- S1

    //Peka på header-noden i b
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
        //Lägg till i tomma setet om temp->value FINNS i b
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
        //Lägg till i tomma setet om INTE temp->value finns i b
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
    //Använd member-funktionen för att se om talet x finns i setet
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
    //Om den är lika med behöver inget göras
    //EVENTUELLT HA SET C RETURN C

    if (this != &s){
        this->~Set();

        //nullptr
        head = new Node(0, nullptr);

        //Pekar på "tomt" head-objekt med nullptr
        Node *tempNode = head;
        //*tempSet, Pekare på första elementet i S1.head, som är noden med 1 från början
        Node *newNode = s.head->next;

        //Lägg in i
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
    //temp pekar på första dummynoden i this (C)
    Node* temp = head;

    //Lägger in talet på rätt plats i listan för att sorteras
    while((temp->next != nullptr) && (temp->next->value <= num)){
        temp = temp->next;
    }

    //Ny nod skapas från number läggs in på rätt plats i listan
    Node* newNode = new Node (num, temp->next);
    temp->next = newNode;
}

void Set::del(int num)
{
    //temp pekar på första dummynoden i this (C)
    Node *temp = head;

    //Om nästa nods värde är samma som nummer, ta bort noden
    //och peka förbi den
    while (temp->next){
        if (temp->next->value == num){
            //Ta bort nod
            delete temp->next;

            //Peka till noden efter den som är borttagen
            //--------------VARFÖR-------------
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

    //Om setet är tomt, skriv ut empty
    if (theSet.empty()){
        os << "Set is empty!";
    }

    else{
        //Så länge temp pekar på något, skriv ut
        while(temp != nullptr){
            os << temp->value << " ";
            //Peka på nästa
            temp = temp->next;
        }
    }
    return os;
}
