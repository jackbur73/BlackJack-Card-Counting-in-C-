//Jack Burgess ECE 3220 Final Project

#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

void ruleBook(int player , int dealer);

class card
{
    public:
       string face, suit;
    card()
    {

    }

    card(string face , string suit)
    {
        this->face = face;
        this->suit = suit;
    }
    void setCard(string value, string temp) // this is a settor function
    {
        suit = temp;
        face = value;
    }

    string makeString()
    {
        string dummy = face + " of " + suit;

        return dummy;
    }

     int getValue()
    {
        if( face == "two")
        {
            return 2;
        }

        if( face == "three")
        {
            return 3;
        }

        if( face == "four")
        {
            return 4;
        }

        if( face == "five")
        {
            return 5;
        }

        if( face == "six")
        {
            return 6;
        }

        if( face == "seven")
        {
            return 7;
        }

        if( face == "eight")
        {
            return 8;
        }

        if( face == "nine")
        {
            return 9;
        }

        if( (face == "ten") || (face == "jack") || (face == "queen") || (face == "king"))
        {
            return 10;
        }

        if(face == "ace")
        {
            return 11;;
        }
        return 1;
    }

   int getValue(int &count ) // overloader function 
    {
        if( face == "two") // 2 - 6 is -1 for the count 
        { // 7 8 9 is zero for the count
            count--;
            cout << "The current Count is " << count << endl;
            return 2; // and every ace - face is +1 for the count
        }

        if( face == "three")
        {
            count--;
            cout << "The current Count is " << count << endl;
            return 3;
        }

        if( face == "four")
        {
            count--;
            cout << "The current Count is " << count << endl;
            return 4;
        }

        if( face == "five")
        {
            count--;
            cout << "The current Count is " << count << endl;
            return 5;
        }

        if( face == "six")
        {
            count--;
            cout << "The current Count is " << count << endl;
            return 6;
        }

        if( face == "seven")
        {
            cout << "The current Count is " << count << endl;
            return 7;
        }

        if( face == "eight")
        {
            cout << "The current Count is " << count << endl;
            return 8;
        }

        if( face == "nine")
        {
            cout << "The current Count is " << count << endl;
            return 9;
        }

        if( (face == "ten") || (face == "jack") || (face == "queen") || (face == "king"))
        {
            count++;
            cout << "The current Count is " << count << endl;
            return 10;
        }

        if(face == "ace")
        {
            count++;
            cout << "The current Count is " << count << endl;
            return 11;;
        }
        return 1;
    }
};

class deck
{
    public:
    card arr[52]; // this is an array of cards
    int post ; // this is the current spot of the deck
    deck()
    {
        string faces[13] = {"ace" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "jack" , "queen" , "king"}; // 1 is an ace, then 2 - 10 and 11 -13 is jack queen king
        string suits[4] = {"Heart" , "Diamond" , " Spade" , "Clubs"};

        post = 0;
        for(int x = 0; x < 5 ; x ++)
        {
             for(int i = 1 ; i < 14 ; i++)
             {
                 arr[i] = card((faces[i % 13]) , (suits[ x % 4]));

                 if(x == 1)
                 {
                     arr[i + 12] = card((faces[i % 13]) , (suits[ x % 4]));
                 }
                  if(x == 2)
                 {
                     arr[i + 25] = card((faces[i % 13]) , (suits[ x % 4]));
                 }

                 if(x == 3)
                 {
                     arr[i + 38] = card((faces[i % 13]) , (suits[ x % 4]));
                 }
             }
        }
    }


    void shuffle()
    {
        post = 0;

        int rando = 0;
        while(rando <= 5) // this is to go through and make sure that every spot as been changed mulitple times
        { 

        for(int x = 0; x < 52; x++)
        {
            int y;
            y = rand() % 52;

            card dummy;
            dummy = arr[x];
            arr[x] = arr[y];
            arr[y] = dummy;
        }
        rando++;
      }
    }

