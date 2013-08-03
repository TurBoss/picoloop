using namespace std;

#include <string>
#include "PatternElement.h"
#include "Pattern.h"


Pattern::Pattern() : pevector(16,PatternElement())
{

}

PatternElement & Pattern::getPatternElement(int patternElementNumber)
{
  return pevector[patternElementNumber];
}

void Pattern::setPatternSize(int patternSize)
{
  size=patternSize;
}

void Pattern::setLeftVolume(int left)
{
  leftVolume=left;
}

void Pattern::setRightVolume(int right)
{
  rightVolume=right;
}


int Pattern::getLeftVolume()
{
  return leftVolume;
}

int Pattern::getRightVolume()
{
  return rightVolume;
}


void Pattern::print()
{
  for ( int i=0; i<pevector.size(); i++)
    {
      string s;
      PatternElement PE;
      PE=pevector[i];
      s=PE.getStr();
      cout << i << ":" << s << "\n";
    }
}
