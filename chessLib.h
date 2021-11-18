/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessLib.h
 * Author: SalihaSAGOL
 *
 * Created on 7 Aralık 2020 Pazartesi, 10:15
 */


#define CHESSLIB_H


struct poz {
    short yatay; 
    char dusey; 
};

struct poz *hareketSah(struct poz ilkPoz);
struct poz *hareketVezir(struct poz ilkPoz);
struct poz *hareketFil(struct poz ilkPoz);
struct poz *hareketAt(struct poz ilkPoz);
struct poz *hareketKale(struct poz ilkPoz);
struct poz *hareketPiyon(struct poz ilkPoz);

void hareketYazdir(struct poz ilkPozisyon, char tas);

int harfeGorePozisyon(char dusey);
char pozisyonaGoreHarf(int pozisyon);
int tasaGoreFonksiyonIndex(char tas);