    bool checkPost()
    {
        cout << "The current postition in the deck is " << post << endl;


        if(post < 52)
        {
            return true;
        }

        return false;
    }

    card deal()
    {
        if(post < 52)
        {
            post++;
            return arr[post];
        }

        if((post == 52) || (checkPost() == false))
        {
            shuffle();
            post = 0;
            return arr[0];
        }

        return arr[post];
    }

    int getPos()
    {
        return post;
    }

    int getValue(card temp)
    {
        if( temp.face == "two")
        {
            return 2;
        }

        if( temp.face == "three")
        {
            return 3;
        }

        if( temp.face == "four")
        {
            return 4;
        }

        if( temp.face == "five")
        {
            return 5;
        }

        if( temp.face == "six")
        {
            return 6;
        }

        if( temp.face == "seven")
        {
            return 7;
        }

        if( temp.face == "eight")
        {
            return 8;
        }

        if( temp.face == "nine")
        {
            return 9;
        }

        if( (temp.face == "ten") || (temp.face == "jack") || (temp.face == "queen") || (temp.face == "king"))
        {
            return 10;
        }

        if(temp.face == "ace")
        {
            return 11;;
        }
        return 1;
    }

     string makeString(card temp)
    {
        string dummy = temp.face + " of " + temp.suit;

        return dummy;
    }

    
};

float split(deck &casino , int &count , float units, int card1 , int card2, int dealer, int down);

