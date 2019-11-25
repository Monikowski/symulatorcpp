#pragma once
#include "Czlowiek.h"

#include "Zwierze.h"

#include "Roslina.h"

#include "Swiat.h"

#include "Organizm.h"

#include "Wilk.h"
#include "Lis.h"
#include "Czlowiek.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Owca.h"

#include "conio2.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Jagody.h"
#include "Guar.h"
#include "Barszcz.h"

#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>


#define INIC_CZL 4 // inicjatywa kazdego organizmu
#define INIC_WIL 5
#define INIC_OWC 4
#define INIC_LIS 7
#define INIC_ZOL 1
#define INIC_ANT 4

#define INIC_ROS 0

#define INIC_TRA 0
#define INIC_MLE 0
#define INIC_GUA 0
#define INIC_JAG 0
#define INIC_BAR 0

#define ID_CZL 0 // id kazdego organizmu
#define ID_WIL 1
#define ID_OWC 2
#define ID_LIS 3
#define ID_ZOL 4
#define ID_ANT 5

#define ID_TRA 7
#define ID_MLE 8
#define ID_GUA 9
#define ID_JAG 10
#define ID_BAR 11

#define GEST_WIL 0.035 // gestosc wystepowania kazdego organizmu 
#define GEST_OWC 0.08
#define GEST_LIS 0.04
#define GEST_ZOL 0.03
#define GEST_ANT 0.07

#define GEST_TRA 0.07
#define GEST_MLE 0.04
#define GEST_GUA 0.06
#define GEST_JAG 0.017
#define GEST_BAR 0.01

#define SYMB_CZL '@' // symbol kazdego organizmu
#define SYMB_WIL 'W'
#define SYMB_OWC 'O'
#define SYMB_LIS 'L'
#define SYMB_ZOL 'Z'
#define SYMB_ANT 'A'

#define SYMB_TRA '#'
#define SYMB_MLE '^'
#define SYMB_GUA '+'
#define SYMB_JAG '$'
#define SYMB_BAR '%'

#define SILA_CZL 5 // sila startowa kazdego organizmu
#define SILA_WIL 9
#define SILA_OWC 4
#define SILA_LIS 3
#define SILA_ZOL 2
#define SILA_ANT 4

#define SILA_TRA 0
#define SILA_MLE 0
#define SILA_GUA 0
#define SILA_JAG 99
#define SILA_BAR 10

#define CD_CZL 0 // cooldowny (na rozmnazanie)
#define CD_WIL 4
#define CD_OWC 3
#define CD_LIS 4
#define CD_ZOL 2
#define CD_ANT 4

#define CD_ROS 0

#define CD_TRA 0
#define CD_MLE 0
#define CD_GUA 0
#define CD_JAG 0
#define CD_BAR 0

#define ROZ_TRA 20 // szansy na rozrost w %
#define ROZ_MLE 15
#define ROZ_GUA 17
#define ROZ_JAG 12
#define ROZ_BAR 10

using namespace std;
