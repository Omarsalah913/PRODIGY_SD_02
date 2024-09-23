#include <iostream>
#include <ctime>
#include <string>

class Guess_game{
    private:
    int Generated_number;
    int Attempts;
    int Difference;
    int Gap;
    int Range;

    public:
    //Default Constructor
    Guess_game(){
        Generated_number = 0;
        Attempts = 0;
    }

    void SetRange(int lowest, int highest){
        Range = highest - lowest + 1;
        Generated_number = lowest + (rand() % Range);
        Gap = highest / 10;    
    }

    void Start_Guess(void){
        int user_guess = 0;
        do{
            std::scanf("%d",&user_guess);
            Difference = user_guess - Generated_number;
            Attempts++;
            if(Difference >= Gap){
                std::cout<<"Your guess is too high!"<<std::endl;                  
            }

            if(Difference <= -Gap){
                std::cout<<"Your guess is too low!"<<std::endl;                  
            }
            if(Difference > 0 && Difference < Gap){
                std::cout<<"Your guess is high but you're getting closer!"<<std::endl;                  
            }

            if(Difference < 0 && Difference > -Gap){
                std::cout<<"Your guess is low but you're getting closer!"<<std::endl;                  
            }
            if(Difference != 0){
                std::cout<<"Guess again!"<<std::endl;
            }
            
        }while(Generated_number != user_guess);
       
        std::cout<<"Your guess was right!"<<std::endl;
        std::cout<<"You took "<<Attempts<<" attempt/s to guess it right!"<<std::endl;        
    }
};


int main(){
    srand(time(0));
    std::string Range;
    int lowest = 0;
    int highest = 0;

    Guess_game G1;

    std::cout<<"Welcome to the Guessing Game!"<<std::endl;

    std::cout<<"Define the range for guessing by writing the lowest number then a dash then the highest number."<<std::endl;
    std::cout<<"Ex: 1-100"<<std::endl;
    std::getline(std::cin,Range);
    std::sscanf(Range.c_str(), "%d-%d", &lowest, &highest);
    G1.SetRange(lowest,highest);
    std::cout<<"The range you specified is "<<Range<<std::endl; 
    std::cout<<"Now guess a number!"<<std::endl;
    G1.Start_Guess();
    

    return 0;
}

