/*	Gamma - Generic processing library
	See COPYRIGHT file for authors and license information
	
	Tutorial:		Generator / Oscillator / Sweep
	Description:	Sweeping through a table to create a sine wave
*/

#include "tutorial.h"

const int N=2048;
float table[N];				// Table to store sine wave
Sweep<> sweep(440);			// Linearly sweeping phase

void audioCB(AudioIOData& io){

	for(uint32_t i=0; i<io.framesPerBuffer(); i++){
	
		float s = sweep();		
		s = table[int(s*N)];

		io.out(0)[i] = io.out(1)[i] = s*0.2;
	}
}

int main(int argc, char* argv[]){

	// Fill sine table
	for(int i=0; i<N; ++i){
		table[i] = sin(float(i)/N*M_2PI);
	}

	AudioIO io(256, 44100., audioCB, NULL, 2);
	Sync::master().spu(io.framesPerSecond());
	io.start();
	printf("\nPress 'enter' to quit...\n"); getchar();
	return 0;
}