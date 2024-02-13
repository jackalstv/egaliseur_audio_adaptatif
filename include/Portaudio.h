//
// Created by User on 2/13/2024.
//

#ifndef EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
#define EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H

#include <stdio.h>
#include <portaudio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

#define START_FREQ 5.0
#define END_FREQ 20000.0
#define DURATION 20.0
#define SAMPLING_RATE 44100.0

float x[(int)END_FREQ- (int)START_FREQ + 1];
int y=0;

void generateSignal(double *signal, int numSamples);

int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData);

#endif //EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
