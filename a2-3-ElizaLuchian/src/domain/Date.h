//
// Created by 40745 on 16/03/2024.
//

#ifndef A2_3_ELIZALUCHIAN_DATE_H
#define A2_3_ELIZALUCHIAN_DATE_H

/*
 * Struct that stores the expiration date.
 * */

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date CreateDate(int day, int month, int year);
int IsGreaterDate(Date d1, Date d2);

#endif //A2_3_ELIZALUCHIAN_DATE_H
