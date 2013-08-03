#include "FuzzyPulseOscillator.h"

using namespace std;


FuzzyPulseOscillator::FuzzyPulseOscillator()
{
  frequency=440;
  amplitude=127;
  sample_num=0;
  old_phase=0;
  new_phase=0;
}

FuzzyPulseOscillator::~FuzzyPulseOscillator()
{

}



Sint16 FuzzyPulseOscillator::tick()
{
  float  f;
  Uint16 u;
  Sint16 s;
  int debug=1;
  int detect_phase=0;
  int period=0;

  // // // // 1/freq*44100 = > pas de + - + - 
  
  if (sample_num==0) srand(frequency);
  sample_num++;

  if (debug) printf("Sint16 NoiseOscillator::tick()\n");

  s=rand();
  if (s<0) s=s*-1;
  
  printf("s:%d\n",s);

  //detect_phase=sample_num % ( frequency*2);
  
  period=(44100/frequency);

  if (debug) 
    printf("period:%d samplenum:%d sample_num mod period: %d \n",
	   period,
	   sample_num,
	   sample_num%period);
  
  if ((sample_num % ( 2* period) ) > period)
    {  new_phase=-1; }
  else
    {  new_phase=1;  }


  if (old_phase != new_phase) 
    srand(frequency);

  if (debug) 
    printf("s:%d phase:%d\n",s,new_phase);

  
  s=s*new_phase;
  
  // Amplification -32000 32000
  //s=(s*((amplitude/64)*new_phase));
  //f=(float)(s*((amplitude/256)*new_phase));
  //f=float(amplitude)/float(512);
  f=f*s*new_phase;
  //s=f;

  if (debug) printf("%d\n",s);
  last_tick=s;
  old_phase=new_phase;
  return s;
}
