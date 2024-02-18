//
// Created by User on 2/13/2024.
//
#include "../include/Portaudio.h"

float x[(int)END_FREQ- (int)START_FREQ + 1];


// Fonction de rappel (callback) pour PortAudio
int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    double *signal = (double *)userData;
    float *out = (float *)outputBuffer;

    static unsigned long frameIndex = 0;

    // Calculer la fréquence actuelle
    double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * frameIndex / (SAMPLING_RATE * DURATION);
    //printf("Frequency: %.2f Hz\n", currentFreq);

    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));
        printf("%lu\n", i);
        x[i]=i;
        isPress[i]=0;
    }

    frameIndex += framesPerBuffer;

    return paContinue;
}
