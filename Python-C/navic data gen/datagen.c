#include <stdio.h>
#include <stdlib.h>

struct NavicDataGen {
    int dataRate;
    int sampleRate;
    int numSymbolsPerFrame;
    int numSamplesPerBit;
    int samplesToNextBit;
    int bitcnt;
    float* symbolStream;
};

void initNavicDataGen(struct NavicDataGen* generator, int ds, int fs) {
    generator->dataRate = ds;
    generator->sampleRate = fs;
    generator->numSymbolsPerFrame = 1800;
    generator->numSamplesPerBit = (int)(fs / ds);
    generator->samplesToNextBit = generator->numSamplesPerBit;
    generator->bitcnt = 0;

    // Allocate memory for symbolStream based on numSymbolsPerFrame
    generator->symbolStream = (float*)malloc(generator->numSymbolsPerFrame * sizeof(float));
    
    // Initialize symbolStream to 0
    for (int i = 0; i < generator->numSymbolsPerFrame; ++i) {
        generator->symbolStream[i] = 0.0;
    }
}

void cleanupNavicDataGen(struct NavicDataGen* generator) {
    // Free dynamically allocated memory here
    free(generator->symbolStream);
}
void SymbolsGen(struct NavicDataGen* generator) {
    // Generate symbols and print them
    for (int i = 0; i < generator->numSymbolsPerFrame; ++i) {
        generator->symbolStream[i] = (float)(rand() % 2); // Generate random 0 or 1 for demonstration
        printf("%d ", (int)generator->symbolStream[i]); // Print the generated symbol as an integer (0 or 1)
    }
    printf("\n"); // Print a newline after generating symbols for one frame
}


void GenerateBits(struct NavicDataGen* generator, float timeInterval) {
    // Calculate the number of bits to generate based on the time interval
    int numBitsToGen = (int)(generator->sampleRate * timeInterval);
    int currentIndex = 0;
    float* genStream = (float*)malloc(numBitsToGen * sizeof(float));

    int bufferCnt = numBitsToGen;
    while (bufferCnt > 0) {
        int numSamples = (bufferCnt < generator->samplesToNextBit) ? bufferCnt : generator->samplesToNextBit;

        // Generate symbols using SymbolsGen method
        SymbolsGen(generator);

        // Copy generated symbols to genStream
        for (int i = 0; i < numSamples; ++i) {
            genStream[currentIndex++] = generator->symbolStream[generator->bitcnt % generator->numSymbolsPerFrame];
            generator->bitcnt++;
            if (generator->bitcnt % generator->numSymbolsPerFrame == 0) {
            
            printf("%f ", generator->symbolStream[i]); // Print the generated symbol
   		 }
   		 printf("\n");
                // Generate new symbols for the next frame if the current frame ended
                SymbolsGen(generator);
            }
        

        // Update remaining samples and samplesToNextBit
        bufferCnt -= numSamples;
        generator->samplesToNextBit -= numSamples;
        if (generator->samplesToNextBit <= 0) {
            generator->samplesToNextBit = generator->numSamplesPerBit;
        }
    }

    // Use genStream for further processing if needed

    free(genStream); // Free memory allocated for genStream
}

int main() {
    struct NavicDataGen generator;
    int dataRate = 100; // Set your desired data rate
    int sampleRate = 1000; // Set your desired sample rate
    float timeInterval = 1.0; // Set your desired time interval for bit generation
    
    initNavicDataGen(&generator, dataRate, sampleRate);
    GenerateBits(&generator, timeInterval);
    cleanupNavicDataGen(&generator);

    return 0;
}


