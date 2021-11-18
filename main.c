/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: SalihaSAGOL
 *
 * Created on 7 Aralık 2020 Pazartesi, 10:14
 */

#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"

/*
 * 
 */
int main(void) {
    struct poz p;
    p.dusey = 'F';
    p.yatay = 5;


    printf("<<<Sah tasi hareketi>>>\n"); //sah hareket
    hareketYazdir(p, 'S');
    
    printf("<<<Vezir tasi hareketi>>>\n"); //vezir hareket
    hareketYazdir(p, 'V');
    
    printf("<<<Fil tasi hareketi>>>\n"); //fil hareket
    hareketYazdir(p, 'F');
    
    printf("<<<At tasi hareketi>>>\n"); //at hareket
    hareketYazdir(p, 'A');
    
    printf("<<<Kale tasi hareketi>>>\n"); //kale hareket
    hareketYazdir(p, 'K');
    
    printf("<<<Piyon tasi hareketi>>>\n"); //piyon hareket
    hareketYazdir(p, 'P');


}