float blackjack(deck &casino , int &count , float units)
{

    int in = 0; // userInput
    bool over = 0; // a flag to see when the game is over

    if(casino.getPos() > 40)
    {
        cout << "***********************************" << endl;
        cout << "Resfuffle!" << endl;
        cout << "***********************************" << endl;

        count = 0;
    }

    int player;
    int dealer;

    int c1; // dunny card values
    int c2;
    int c3;
    int c4;

    int dealerdown;

    card temp = casino.deal();
    cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
    player = temp.getValue(count);
    c1 = temp.getValue();

    temp = casino.deal();
    cout << "The Dealer was dealt a " << temp.makeString() << endl; // dealers first card
    dealer = temp.getValue(count);

    temp = casino.deal();
    cout << "The Player was dealt a " << temp.makeString() << endl; // players second card
    player = player + temp.getValue(count);
    c2 = temp.getValue();

    cout << "*****************************" << endl;

    temp = casino.deal();
    dealerdown = temp.getValue();

    cout << "The player has a " << player << endl;
    cout << "The dealer has a " << dealer << endl;

    cout << "THE COUNT IS " << count << endl;

    if((dealer + dealerdown ) == 21)
    {
        cout << "DEALER BLACKJACK " << endl;
        units = units * -1;
        return units;
    }
    
    if(player == 21)
    {
        cout << "PLAYER BLACKJACK!!!!!!!!!!!!!" << endl;
        return units * 2.5;
    }

      if((player == 21) && ((dealer + dealerdown ) == 21))
    {
        cout << "BOTH THE DEALER AND THE PLAYER HAVE BLACKJACK YOU GET REGULAR PAYOUT" << endl;
        return units * 2;
    }

    //cout << "The player has a " << c1 << " and a " << c2 << endl;

    if(c1 == c2)
    {
        in = 0;
        while(in == 0)
        {
        cout << "Would you like to hit, Split, double, or Stand ? " << endl;
        cout << "-------------------------------" << endl;
        cout << "Hit == 1" << endl;
        cout << "Split == 2" << endl;
        cout << "double == 3" << endl;
        cout << "Stand == 4" << endl;
        cin >> in;
        }

        if(in == 2)
        {
            float JK;
            JK = split(casino, count , units, c1,c2 , dealer , dealerdown);
            return JK;
        }

    }

    cout << "Would you like to Hit, Double , Or Stand??"  << endl;
    cout << "************************************" << endl;

    while((in < 1) || (in > 3))
    {
        cout << "HIT = 1" << endl;
        cout << "Double = 2" << endl;
        cout << "Stand = 3 "  << endl;
        cin >> in;
    }

    cout << "*******************************" << endl;

    if(in == 1)
    {
        temp = casino.deal();
        cout << "The player was dealt a " << temp.makeString();
        player = player + temp.getValue(count);

        cout << "The player now has a " << player << endl;

        if(temp.getValue() == 11)
        {
            if(player > 21)
            {
                cout << "The ace is now worth 1" << endl;
                player = player - 10;
            }
        }
    }

    if(in == 2)
    {
        temp = casino.deal();
        cout << "The player was dealt a " << temp.makeString();
        player = player +temp.getValue(count);

        cout << "The player now has a " << player << endl;

        if(temp.getValue() == 11)
        {
            if(player > 21)
            {
                cout << "The players ace is now worth a 1" << endl;
                player = player - 10;
            }
        }

        units = units * 2;
        over = 1; // on a double the hand is over
    }

    if(in == 3)
    {
        cout << "You choice to stand !" << endl;
        over = 1;
    }
/////////////////////////////////////////////////// First card dealt now its only hit stand 

    if(player > 21)
    {
        cout << " ****************************" << endl;
        cout << " You lose " << endl;
        return 0;
    }

    cout <<"You can only hit or stand now !!" << endl;

    while(over == 0)
    {
        cout << "*****************************" << endl;
    cout << "The player has a " << player << endl;
    cout << "The dealer has a " << dealer << endl;

    in = 0;

        while((in < 1) || (in >2))
        {

            cout << "Enter a 1 for HIT or a 2 for STAND" << endl;
            cin >> in;

        }

        cout << "*************************" << endl;

        if(in ==1)
        {
            cout << "You choice to hit!" << endl;
            temp = casino.deal();
            cout << "The card dealt was a " << temp.makeString() << endl;
            player = player + temp.getValue(count);

            if(temp.getValue() == 11)
            {
                if(player > 21)
                {
                    cout <<"You ace is now worth 1" << endl;
                    player = player - 10;
                }
                
            }
            cout << "The player now has a " << player << endl;
            cout << "*****************************" << endl;
        }

        if( in == 2)
        {
            cout << "You choose to stand with a player " << player << endl;
            cout << " ****************************" << endl;
            over = 1;
        }

        if(player > 20)
        {
            over = 1;
        }

        
    }

    cout << "*************************" << endl;
//////////////////////////////////////////////////

    cout << "Now for the Dealer to draw! " << endl;

    cout << "The dealers down card was a " << dealerdown << endl;
    dealer = dealer + dealerdown;

    cout << "The dealer and the down card are now " << dealer << endl;

    cout << "*********************************" << endl;

    while(dealer < 17)
    {
        temp = casino.deal();

        cout << "The dealer drew a " << temp.makeString() << endl;

        dealer = dealer + temp.getValue(count);

        cout << "So the dealer has a " << dealer << endl;

        cout << "*************************" << endl;

       // dealer = dealer + temp.getValue(count);

        if(temp.getValue() == 11)
        {
            if(dealer > 21)
            {
                dealer = dealer - 10;
                cout << "The ace is now worth a 1 " << endl;
            }
        }
    }

    cout << "*******************************" << endl;

    if(player > 21)
    {
        cout << "The player has bust, so you lose! " << endl;
        return 0;
    }

    if(dealer > 21)
    {
        cout << "The dealer has bust so you win! " << endl;
        return units * 2;
    }

    if(dealer < player)
    {
        cout << "The player has a " << player << " and the dealer has a " << dealer << " So the player wins!" << endl;
        return units * 2;
    }

    if(dealer > player)
    {
        cout << "The player has a " << player << " and the dealer has a " << dealer << " So the dealer wins!" << endl;
        return 0;
    }

    if(dealer == player)
    {
        cout << "The player and the dealer had " << player << endl;
        return units;
    }
    return units;

}

