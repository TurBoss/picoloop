using namespace std;

#include <vector>
#include "WaveTable.h"

#ifndef __WAVETABLEMANAGER__
#define __WAVETABLEMANAGER__

class WaveTableManager 
{
private:

  //Constructor Destructor
  WaveTableManager();
  ~WaveTableManager();

  //WaveTableManager & operator= (const WaveTableManager&) {}
  //WaveTableManager(const WaveTableManager&)              {}

  vector<WaveTable*> wtvector;  

  int    size;


public:
  static WaveTableManager& getInstance();



  //void addWaveTable(WaveTable * WT);


  int         getSize();
  void        insert(WaveTable * WT,int position);
  WaveTable * get(int position);


};
#endif