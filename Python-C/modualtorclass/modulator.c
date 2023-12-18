#include <stdio.h>

struct NavicL5sModulator {
    double sampleRate;
    double codePhase;
    double prnstart;
    double cstart;
    int m1;
    int n;
    int m2;
    double subCarrPhase1;
    double subCarrPhase2;
};

void initNavicL5sModulator(struct NavicL5sModulator *modulator, double fs) {
    modulator->sampleRate = fs;
    modulator->codePhase = 0;
    modulator->prnstart = 0;
    modulator->cstart = 0;
    modulator->m1 = 1;
    modulator->n = 1;
    modulator->m2 = 6;

    // BOC(m,n) Init
    double fsc1 = modulator->m1 * 1.023e6;
    double epsilon1 = fsc1 * 1 / (100 * modulator->sampleRate);
    modulator->subCarrPhase1 = epsilon1;

    double fsc2 = modulator->m2 * 1.023e6;
    double epsilon2 = fsc2 * 1 / (100 * modulator->sampleRate);
    modulator->subCarrPhase2 = epsilon2;
}

int main() {
    struct NavicL5sModulator modulator;
    double fs = 1000000.0; // Sample rate (1 MHz) - you can change this value as needed

    initNavicL5sModulator(&modulator, fs);

    // Printing initialized values
    printf("Sample Rate: %f\n", modulator.sampleRate);
    printf("Code Phase: %f\n", modulator.codePhase);
    printf("PRN Start: %f\n", modulator.prnstart);
    printf("C Start: %f\n", modulator.cstart);
    printf("M1: %d\n", modulator.m1);
    printf("N: %d\n", modulator.n);
    printf("M2: %d\n", modulator.m2);
    printf("Subcarrier Phase 1: %f\n", modulator.subCarrPhase1);
    printf("Subcarrier Phase 2: %f\n", modulator.subCarrPhase2);

    return 0;
}