float split(deck &casino , int &count , float units, int card1 , int card2, int dealer, int down)
{

    float unit1 = units;
    float unit2 = unit1;


    int hand1 = card1;
    int hand2 = card2;

    int c3;
    int c4;

    card temp = casino.deal();

    bool end1 = 0; // a bool to see if the game is over or not
    bool end2 = 0;

    cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
    hand1 = hand1 + temp.getValue(count);

    int in = 0;

    cout << "One hand 1 you have a " << hand1 << " You can only split once in most casinos so you can only split once here " << endl;
    cout << "The dealer has a " << dealer << endl;
    cout << "***************************" << endl;

        while ((in > 3) || (in < 1))
        {
            cout << "Please enter a value" << endl;
             cout << "Hit == 1" << endl;
            cout << "Double == 2" << endl;
              cout << "Stand == 3" << endl; 
            cin >> in;
        }

        if( in == 1)
        {
            cout << "You decided to hit " << endl;
            temp = casino.deal();
            c3 = temp.getValue(count);

            cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
            hand1 = hand1 + temp.getValue();
            cout << "The player now has a " << hand1 << endl;
        }

        if (in == 2)
        {
            cout << "You decided to Double " << endl;
            temp = casino.deal();
            c3 = temp.getValue(count);

            cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
            hand1 = hand1 + temp.getValue();
            cout << "The player now has a " << hand1 << endl;

            unit1 = unit1 + unit1;
            end1 = 1;
        }

        if (in == 3)
        {
            cout << "You choice to stand" << endl;
            end1 = 1;
        }

        if(hand1 > 21)
        {
            if( card1 == 11)
            {
                card1 = 1;
                hand1 = hand1 - 10;
            }

            if(c3 == 11)
            {
                card1 = 1;
                hand1 = hand1 - 10;
            }
        }

        if( hand1 > 21)
        {
            cout << "The first hand was a bust" << endl;
            unit1 = unit1 * -1;
            end1 = 1;
        }

        while(end1 == 0)
        {
            cout << "The first hand is a " << endl;
            cout << "Woudl you like to hit or stand?" << endl;
            cout << "**************************" << endl;
            in = 0;

            while((in =! 1) && (in =!2))
            {
                cout << "HIT = 1" << endl;
                cout << "STAND = 2" << endl;
                cout << "Player has a " << hand1 << endl;
                cout << "The dealer has a "  << dealer << endl;
                cin >> in;
            }

            if(in == 1) // if hit then deal a card
            {
                cout << "You decided to hit" << endl;
                temp = casino.deal();
                cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
                hand1 = hand1 + temp.getValue(count);
                cout << "The player now has a " << hand1 << endl;
            }

            if(in == 2) // the hand ends once he stands!
            {
                cout << "You decided to stand with hand 1" << endl;
                cout << "This hand ends with " << hand1 << endl;
                end1 = 1;
            }

            if(hand1 > 21) // the hand also ends if the player busts!
            {
                cout<< "The hand1 busts with a  " << hand1 << endl;
                end1 = 1;
                unit1 = unit1 * -1;
                cout << "You lose :(" << endl;
            }
        }
////////////////////////////////////////////////////////////////////////////

    cout << "Now its time to play Hand2" << endl;
    cout << "Hand 2 has a " << hand2 << endl;
    cout << "The dealer has a " << dealer << endl;

    temp = casino.deal();
    c4 = temp.getValue(count);
    cout << "The Second hand was dealt a " << temp.makeString() << endl;
    hand2 = hand2 + c4;
    cout << "The 2nd hand is a " << hand2 << endl;
    in = 0;

    cout << "The dealer has a " << dealer << endl;
    cout << "***************************" << endl;

        while ((in > 3) || (in < 1))
        {
            cout << "Please enter a value" << endl;
             cout << "Hit == 1" << endl;
            cout << "Double == 2" << endl;
              cout << "Stand == 3" << endl; 
            cin >> in;
        }

    if ( in == 1)
    {
            cout << "You decided to hit " << endl;
            temp = casino.deal();
            int c5 = temp.getValue(count);

            cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
            hand2 = hand2 + temp.getValue();
            cout << "The player now has a " << hand2 << endl;
    }

    if (in == 2)
    {
        cout << "You decided to double Hand2" << endl;
        temp = casino.deal();
        cout << "The second hand was dealt a " << temp.makeString() << endl;
        hand2 = hand2 + temp.getValue(count);
        unit2 = unit2 + unit2;

        cout << "The second hand is now a " << hand2 << endl;
    }

    if ( in == 3)
    {
        cout << "You decided to stand on hand 2" << endl;
        end2 = 1;
    }

    if(hand2 > 21)
    {
        if((card2 == 11) || (c4 == 11))
        {
            cout << "The Ace is now worth 1 so you do not bust" << endl;
            hand2 = hand2 - 10;
        }
    }

    if(hand2 > 21)
    {
        cout << "You have busted You lost the bet which was " << unit2 << endl;
        end2 = 1;
        unit2 = unit2 * -1;
    }

    while(end2 == 0)
    {
        cout << "Now you have to choice between hit or stand for the 2nd hand" <<endl;
        cout << "Hand2 has a " << hand2 << endl;
        cout << "The dealer has a " << dealer << endl;

        in = 0;

        while((in =! 1) && (in =!2))
            {
                cout << "HIT = 1" << endl;
                cout << "STAND = 2" << endl;
                cout << "Player has a " << hand1 << endl;
                cout << "The dealer has a "  << dealer << endl;
                cin >> in;
            }
        
        if( in == 1)
        {
            cout << "You choose to hit " << endl;
            temp = casino.deal();
            cout << "You have been dealt " << temp.makeString() << endl;
            hand2 = hand2 + temp.getValue(count);
    
        }

        
        if ( in == 2)
        {
            cout << "you have choice to stand on hand 2 "  << endl;
            cout << "You stood with a " << hand2 << " On a dealer " << dealer << endl;
            end2 = 1;
        }

        if ( hand2 > 21)
        {
            if ((card2 == 11) || (c4 == 11))
            {
                hand2 = hand2 - 10;
                cout << "You ace is now worth 1" << endl;
            }
        }

        if (hand2 > 21)
        {
            cout << "You have busted and you lost !" << endl;
            unit2 = unit2 * -1;
            end2 = 1;
        }
    }

    cout << "**************************************************" << endl;

    cout << "Now its time to deal to the dealer! The dealer has a " << dealer << endl;

    int d2;
    int d3;
    int d4;

    dealer = dealer + down;

    cout << " The dealers down card was a " << down << endl;
    cout << "The dealers now has a " << dealer << endl;

    if(dealer == 22) // double aces 
    {
        dealer = 12;
        cout << "The dealer now has a " << dealer << endl;
    }

    while(dealer < 17)
    {
        cout << "The dealer has less than 17 so we must hit! " << endl;
        temp = casino.deal();
        cout << "The dealer was dealt a " << temp.makeString() << endl;
        dealer = dealer + temp.getValue(count);
        cout << "The dealer now has a " << dealer << endl;

        if(dealer > 21)
        {
            if(temp.getValue() == 11)
            {
                cout << "dealers ace is now worth 1 " << endl;
                dealer = dealer - 10;

            }
        }

    }

    if((dealer > 21) && (hand1 < 21))
    {
        cout << "Dealer bust!!! Hand1 wins because it stood " << endl;
        unit1 = unit1 + unit1; // the bet doubles
    }

    if((dealer > 21) && (hand2 < 21))
    {
        cout << "Dealer BUST !!! Hand2 wins because it stood" << endl;
        unit2 = unit2 * 2;
    }

    if((dealer < 22) && (hand1 < 22))
    {
        if(dealer > hand1)
        {
            cout << "Hand 1 lost to the dealer "  << endl;
            unit1 = unit1 * -1;
        }

        if(dealer < hand1)
        {
            cout << "hand 1 Beats the dealer !" << endl;
            unit1 = unit1 * 2;
        }

        if(dealer == hand1)
        {
            cout << "Hand 1 was a push with the dealer" << endl;
        }
    }

    if((dealer < 22) && (hand2 << 22))
    {
        if(dealer > hand2)
        {
            cout << "Hand 2 lost to the dealer " << endl;
            unit2 = unit2 * -1;
        }

        if ( hand2 > dealer )
        {
            cout << "Hand 2 beats the dealer!"  << endl;
            unit2 = unit2 * 2;
        }

        if ( hand2 == dealer)
        {
            cout << "Hand 2 and the dealer were a push"  << endl;
        }
    }

    float totalUnit = unit1 + unit2;

    cout << "The total split had a balance of " << totalUnit << endl;
    return totalUnit;
}


