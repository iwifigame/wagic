#ifndef _DECK_MANAGER_H
#define _DECK_MANAGER_H

#include <string>
#include <vector>

#include "DeckMetaData.h"

using namespace std;

class DeckManager
{
private:
    vector<DeckMetaData*> playerDeckOrderList;
    vector<DeckMetaData*> aiDeckOrderList;
    map<string, StatsWrapper*> playerDeckStatsMap;
    map<string, StatsWrapper*> aiDeckStatsMap;

    static DeckManager *mInstance;

public:
    DeckManager()
    {
        //private constructor
    }

    void updateMetaDataList(vector<DeckMetaData*>* refList, bool isAI);
    vector<DeckMetaData*> * getPlayerDeckOrderList();
    vector<DeckMetaData*> * getAIDeckOrderList();

    void AddMetaData( const std::string& filename, bool isAI);
    void DeleteMetaData( const std::string& filename, bool isAI);
    DeckMetaData* getDeckMetaDataById(int deckId, bool isAI);
    DeckMetaData* getDeckMetaDataByFilename(const std::string& filename, bool isAI);
    StatsWrapper* getExtendedStatsForDeckId(int deckId, MTGAllCards* collection, bool isAI);
    StatsWrapper* getExtendedDeckStats(DeckMetaData* selectedDeck, MTGAllCards* collection, bool isAI);

    static DeckManager* GetInstance();
    static void EndInstance();

    //convenience method to get the difficulty rating between two decks.  This should be refined a little more
    //since the eventual move of all deck meta data should be managed by this class

    int getDifficultyRating(Player *statsPlayer, Player *player);
    
    ~DeckManager();

};

#endif //_DECK_MANAGER_H
