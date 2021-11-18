/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessLib.c
 * Author: SalihaSAGOL
 *
 * Created on 7 Aralık 2020 Pazartesi, 10:14
 */


#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"

int counter = 0;

void hareketYazdir(struct poz ilkPozisyon, char tas) {

    int i, j;
    int** board = (int **) calloc(8, sizeof (int*)); //satranc tahtasi 
    int yer = tasaGoreFonksiyonIndex(tas);

    struct poz * (*satrancFonksiyonlari[6]) (struct poz ilkPoz);
    satrancFonksiyonlari[0] = hareketSah;
    satrancFonksiyonlari[1] = hareketVezir;
    satrancFonksiyonlari[2] = hareketFil;
    satrancFonksiyonlari[3] = hareketAt;
    satrancFonksiyonlari[4] = hareketKale;
    satrancFonksiyonlari[5] = hareketPiyon;

    struct poz* sonuclar = (*satrancFonksiyonlari[yer]) (ilkPozisyon);


    for (i = 0; i < 8; i++) {
        board[i] = (int *) calloc(8, sizeof (int));
    }

    //board 0 
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }

    for (i = 0; i < counter; i++) {
        board[sonuclar[i].yatay][harfeGorePozisyon(sonuclar[i].dusey)] = 1;
    }

    board[ilkPozisyon.yatay - 1][harfeGorePozisyon(ilkPozisyon.dusey)] = 2;

    //board yazdirilir
    for (i = 7; i >= 0; i--) {
        for (j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    counter = 0;
}

struct poz *hareketSah(struct poz ilkPoz) {

    struct poz* sonucSah = (struct poz*) malloc(8 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);


    //yatay 
    if (yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = ilkPoz.dusey;
        sonucSah[counter++] = sonuc;
    }

    if (yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = ilkPoz.dusey;
        sonucSah[counter++] = sonuc;
    }

    //dusey hareket
    if (dusey + 1 != 8) {
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucSah[counter++] = sonuc;
    }

    if (dusey - 1 != -1) {
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucSah[counter++] = sonuc;
    }

    //capraz
    if (dusey - 1 != -1 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucSah[counter++] = sonuc;
    }

    if (dusey - 1 != -1 && yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucSah[counter++] = sonuc;
    }

    if (dusey + 1 != 8 && yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucSah[counter++] = sonuc;
    }

    if (dusey + 1 != 8 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucSah[counter++] = sonuc;
    }

    return sonucSah;
}

struct poz *hareketVezir(struct poz ilkPoz) {

    struct poz* sonucVezir = (struct poz*) malloc(64 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);


    //yatay 
    while (yatay + 1 != 8) {
        yatay++;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (yatay - 1 != -1) {
        yatay--;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    //dusey 
    while (dusey + 1 != 8) {
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (dusey - 1 != -1) {
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    //capraz 
    while (yatay + 1 != 8 && dusey - 1 != -1) {
        yatay++;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (yatay - 1 != -1 && dusey - 1 != -1) {
        yatay--;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (yatay - 1 != -1 && dusey + 1 != 8) {
        yatay--;
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (yatay + 1 != 8 && dusey + 1 != 8) {
        yatay++;
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucVezir[counter++] = sonuc;
    }

    return sonucVezir;
}

struct poz *hareketFil(struct poz ilkPoz) {

    struct poz* sonucFil = (struct poz*) malloc(16 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);

    //capraz
    while (dusey - 1 != -1 && yatay + 1 != 8) {
        yatay++;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucFil[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (dusey - 1 != -1 && yatay - 1 != -1) {
        yatay--;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucFil[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (dusey + 1 != 8 && yatay - 1 != -1) {
        yatay--;
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucFil[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (dusey + 1 != 8 && yatay + 1 != 8) {
        yatay++;
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucFil[counter++] = sonuc;
    }
    return sonucFil;
}

struct poz *hareketAt(struct poz ilkPoz) {

    struct poz* sonucAt = (struct poz*) malloc(8 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);


    if (yatay + 2 < 8 && dusey - 1 != -1) {
        sonuc.yatay = yatay + 2;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucAt[counter++] = sonuc;
    }

    if (yatay - 2 > -1 && dusey - 1 != -1) {
        sonuc.yatay = yatay - 2;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucAt[counter++] = sonuc;
    }

    if (yatay - 2 > -1 && dusey + 1 != 8) {
        sonuc.yatay = yatay - 2;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucAt[counter++] = sonuc;
    }

    if (yatay + 2 < 8 && dusey + 1 != 8) {
        sonuc.yatay = yatay + 2;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucAt[counter++] = sonuc;
    }

    if (yatay + 1 != 8 && dusey - 2 > -1) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 2);
        sonucAt[counter++] = sonuc;
    }

    if (yatay - 1 != -1 && dusey - 2 > -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 2);
        sonucAt[counter++] = sonuc;
    }

    if (yatay - 1 != -1 && dusey + 2 < 8) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 2);
        sonucAt[counter++] = sonuc;
    }

    if (yatay + 1 != 8 && dusey + 2 < 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 2);
        sonucAt[counter++] = sonuc;
    }

    return sonucAt;
}

struct poz *hareketKale(struct poz ilkPoz) {

    struct poz* sonucKale = (struct poz*) malloc(64 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);

    //yatay
    while (yatay + 1 != 8) {
        yatay++;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        sonucKale[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (yatay - 1 != -1) {
        yatay--;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        sonucKale[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    //dusey
    while (dusey + 1 != 8) {
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucKale[counter++] = sonuc;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfeGorePozisyon(ilkPoz.dusey);

    while (dusey - 1 != -1) {
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = pozisyonaGoreHarf(dusey);
        sonucKale[counter++] = sonuc;
    }

    return sonucKale;
}

struct poz *hareketPiyon(struct poz ilkPoz) {

    struct poz* sonucPiyon = (struct poz*) malloc(2 * sizeof (struct poz));
    struct poz sonuc;

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfeGorePozisyon(ilkPoz.dusey);

    if (yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = ilkPoz.dusey;
        sonucPiyon[counter++] = sonuc;
        
    } else if (dusey + 1 != 8 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey + 1);
        sonucPiyon[counter++] = sonuc;
        
    } else if (dusey - 1 != -1 && yatay + 1 != -1) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = pozisyonaGoreHarf(dusey - 1);
        sonucPiyon[counter++] = sonuc;
    }

    return sonucPiyon;
}

int tasaGoreFonksiyonIndex(char tas) {

    if (tas == 'S') {
        return 0;
    } else if (tas == 'V') {
        return 1;
    } else if (tas == 'F') {
        return 2;
    } else if (tas == 'A') {
        return 3;
    } else if (tas == 'K') {
        return 4;
    } else if (tas == 'P') {
        return 5;
    } else {
        return 6;
    }
}

char pozisyonaGoreHarf(int pozisyon) {

    switch (pozisyon) {
        case 0:
            return 'A';
            break;
        case 1:
            return 'B';
            break;
        case 2:
            return 'C';
            break;
        case 3:
            return 'D';
            break;
        case 4:
            return 'E';
            break;
        case 5:
            return 'F';
            break;
        case 6:
            return 'G';
            break;
        case 7:
            return 'H';
            break;
    }
}

int harfeGorePozisyon(char dusey) {

    switch (dusey) {
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
    }
}


