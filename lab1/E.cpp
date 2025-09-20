#include <iostream>
#include <deque>
#include <vector>
using namespace std;

bool candidate_win(int cand,int opponent){
    return (cand == 0 && opponent == 9) || ((cand > opponent) && !(cand == 9 && opponent == 0));
}

void log_decks(const std::deque<int>& boris_deck, const std::deque<int>& nursik_deck, int turn){
    std::cout << "Turn #" << turn << "\n";
    std::cout << "Boris deck: ";
    for(auto el : boris_deck){
        std::cout << el << " ";
    }
    std::cout << "\nNursik deck: ";
    for(auto el : nursik_deck){
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main() {
    std::deque<int> boris_deck, nursik_deck;
    int el;
    for(int i = 0; i < 5; i++){
        cin >> el;
        boris_deck.push_back(el);
    }

    for(int i = 0; i < 5; i++){
        cin >> el;
        nursik_deck.push_back(el);
    }

    for(int turn = 1; turn < 10^6; turn++){
        int boris_card = boris_deck.front();
        boris_deck.pop_front();
        int nursik_card = nursik_deck.front();
        nursik_deck.pop_front();
        std::deque<int> *winners_deck = ((candidate_win(boris_card, nursik_card)) ? &boris_deck : &nursik_deck);
        winners_deck->push_back(boris_card);
        winners_deck->push_back(nursik_card);

        if (nursik_deck.empty() || boris_deck.empty()){
            std::cout << (nursik_deck.empty() ? "Boris " : "Nursik ") << turn << std::endl;
            return 0;
        }
    }
    std::cout << "blin nichya" << std::endl;
    return 0;   
}