void ruleBook(int player , int dealer) // This is a function that tells the player whether or not to hit stand or double.
//It will not tell the player to split as splitting is not included in the rule book
    {   
    cout << "***************************************" << endl;

    if((player > 16) && (player < 22)) // 17 - 21
    {
        cout << "The player should Stand!" << endl;
        return ;
    }

    if(player == 11) // always double on 11
    {
        cout << "The player should DOUBLE" << endl;
        return;
    }

    if((dealer < 7) && (dealer > 3)) // dealer 4 - 6
    {
        if((player < 12) && (player > 8)) // player 9 - 11
        {
            cout << "The player should DOUBLE!" << endl;
            return;
        }

        if(player > 11) // player 12-21
        {
            cout << "The player should STAND" << endl;
            return;
        }

        if(player < 9 )// 2 - 8)
        {
            cout << "The player should HIT " << endl;
            return;
        }
    }

    if((dealer == 2) || (dealer == 3) || (dealer == 7) || (dealer == 8) || (dealer == 9) || (dealer == 10) || (dealer == 11)) // dealer 2,3 7-face and ace
    {
        if(player > 16)
        {
            cout << "The player should STAND" << endl;
            return;
        }

        if(player < 17)
        {
            cout << "The player should HIT" << endl;
            return;
        }
    }

    }


