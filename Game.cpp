#include <iostream>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string arr[11][5]={
    {"What is the capital of India ?","New Delhi","Mumbai","Punjab","Karnataka"},
{"Who is the prime minister of India ?","Narendra Damodar Das Modi","Rahul Gandhi","Nirmala Sitaraman","Yogi Adityanath"},
{"Which planet is known as the red planet ?","Mars","Venus","Jupiter","Mercury"},
{"How many continents are there in the world ?","7","5","6","8"},
{"Who wrote the national anthem of india ?","Rabindranath Tagore","Mahatma Gandhi","Bankim Chandra Chattopadhyay","Sarojini Naidu"},
{"Which is the largest ocean in the world ?","Pacific Ocean","Atlantic Ocean","Indian Ocean","Arctic Ocean"},
{"What is the chemical symbol for gold ?","Au","Ag","Fe","Cu"},
{"Which animal is known as the king of jungle ?","Lion","Tiger","Elephant","Leopard"},
{"How many sides does a hexagon have ?","6","7","9","5"},
{"Which is the largest planet in our solar system?","Jupiter","Saturn","Earth","Neptune"},
{"Which country is famous for Eiffel Tower ?","France","Italy","Spain","Germany"}
};
int indexs[11]={0,1,2,3,4,5,6,7,8,9,10};
int optionss[4]={1,2,3,4};
random_device rd;
mt19937 gen(rd());

int Menu ()
{
    int choicee;
    cout<<"==================================\n";
    cout<<"            QUIZ GAME \n";
    cout<<"==================================\n\n";
    cout<<"1----->  Play Game \n";
    cout<<"2----->  Instructions \n";
    cout<<"3----->  Exit \n\n";
    cout<<"Enter Your Choice : ";
    cin>>choicee; 
    return choicee;
}
int Game()
{
    int ans,currentscore;
    shuffle(indexs, indexs + 11 ,gen);
    currentscore=0;
    for (int i = 0; i < 10; i++)
    {
        cout<<"Question no."<<i+1<<" : "<<arr[indexs[i]][0]<<endl;
        cout<<"\n";
        shuffle(optionss,optionss+4,gen);
        cout<<"1. "<<arr[indexs[i]][optionss[0]]<<endl;
        cout<<"2. "<<arr[indexs[i]][optionss[1]]<<endl;
        cout<<"3. "<<arr[indexs[i]][optionss[2]]<<endl;
        cout<<"4. "<<arr[indexs[i]][optionss[3]]<<endl;
        cout<<"\nEnter Your Answer(1/2/3/4) : ";
        cin>>ans;
        if (arr[indexs[i]][optionss[ans-1]] == arr[indexs[i]][1])
        {
            cout<<"Correct Answer! \n";
            currentscore=currentscore+1;
        }else
        {
            cout<<"Wrong Answer! \n";
        }
    }
    return currentscore;
}


int main()
{   
    int choicee,play,ans,highscore,currentscore,click;
    play=1;
    highscore=0;

        while(play==1)
        {
            
            choicee = Menu();
            switch (choicee)
            {
                case 1:
                    currentscore = Game();
                    if (currentscore>highscore)
                    {
                        highscore=currentscore;
                    }
                    cout<<"\n--->Score Board<---\n\n";
                    cout<<"High Score : "<<highscore<<endl;
                    cout<<"Your Score : "<<currentscore<<endl;
                    cout<<"Click 1 to proceed : ";
                    cin>>click;
                    switch(click)
                    {
                        case 1:
                            cout<<"\n\nWant to play again ? \n";
                            cout<<"1------> Yes \n";
                            cout<<"2------> No \n\n";
                            cout<<"Enter Your Choice : ";
                            cin>>play;
                            break;
                        default:
                            cout<<"Invalid inpiut!!\n";
                            break;
                    }
                    break;
                
                case 2:
                    cout<<"\n Instructions regarding the quiz game.\n";
                    cout<<"1. 10 questions will be given.\n";
                    cout<<"2. 4 options will be provided for each question.\n";
                    cout<<"3. One of the options will be correct.\n";
                    cout<<"4. Each correct option will reward one point.\n";
                    cout<<"5. No points for choosing wrong option.\n";
                    cout<<"6. No negative points will be given.\n";
                    cout<<"7. Score will be tracked throughout the game.\n";
                    cout<<"8. High score will be saved during the session. \n";
                    cout<<"9. Questions are shuffled and will appear in random order. \n";
                    cout<<"10. Beating the high score will save your score during the session. \n";
                    break;

                case 3:
                    cout<<"Thanks For Playing!\n";
                    return 0;
        
                default:
                    cout<<"Invalid choice!\n";
                    cout<<"Please enter a valid option!\n";
                    break;
            }
        }
        cout<<"Thanks For Playing!\n";
    /*random_device rd;
    mt19937 g(rd());
    Shuffle(indexs, indexs + 11 ,g);*/

    return 0;
}