//++++++++++++++++++++++++++++++++
// Header file used in the project
//++++++++++++++++++++++++++++++++

#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

//++++++++++++++++++++++
// Class used in project
//++++++++++++++++++++++

class rentalSystem
{
  char brandn[30], model[30], reg[8], nos[2], pickup[20], dropoff[20], seat[8][4][10];

public:
  void fleet();
  void rent();
  void empty();
  void display();
  void avail();
  void position(int i);
}

car[10];
void vline(char ch)

{

  for (int i=80;i>0;i--)
  cout<<ch;

}

//+++++++++++++++++++++++++
// Function to create fleet
//+++++++++++++++++++++++++

void rentalSystem::fleet()
{

  cout<<"\n\t\t\tEnter Car Brand: ";
  cin>>car[p].brandn;
  cout<<"\n\t\t\tEnter Model: ";
  cin>>car[p].model;
  cout<<"\n\t\t\tRegistration: ";
  cin>>car[p].reg;
  cout<<"\n\t\t\tNo. of Seats: ";
  cin>>car[p].nos;
  cout<<"\n\t\t\tPick up location: ";
  cin>>car[p].pickup;
  cout<<"\n\t\t\tDrop of location: ";
  cin>>car[p].dropoff;
  car[p].empty();
  p++;
  
}

//++++++++++++++++++++++
// Function to rent cars
//++++++++++++++++++++++


void rentalSystem::rent()
{
  int seat;
  char number[5];
  top:
  cout<<"\n\t\t\tEnter Car Brand: ";
  cin>>number;
  int n;

  for(n=0;n<=p;n++)
  {

    if(strcmp(car[n].brandn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\n\t\t\tChose Bay: ";
    cin>>seat;
    if(seat>9)

    {

      cout<<"\n\t\t\tThere are only 8 bays available in this branch.";

    }

    else

    {

    if (strcmp(car[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"\n\t\t\tEnter Driver's Name: ";
        cin>>car[n].seat[seat/4][(seat%4)-1];
        break;

      }

    else

      cout<<"\t\t\tThe car is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"\t\t\tEnter correct brand name.\n";
      goto top;

    }

  }

  
//+++++++++++++++++++++++++
// Function to return empty
//+++++++++++++++++++++++++

void rentalSystem::empty()
{

  for(int i=0; i<2;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(car[p].seat[i][j], "Empty");

    }

  }

}


//++++++++++++++++++++++++++++++++++++++++++++
// Function to display the cars (availability)
//++++++++++++++++++++++++++++++++++++++++++++

void rentalSystem::display()
{

  int n;
  char number[5];
  cout<<"\n\t\t\tEnter Brand Name: ";
  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(car[n].brandn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');
  cout<<"Brand Name: \t\t"<<car[n].brandn
  <<"\nModel: \t\t\t"<<car[n].model<<"\nRegistration: \t\t"
  <<car[n].reg<<"\nNo.of Seats: \t\t"<<car[n].nos
  <<"\nPick Up: \t\t"<<car[n].pickup<<"\nDrop Off: \t\t"
  <<car[n].dropoff<<"\n";
  vline('*');

  car[0].position(n);
  int a=1;

  for (int i=0; i<2; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(car[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe bay no "<<(a-1)<<" is reserved for "<<car[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"\t\t\tEnter correct bay no.: ";

}

//+++++++++++++++++++++++
// Function to assign car
//+++++++++++++++++++++++

void rentalSystem::position(int l)
{

  int s=0;p=0;
  for (int i =0; i<2;i++)

  {

    cout<<"\n";
    for (int j = 0;j<4; j++)

    {

      s++;
      if(strcmp(car[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<car[l].seat[i][j];
          p++;

        }

        else

        {

        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<car[l].seat[i][j];

        }
      }
    }
    
  cout<<"\n\nThere are "<<p<<" bays empty in this Brand: "<<car[l].brandn;

  }
  
  
//+++++++++++++++++++++++++++++++++++++++++
// Function to see ehich fleet is available
//+++++++++++++++++++++++++++++++++++++++++
  
void rentalSystem::avail()
{


  for(int n=0;n<p;n++)

  {

    vline('*');

  cout<<"Brand Name: \t\t"<<car[n].brandn
  <<"\nModel: \t\t\t"<<car[n].model<<"\nRegistration: \t\t"
  <<car[n].reg<<"\nNo.of Seats: \t\t"<<car[n].nos
  <<"\nPick Up: \t\t"<<car[n].pickup<<"\nDrop Off: \t\t"
  <<car[n].dropoff<<"\n";

    vline('*');
    vline('_');

  }
}


//+++++++++++++++++++++++++++++
// The main function of program
//+++++++++++++++++++++++++++++

int main()
{
    
system("cls");
int w;
while(1)

{
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Fleet\n\t\t\t"
  <<"2.Rental Management\n\t\t\t"
  <<"3.Display\n\t\t\t"
  <<"4.Fleet Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\n\t\t\tInput the function needed here: ";
  cin>>w;

  switch(w)

  {

    case 1:  car[p].fleet();
      break;
    case 2:  car[p].rent();
      break;
    case 3:  car[0].display();
      break;
    case 4:  car[0].avail();
      break;
    case 5:  exit(0);

  }
}
return 0;
}

//+++++++++++++++
// End of project
//+++++++++++++++