float blackjack(deck &casino , int &count , float units , int rules)
{

    int in = 0; // userInput
    bool over = 0; // a flag to see when the game is over

    if(casino.getPos() > 40)
    {
        cout << "***********************************" << endl;
        cout << "Resfuffle!" << endl;
        cout << "***********************************" << endl;

        count = 0;
    }

    int player;
    int dealer;

    int c1; // dunny card values
    int c2;
    int c3;
    int c4;

    int dealerdown;

    card temp = casino.deal();
    cout << "The Player was dealt a " << temp.makeString() << endl; // players first card
    player = temp.getValue(count);
    c1 = temp.getValue();

    temp = casino.deal();
    cout << "The Dealer was dealt a " << temp.makeString() << endl; // dealers first card
    dealer = temp.getValue(count);

    temp = casino.deal();
    cout << "The Player was dealt a " << temp.makeString() << endl; // players second card
    player = player + temp.getValue(count);
    c2 = temp.getValue();

    cout << "*****************************" << endl;

    temp = casino.deal();
    dealerdown = temp.getValue();

    cout << "The player has a " << player << endl;
    cout << "The dealer has a " << dealer << endl;

    cout << "THE COUNT IS " << count << endl;

    if((dealer + dealerdown ) == 21)
    {
        cout << "DEALER BLACKJACK " << endl;
        units = units * -1;
        return units;
    }
    
    if(player == 21)
    {
        cout << "PLAYER BLACKJACK!!!!!!!!!!!!!" << endl;
        return units * 2.5;
    }

      if((player == 21) && ((dealer + dealerdown ) == 21))
    {
        cout << "BOTH THE DEALER AND THE PLAYER HAVE BLACKJACK YOU GET REGULAR PAYOUT" << endl;
        return units * 2;
    }

    //cout << "The player has a " << c1 << " and a " << c2 << endl;

    ruleBook(player , dealer);

    if(c1 == c2)
    {
        in = 0;
        while(in == 0)
        {
        cout << "Would you like to hit, Split, double, or Stand ? " << endl;
        cout << "-------------------------------" << endl;
        cout << "Hit == 1" << endl;
        cout << "Split == 2" << endl;
        cout << "double == 3" << endl;
        cout << "Stand == 4" << endl;
        cin >> in;
        }

        if(in == 2)
        {
            float JK;
            JK = split(casino, count , units, c1,c2 , dealer , dealerdown);
            return JK;
        }

    }

    cout << "Would you like to Hit, Double , Or Stand??"  << endl;
    //ruleBook(player , dealer);
    cout << "************************************" << endl;

    while((in < 1) || (in > 3))
    {
        cout << "HIT = 1" << endl;
        cout << "Double = 2" << endl;
        cout << "Stand = 3 "  << endl;
        ruleBook(player,dealer);
        cin >> in;
    }

    cout << "*******************************" << endl;

    if(in == 1)
    {
        temp = casino.deal();
        cout << "The player was dealt a " << temp.makeString();
        player = player + temp.getValue(count);

        cout << "The player now has a " << player << endl;

        if(temp.getValue() == 11)
        {
            if(player > 21)
            {
                cout << "The ace is now worth 1" << endl;
                player = player - 10;
            }
        }
    }

    if(in == 2)
    {
        temp = casino.deal();
        cout << "The player was dealt a " << temp.makeString();
        player = player +temp.getValue(count);

        cout << "The player now has a " << player << endl;

        if(temp.getValue() == 11)
        {
            if(player > 21)
            {
                cout << "The players ace is now worth a 1" << endl;
                player = player - 10;
            }
        }

        units = units * 2;
        over = 1; // on a double the hand is over
    }

    if(in == 3)
    {
        cout << "You choice to stand !" << endl;
        over = 1;
    }
/////////////////////////////////////////////////// First card dealt now its only hit stand 

    if(player > 21)
    {
        cout << " ****************************" << endl;
        cout << " You lose " << endl;
        return 0;
    }

    cout <<"You can only hit or stand now !!" << endl;

    while(over == 0)
    {
        cout << "*****************************" << endl;
    cout << "The player has a " << player << endl;
    cout << "The dealer has a " << dealer << endl;

    in = 0;

        while((in < 1) || (in >2))
        {

            cout << "Enter a 1 for HIT or a 2 for STAND" << endl;
            ruleBook(player,dealer);
            cin >> in;

        }

        cout << "*************************" << endl;

        if(in ==1)
        {
            cout << "You choice to hit!" << endl;
            temp = casino.deal();
            cout << "The card dealt was a " << temp.makeString() << endl;
            player = player + temp.getValue(count);

            if(temp.getValue() == 11)
            {
                if(player > 21)
                {
                    cout <<"You ace is now worth 1" << endl;
                    player = player - 10;
                }
                
            }
            cout << "The player now has a " << player << endl;
            cout << "*****************************" << endl;
        }

        if( in == 2)
        {
            cout << "You choose to stand with a player " << player << endl;
            cout << " ****************************" << endl;
            over = 1;
        }

        if(player > 20)
        {
            over = 1;
        }

        
    }

    cout << "*************************" << endl;
//////////////////////////////////////////////////

    cout << "Now for the Dealer to draw! " << endl;

    cout << "The dealers down card was a " << dealerdown << endl;
    dealer = dealer + dealerdown;

    cout << "The dealer and the down card are now " << dealer << endl;

    cout << "*********************************" << endl;

    while(dealer < 17)
    {
        temp = casino.deal();

        cout << "The dealer drew a " << temp.makeString() << endl;

        dealer = dealer + temp.getValue(count);

        cout << "So the dealer has a " << dealer << endl;

        cout << "*************************" << endl;

       // dealer = dealer + temp.getValue(count);

        if(temp.getValue() == 11)
        {
            if(dealer > 21)
            {
                dealer = dealer - 10;
                cout << "The ace is now worth a 1 " << endl;
            }
        }
    }

    cout << "*******************************" << endl;

    if(player > 21)
    {
        cout << "The player has bust, so you lose! " << endl;
        return 0;
    }

    if(dealer > 21)
    {
        cout << "The dealer has bust so you win! " << endl;
        return units * 2;
    }

    if(dealer < player)
    {
        cout << "The player has a " << player << " and the dealer has a " << dealer << " So the player wins!" << endl;
        return units * 2;
    }

    if(dealer > player)
    {
        cout << "The player has a " << player << " and the dealer has a " << dealer << " So the dealer wins!" << endl;
        return 0;
    }

    if(dealer == player)
    {
        cout << "The player and the dealer had " << player << endl;
        return units;
    }
    return units;

}

