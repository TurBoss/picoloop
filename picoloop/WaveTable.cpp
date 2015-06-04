#include "WaveTable.h"
using namespace std;

WaveTable::WaveTable() 
{
  size=0;
  buffer=0;
  name=0;
}

WaveTable::~WaveTable()
{
  if (buffer!=0)
    {
      free(buffer);
      buffer=0;
    }  
}


int WaveTable::allocMemory()
{
  if (size>0)
    {
      buffer=(Sint16*)malloc(sizeof(Sint16)*size);
      if (buffer==0)
	{
	  printf("Error allocating memory\n");
	  exit(1);
	  //return 0;
	}
      else
	{
	  printf("WaveTable::allocMemory(), buffer:0x%08.8X\n",buffer);
	}
    }
  return size;
}

int WaveTable::freeMemory()
{
  if (buffer!=0)
    {
      free(buffer);
      buffer=NULL;
    }
}

int WaveTable::setSize(int bufferSize)
{
  if (size==bufferSize)
    return 0;

  
  if (bufferSize>=0)
    size=bufferSize;
  
  if (buffer!=0)
    {
      printf("WARNING: Erasing previous memory\n");
      this->freeMemory();

    }
  return this->allocMemory();
}

Sint16 * WaveTable::getBuffer()
{
  printf("WaveTable::getBuffer(), buffer:0x%08.8X\n",buffer);
  return buffer;
}