int main(void)
{
   // cout << "This compiles \n" << endl;

    srand(time(0));

    deck casino;

    casino.shuffle();

    casino.post = 48;

    int count;
    count = 0;

    int player1;

    int dealer;

  //  blackjack(casino, count, 10);

    cout << "You have 100$" << endl;
    bool flag = 0;
    float bank = 100;

    int rule = 0;

    cout << "***************************" << endl;
    cout << "Do you know how to play blackjack or would you like the suggested plays" << endl;
    cout << "Enter 0 if you would like to use the suggested plays " << endl;
    cout << "Please note that the suggested rules do not include splits as it is an advanced stratgery and only experienced blackjack players should use it" << endl;
    cin >> rule;


    if (rule != 0)
    {
        while(flag != 1)
    {

        cout << "**********************" << endl;

        cout << "The Count is " << count << endl;
        if(count > 3)
        {
            cout << "The count is high so you are more likely to loss" << endl;
            cout << "Try to bet a small amount " << endl;
        }

        if(count < -3)
        {
            cout << "The count is very low!! you are more likely to win" << endl;
            cout << "You should bet a large amount " << endl;
        }


        cout << "******************************" << endl;


        float unit;
        cout << "You have " << bank << " dollars" << endl;
        cout << "How much would u like to bet??" << endl;
        cin >> unit;

        if((unit < 0) || ( unit > bank))
        {
             cout << "You have " << bank << " dollars" << endl;
             cout << "How much would u like to bet??" << endl;
             cin >> unit;
        }

        cout << "*********************" << endl;
        cout << "You are betting " << unit << " time to play!!" << endl;

        bank = bank - unit ; 

        bank = bank + blackjack(casino,count,unit);

        cout << "you have " << bank << endl;

        cout << "Please enter a 0 to keep playing or a 1 to quit " << endl;
        cin >> flag;
    }
    }

    if(rule == 0)
    {
         while(flag != 1)
    {

        cout << "**********************" << endl;

        cout << "You choice to play with the rules" << endl;

        cout << "The Count is " << count << endl;
        if(count > 3)
        {

            cout << "**********************" << endl;
            cout << "The count is high so you are more likely to loss" << endl;
            cout << "Try to bet a small amount " << endl;
            cout << "*******************" << endl;
        }

        if(count < -3)
        {
            cout << "************************" << endl;
            cout << "The count is very low!! you are more likely to win" << endl;
            cout << "You should bet a large amount " << endl;
            cout << "*************************" << endl;
        }


        cout << "******************************" << endl;


        float unit;
        cout << "You have " << bank << " dollars" << endl;
        cout << "How much would u like to bet??" << endl;
        cin >> unit;

        if((unit < 0) || ( unit > bank))
        {
             cout << "You have " << bank << " dollars" << endl;
             cout << "How much would u like to bet??" << endl;
             cin >> unit;
        }

        cout << " *********************" << endl;
        cout << "You are betting " << unit << " time to play!!" << endl;

        bank = bank - unit ; 

        bank = bank + blackjack(casino,count,unit , 0); // overloader blackjack function call

        cout << "you have " << bank << endl;

        cout << "Please enter a 0 to keep playing or a 1 to quit " << endl;
        cin >> flag;
    }
    }
}
